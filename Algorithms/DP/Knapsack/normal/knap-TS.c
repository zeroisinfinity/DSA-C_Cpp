#include <stdio.h>
const int profit[5] = {0, 6,5,3,8};
const int weight[5] = {0, 1,2,1,2};
#define constraint 5
#define pwsize 5
int mem[pwsize][constraint+1];

int max(int a , int b){//b8
	return a > b ? a : b;
}//b8

int knap(int obj , int wght ){//b1
	for(int i = 1 ; i < obj ; ++i)
		for(int j = 1 ; j <= wght; ++j)
			if(weight[i] <= j) mem[i][j] = max(mem[i-1][j] , mem[i - 1][j - weight[i]] + profit[i]);
			else mem[i][j] = mem[i - 1][j];
	return mem[obj-1][wght];

}//b1
 
int main(){//b4
	
	for (int i=0; i<pwsize ; i++)
		for (int j=0; j<constraint+1 ; j++)
       			 mem[i][j] = 0;

	printf("max profit is - %d",knap(pwsize,constraint));
		printf("\n");
	
	for (int i=0; i<pwsize ; i++){
		for (int j=0; j<constraint+1 ; j++){
       			 printf(" %d ",mem[i][j]);
		}
		printf("\n");
	}


	return 0;
}//b4

