#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int dxd[5] = { 3 , 2 , 4 , 2 , 5 };
int lhs = 1;
int rhs = 4;
int soln[8] = {0};
int trav = 0;
int min_cost(int lhs , int rhs){//b1
	

	if(lhs==rhs) return 0;
	
	int upbound = INT_MAX;
	int cost = upbound;
	
	for(int cut = lhs ; cut < rhs ; ++cut){//b3
		 cost = min_cost(lhs , cut) + min_cost(cut + 1 , rhs) + (dxd[lhs-1] * dxd[cut] * dxd[rhs]); //IF YOU WANT COST OF SINGLE PAIR WITH LEAST COST THEN KEEP COST AS STATIC OR POINTER A SINGLE MEMORY ADDR 
		 if(cost < upbound){//b4
			upbound = cost;
			if(lhs!=cut || cut+1!=rhs) printf("\n(%d , %d) + (%d , %d)\n",lhs,cut,cut+1,rhs);
		//	if(trav>=8) trav=0;
		//	soln[trav] = lhs;
		//	soln[trav+1] = cut;
		//	soln[trav+2] = cut+1;
		//	soln[trav+3] = rhs;
		//	trav+=4;
		 }//b4 
	}//b3

	return upbound;

}//b1
 


int main(){//b2
	
	printf("\nMIN cost is - %d",min_cost(lhs,rhs));

	//for(int i = 0 ; i < 8 ; i+=2)
		//printf("\n(%d , %d)",soln[i],soln[i+1]);
	printf("\nLOOK FOR LAST 2 LINES THATS THE ANSWER\n");
	return 0;
}//b2
