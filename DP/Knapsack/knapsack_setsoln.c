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

const int prof[5] = {0,3,5,6,8};
const int wght[5] = {0,1,2,1,2};
const int constraint = 5; 

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

int cmp_item(const void *a, const void *b) {//b13
    const pw *pa = (const pw*)a;
    const pw *pb = (const pw*)b;
    return pa->weight - pb->weight;
}//b13

/*bool dominance( pw* ans , int indx , int profit , int weight){//b7
	
	if(!indx) return true;
	
	while(ans[indx]){//b12
	    bool prof = ans[indx-1].profit >= profit;  
	    bool wght = ans[indx-1].weight <= weight; 

	    if(prof && wght) return false;
	    else return true;

}//b7*/
 pw* valid(int prof , int wght , pw* ans , int size){//b11
		if( wght <= constraint){//b8
				ans = legal(size , ans);
				ans[size].profit = prof;
				ans[size].weight = wght;
				printf("SET[trav+1] is (%d , %d)\n" , ans[size].profit , ans[size].weight);
	}//b8
	return ans;
}//b11
pw* copy(pw* pw1 , pw* pw2,int* size){//b15
    int i = 0;
    while(pw1[i].profit){//b16
        pw2 = valid(pw1[i].profit,pw1[i].weight,pw1,*size);
        i++;
    }//b16
    *size = i;
    return pw2;
}//b15


 
int main(){//b1
        pw* subsets[5];
        int* size = calloc(1,sizeof(int));
	for(int trav = 0 ; trav < 5 ; trav++){//b6
	                
	                if(!trav) subsets[trav] = copy(subsets[trav-1],subsets[trav],size);
	                
		        subsets[trav] = valid(prof[trav],wght[trav],subsets[trav],*size);
		  	(*size)++;
	
			int limit = *size - 1;
			int iter_soln = 1;
			while(iter_soln < limit){//b9
					
				int tmp_p = subsets[trav][iter_soln].profit + prof[trav];
				int tmp_w = subsets[trav][iter_soln].weight + wght[trav];
	
			        subsets[trav] = valid(tmp_p,tmp_w,subsets[trav],*size);
				(*size)++;	
				iter_soln++;
			}//b9
			

	}//b6
	
	
	return 0;
}//b1
