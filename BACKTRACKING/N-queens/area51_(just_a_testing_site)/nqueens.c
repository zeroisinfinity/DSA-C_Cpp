#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

// i = trav in valid_move()
// j = *soln[trav] in valid_move()
// k = k_row
// l = l_col , *soln[trav] in place_queen()

bool valid_move(int k_row , int l_col , int* soln , int dxd , size_t* arr_len){//b5
    
    for( int trav = 0 ; trav < *arr_len ; trav++){//b6
          bool same_diagonals = (trav - k_row == abs(soln[trav] - l_col)) ;
          bool same_col = soln[trav] == l_col ;
          if( !same_diagonals && !same_col ){//b6
              continue;
          }//b6
          else{//b7
              return false;
          }//b7
    }//b6
    return true;
    
}//b5




void place_queen(int dxd, int k_row , int* soln , size_t* arr_len ){//b1
    
    for(int trav = 0 ; trav < dxd ; trav++){//b2
    
          if( valid_move(k_row , soln[trav] , soln , dxd , arr_len) && soln[0]!=0 ){//b3
                progs_bar(1 , soln , arr_len , dxd );
                soln[k_row] = trav;
                place_queen(dxd , k_row + 1 , soln , arr_len );
          }//b3

          else{//b4
              soln[0] = trav;
          }//b4
        
    }//b2
    

}//b1


void resize(int** arr, size_t* arr_len , int xve , int dxd){

      if ((*arr_len >= 0 && xve != 0) || !(*arr)) {
      
          if(xve == -1 && *arr_len <= dxd) (*arr_len)--;
          else if(*arr_len != dxd) (*arr_len)++;
          
          int *tmp = realloc(*arr,*arr_len * sizeof(int));
          exitOrNot(tmp);
          *arr = tmp;
          
          if(!arr_len){
              free(*arr);
              *arr = NULL;
          }
          
      else{
          free(*arr);
          *arr = NULL;
      }
      
     }
}
void exitOrNot(int* arg){//b10

    if(!arg){//b11  
        fprintf(stderr,"Memory allocation failed\n");
        exit(1);
    }//b11
    
}//b10

//int sgn(int x) { return (x > 0) - (x < 0); }

// number of elements in the array

void progs_bar(int xve , int* arr , size_t* arr_len , int dxd) { //b8 function scope
    
    switch (xve) { //b9 switch block
        
        case -1: { //b10 shrink array
            resize(arr , arr_len , xve , dxd);
            break;
        } //b10
        
        case 1: { //b11 grow array
            resize(arr , arr_len , xve , dxd);
            break;
        } //b11
        
        case 0: { //b12 free array    int n = 4;  // 4x4 board
            resize(arr , arr_len , xve , dxd);
            break;
        } //b12
        
        default: { //b13 error handling
            fprintf(stderr, "Enter valid numeric value\n");
            exit(1);
        } //b13
        
    } //b9
    
} //b8

void display(int* soln , int dxd){

    for(int col = 0 ; col < dxd ; col++)
        printf(" (%d,%d) " , col , soln[col]);
        
}

int main() {

    printf("Enter your chessboard dimension - ");
    int* dxd = (int*)calloc(1,sizeof(int));
    scanf("%d",dxd);
    int* soln = (int*)calloc(1,sizeof(int));
  
    /*
    arr = realloc(arr,*arr_len * sizeof(int));
   *arr_len is multiplied by sizeof(int) (a size_t).
    If*arr_len is an int, the multiplication promotes to size_t anyway.*/
    size_t* arr_len;
    int l = 0;
    arr_len = &l;
/*  But here’s the catch:
        If you stick with int*arr_len, you’re limited to ~2 billion elements on a 32-bit signed int system. That’s usually fine.
        If you use size_t*arr_len, it can represent the full addressable memory range (4 billion on 32-bit, way bigger on 64-bit).

    TL;DR
        For teaching / small programs → int*arr_len is fine.
        For robust, real-world code that could handle big arrays → size_t*arr_len is the standard practice.
*/
    place_queen( *dxd , 1 , &soln[0] , arr_len);
    //printChessboard(n, labels, 10, 5); // each square: width=10, height=5
    display(*soln , *dxd);
    return 0;
}


