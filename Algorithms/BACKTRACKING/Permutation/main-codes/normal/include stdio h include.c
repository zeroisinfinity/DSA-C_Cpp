#include <stdio.h>
#include <stdlib.h>

int main(){//b1
    
    int loc;
    printf("Enter no.of characters - ");
    scanf("%d",&loc);
    char* quen = (char*)calloc(loc + 1, sizeof(char));
    char* soln = (char*)calloc(loc + 1 , sizeof(char));
    char* flags = (char*)calloc(loc , sizeof(char));
    enter_data(loc,quen);
    return 0;
}//b1

void enter_data(int pos , char* charr){//b2

      for(int trav = 0 ; trav < pos ; trav++){//b3
          printf("Enter character INPUT-ARRAY[%d] - ");
          scanf("%c", charr[trav]);
          printf('\n');
      }//b3
      
      charr[pos] = '\0';
      
}//b2
