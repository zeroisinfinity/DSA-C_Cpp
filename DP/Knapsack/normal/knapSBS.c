#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

const char* BRIGHT_RED = "\x1b[91m";
const char* RESET = "\x1b[0m";

typedef struct {//b2
	int profit;
	int weight;
} pw; //b2 
 

pw* legal(size_t records , pw* ans){//b3
	
	pw* tmp = realloc(ans , (records+1)*sizeof(pw));

	if(!tmp){//b4
		 fprintf(stderr , "%sERROR : Memory NOT allocated ... \n"
				 	"Possible reasons are enlisted below\n"
					"1) Not enough RAM Space\n"
			 		"2) Corrupted Heap\n"
					"3) Size > SIZE_MAX (%zu)\n"
					"4) Invalid pointer passed%s" , BRIGHT_RED , SIZE_MAX , RESET);
		 exit(1);
	}//b4
	
	else{//b5
	     	return tmp;
	}//b5
}//b3


bool dominance( pw* ans , int indx , int profit , int weight){//b7
	
	if(!indx) return true;
	
	bool prof = ans[indx-1].profit >= profit;  
	bool wght = ans[indx-1].weight <= weight; 

	if(prof && wght) return false;
	else return true;

}//b7
 

void valid(int constraint , int trav , int prof , int wght , pw* ans , int size){//b11
		if( wght <= constraint && dominance(ans , trav , prof, wght)){//b8
				soln = legal(size , soln);
				soln[size].profit = prof;
				soln[size].weight = wght;
				printf("SET[trav+1] is (%d , %d)\n" , soln[size].profit , soln[size].weight);
	
}//b11
 
int main(){//b1
	
	pw* soln = NULL;
	size_t size = 0;
	int prof[5] = {0,3,5,6,8};
	int wght[5] = {0,1,2,1,2};
	int subsets[10];
	int constraint = 5;

	for(int trav = 0 ; trav < 5 ; trav++){//b6
		if( wght[trav] <= constraint && dominance(soln , trav , prof[trav] , wght[trav])){//b8
				soln = legal(size , soln);
				soln[size].profit = prof[trav];
				soln[size].weight = wght[trav];
				printf("SET[trav+1] is (%d , %d)\n" , soln[size].profit , soln[size].weight);
				size++;
	
				int limit = size-1;
				int iter_soln = 1;
				while(iter_soln < limit){//b9
					
					int tmp_p = soln[iter_soln].profit + prof[trav];
					int tmp_w = soln[iter_soln].weight + wght[trav];
	
					if(dominance(soln , trav+1 , tmp_p , tmp_w) && tmp_w <= constraint ){//b10
						soln = legal(size , soln);
						soln[size].profit = tmp_p;
						soln[size].weight = tmp_w;
						printf("SET[trav+1] is (%d , %d)\n" , soln[size].profit , soln[size].weight);
						size++;	
					}//b10
					iter_soln++;
				}//b9
		}//b8
	}//b6
	return 0;
}//b1
