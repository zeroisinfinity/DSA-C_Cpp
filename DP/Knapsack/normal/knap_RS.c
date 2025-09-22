#include <stdio.h>
const int profit[5] = {0, 3,5,6,8};
const int weight[5] = {0, 1,2,1,2};
const int constraint = 5;
const int pwsize = 5;

int knap(int obj , int wght ){//b1
	
	if(!obj || !wght){//b2
		return 0;
	}//b2
	
	if(weight[obj] <= wght){//b3
		int neg = knap(obj - 1 , wght);
		int pov = knap(obj - 1 , wght - weight[obj]) + profit[obj];
		return neg > pov ? neg : pov;
	}//b3
}//b1
 
int main(){//b4
	printf("max profit is - %d",knap(pwsize-1,constraint));
	return 0;
}//b4

