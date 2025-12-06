#include <stdio.h>
const int profit[5] = {0, 6,5,3,8};
const int weight[5] = {0, 1,2,1,2};
#define constraint 5
#define pwsize 5
int mem[pwsize][constraint+1];
int knap(int obj , int wght ){//b1
	
	if(!obj || !wght){//b2
		mem[obj][wght] = 0;
		return 0;
	}//b2
	if(mem[obj][wght] != -1) return mem[obj][wght];
	if(weight[obj] <= wght){//b3
		int neg = knap(obj - 1 , wght);
		int pov = knap(obj - 1 , wght - weight[obj]) + profit[obj];
		mem[obj][wght] = neg > pov ? neg : pov;
	}//b3
	else{//b6
		mem[obj][wght] = knap(obj - 1 , wght);
	}//b6
	return mem[obj][wght];
}//b1
 
int main(){//b4
	
	for (int i=0; i<pwsize ; i++)
		for (int j=0; j<constraint+1 ; j++)
       			 mem[i][j] = -1;

	printf("max profit is - %d",knap(pwsize-1,constraint));
	return 0;
}//b4

