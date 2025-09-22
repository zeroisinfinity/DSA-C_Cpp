#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int dxd[5] = { 3 , 2 , 4 , 2 , 5 };
int lhs = 1;
int rhs = 4;
int soln[5][5];
int k[5][5];
int trav = 0;
int min_cost(int lhs , int rhs){//b1
	

	if(lhs==rhs){//b9
		return 0;
	}//b9
	
	soln[lhs][rhs] = INT_MAX;
	int cost = 0;
	for(int cut = lhs ; cut < rhs ; ++cut){//b3
		 soln[lhs][cut] = min_cost(lhs,cut);
		 soln[cut+1][rhs] = min_cost(cut+1,rhs);
		 int cost = soln[lhs][cut] + soln[cut + 1][rhs] + (dxd[lhs-1] * dxd[cut] * dxd[rhs]); //IF YOU WANT COST OF SINGLE PAIR WITH LEAST COST THEN KEEP COST AS STATIC OR POINTER A SINGLE MEMORY ADDR 
		 if(cost < soln[lhs][rhs]){//b4
			soln[lhs][rhs] = cost;
			k[lhs][rhs] = cut;
		 }//b4 
	}//b3

	return soln[lhs][rhs];

}//b1
 


int main(){//b2
	
	printf("\nMIN cost is - %d",min_cost(lhs,rhs));

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
			printf("(%d) ",k[i][j]);
		}
		printf("\n");
	}


		
		//printf("\n(%d , %d)",soln[i],soln[i+1]);
//	printf("\nLOOK FOR LAST 2 LINES THATS THE ANSWER\n");
	return 0;
	}//b2
