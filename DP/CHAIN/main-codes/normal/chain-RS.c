#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int dxd[5] = { 3 , 2 , 4 , 2 , 5 };
int lhs = 1;
int rhs = 4;
int soln[5] = {0};
int min_cost(int lhs , int rhs){//b1
	

	if(lhs==rhs) return 0;
	
	int upbound = INT_MAX;
	int cost = upbound;
	
	for(int cut = lhs ; cut < rhs ; ++cut){//b3
		 cost = min_cost(lhs , cut) + min_cost(cut + 1 , rhs) + (dxd[lhs-1] * dxd[cut] * dxd[rhs]); //IF YOU WANT COST OF SINGLE PAIR WITH LEAST COST THEN KEEP COST AS STATIC OR POINTER A SINGLE MEMORY ADDR 
		 if(cost < upbound){//b4
			upbound = cost;
			printf("\n(%d , %d) + (%d , %d)\n",lhs,cut,cut+1,rhs);
		//	soln[lhs-1] += 1;
		//	soln[cut] += 1;
		//	soln[rhs] += 1;
		 }//b4 
	}//b3

	return upbound;

}//b1
 


int main(){//b2
	
	printf("\nMIN cost is - %d",min_cost(lhs,rhs));

//	for(int i = 0 ; i < 5 ; ++i)
//		printf("\nsoln[%d] - %d",i,soln[i]);
	return 0;
}//b2
