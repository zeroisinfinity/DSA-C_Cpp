#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

// i = trav in valid_move()
// j = soln[trav] in valid_move()
// k = k_row
// l = l_col , soln[trav] in place_queen()

void display(int* soln , int dxd){

    for(int col = 0 ; col < dxd ; col++)
        printf(" (%d,%d) " , col + 1 , soln[col]);
        
}

bool valid_move(int k_row , int l_col , int* soln){//b5
    
    for( int trav = 0 ; trav < k_row - 1 ; trav++){//b6
          bool same_diagonals = abs((trav + 1) - k_row) == abs(soln[trav] - l_col);
          bool same_col = (soln[trav] == l_col) ;
          if( same_diagonals || same_col ){//b6
              return false;
          }//b6
    }//b6

    return true;
    
}//b5




void place_queen(int dxd, int k_row , int* soln){//b1
    
    if(k_row > dxd){
        display(soln, dxd);
        printf("\n");
        return;
    }

    
    for(int trav = 0 ; trav < dxd ; trav++){//b2
    
          if( valid_move(k_row , trav + 1 , soln ) ){//b3
                soln[k_row-1] = trav + 1;
                place_queen(dxd , k_row + 1 , soln);
          }//b3

    }//b2
    

}//b1





int main() {

    printf("Enter your chessboard dimension - ");
    int dxd;
    scanf("%d",&dxd);
    int* soln = (int*)calloc(dxd,sizeof(int));
    
    if(soln==NULL) exit(1);
    
    place_queen( dxd , 1 , soln);
    //printChessboard(n, labels, 10, 5); // each square: width=10, height=5
    free(soln);
    return 0;
}


