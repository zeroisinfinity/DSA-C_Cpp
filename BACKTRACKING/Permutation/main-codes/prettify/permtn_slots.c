#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>




#define RESET   "\033[0m"
#define WHITE_BG "\033[47m\033[30m"  // white background, black text
#define BLACK_BG "\033[40m\033[37m"  // black background, white text



void pretty_print(const char *arr, int n) {
    if (!arr) return;

    for (int col = 0; col < n; col++) {
        if (col % 2 == 0) {
            printf(WHITE_BG" %c "RESET, arr[col]);
        } else {
            printf(BLACK_BG" %c "RESET, arr[col]);
        }
    }
    printf("\n");
}



void display(char* ans){//b8
    int dis = 0;
    
    if(!ans[dis]) exit(1);
    
    while(ans[dis]){//b9
        printf(" %c ",ans[dis]);
        dis++;
    }//b9
}//b8

void permtn(int slot , int cap , char* que , char* ans , bool* stat){//b4
      
      if(slot == cap){//b7
          ans[cap] = '\0';
          pretty_print(ans,cap);
          printf("\n");
      }//b7
      
      if(!que) exit(1);
      if(stat==NULL) exit(1);
      
      for(int iter = 0 ; iter < cap ; iter++){//b5
            if(!stat[iter]){//b6
                    ans[slot] = que[iter];
                    stat[iter] = true;
                    permtn(slot+1 , cap , que , ans , stat);
                    stat[iter] = false;
          }//b6
      }//b5
}//b4

void enter_data(int pos , char* charr){//b2

      if(!charr) exit(1);
      
      for(int trav = 0 ; trav < pos ; trav++){//b3
          printf("Enter character INPUT-ARRAY[%d] - ",trav);
          scanf(" %c", &charr[trav]);
          printf("\n");
      }//b3
      
      charr[pos] = '\0';
      
}//b2


int main(){//b1
    
    int loc;
    printf("Enter no.of characters - ");
    scanf(" %d",&loc);
    char* quen = (char*)calloc(loc + 1, sizeof(char));
    char* soln = (char*)calloc(loc + 1 , sizeof(char));
    bool* flags = (bool*)calloc(loc, sizeof(bool));
    if(!quen) exit(1);
    enter_data(loc,quen);
    permtn(0,loc,quen,soln,flags);
    free(quen);
    free(flags);
    free(soln);
    return 0;
}//b1


