#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int dxd[5] = { 3 , 2 , 4 , 2 , 5 };
int lhs = 1;
int rhs = 5;
int soln[5][5];
int mid[5][5];
int trav = 0;
int min_cost(int n){//b1
	
	for(int diff = 1 ; diff < n ; ++diff){//b15
		for(int i = 1 ; i < n - diff ; ++i){//b16
			int j = i + diff;
			soln[i][j] = INT_MAX;
			for(int k = i ; k < j ; ++k){//b17
				int cost = soln[i][k] + soln[k+1][j] + (dxd[i-1] * dxd[k] * dxd[j]);
				if(cost < soln[i][j]){//b18
					soln[i][j] = cost;
					mid[i][j] = k;
				}//b18
			}//b17
		}//b16
	}//b1
	return soln[1][n];
}//b1
 


int main(){//b2
	
	printf("\nMIN cost is - %d",min_cost(rhs));

	for(int i = 0 ; i < 4 ; ++i){
		for(int j = 0 ; j < 4 ; ++j){
			if(i!=j) soln[i][j] = -1;
			else soln[i][j] = 0;
		}
	}
	printf("\n");
	for(int i = 0 ; i < 5 ; ++i){
		for(int j = 0 ; j < 5 ; ++j){
			printf("(%d) ",soln[i][j]);
		}
		printf("\n");
	}

	printf("\n");
	for(int i = 0 ; i < 5 ; ++i){
		for(int j = 0 ; j < 5 ; ++j){
			printf("(%d) ",mid[i][j]);
		}
		printf("\n");
	}


		
		//printf("\n(%d , %d)",soln[i],soln[i+1]);
//	printf("\nLOOK FOR LAST 2 LINES THATS THE ANSWER\n");
	return 0;
	}//b2
