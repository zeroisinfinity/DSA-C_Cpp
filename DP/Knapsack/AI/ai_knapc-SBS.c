#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

const char* BRIGHT_RED = "\x1b[91m";
const char* RESET = "\x1b[0m";

typedef struct {//b2
	int profit;
	int weight;
} pw; //b2 

const int prof[9] = {0, 10, 30, 30, 35, 40, 40, 50, 60};
const int wght[9] = {0,  5,  5,  6,  2,  4,  7,  6,  9};
const int constraint = 15;
const int pwsize = 9;
int soln[pwsize-1] = {0}; // This will be 8

pw* legal(size_t records, pw* ans){//b3
	pw* tmp = realloc(ans, (records+1)*sizeof(pw));
	if(!tmp){//b4
		fprintf(stderr, "%sERROR : Memory NOT allocated ... \n"
				"Possible reasons are enlisted below\n"
				"1) Not enough RAM Space\n"
				"2) Corrupted Heap\n"
				"3) Size > SIZE_MAX (%zu)\n"
				"4) Invalid pointer passed%s", BRIGHT_RED, SIZE_MAX, RESET);
		exit(1);
	}//b4
	return tmp;
}//b3

int cmp_item(const void *a, const void *b) {//b13
    const pw *pa = (const pw*)a;
    const pw *pb = (const pw*)b;
    if(pa->weight == pb->weight) return pb->profit - pa->profit; // higher profit first if weight same
    return pa->weight - pb->weight; // smaller weight first
}//b13

void dominance(pw** ans, int* size){//b25
    if(*size <= 1) return;
    
    // Sort by weight ascending, profit descending
    qsort(*ans, *size, sizeof(pw), cmp_item);
    
    pw* filtered = malloc(*size * sizeof(pw));
    int new_size = 0;
    int max_profit = -1;
    
    for(int i = 0; i < *size; i++){//b26
        if((*ans)[i].profit > max_profit){//b27
            filtered[new_size] = (*ans)[i];
            max_profit = (*ans)[i].profit;
            new_size++;
        }//b27
    }//b26
    
    free(*ans);
    *ans = filtered;
    *size = new_size;
}//b25

pw* valid(int prof, int wght, pw* ans, int* size){//b11
    if(wght <= constraint){//b8
        ans = legal(*size, ans);
        ans[*size].profit = prof;
        ans[*size].weight = wght;
        (*size)++;
    }//b8
    return ans;
}//b11

pw* fill(pw* prev, int prev_size, int ele, int* curr_size){//b14
    pw* curr = NULL;
    *curr_size = 0;
    
    // Copy previous states
    for(int i = 0; i < prev_size; i++){//b4
        curr = valid(prev[i].profit, prev[i].weight, curr, curr_size);
    }//b4
    
    // Add single item if it fits
    if(wght[ele] <= constraint){
        curr = valid(prof[ele], wght[ele], curr, curr_size);
    }
    
    // Add combinations
    for(int i = 0; i < prev_size; i++){//b4
        int p = prev[i].profit + prof[ele];
        int w = prev[i].weight + wght[ele];
        if(w <= constraint){
            curr = valid(p, w, curr, curr_size);
        }
    }//b4
    
    return curr;
}//b14

void display(pw** subsets, int* sizes, int* bit, int opt){//b10
    if(!opt){//b22
        for(int i = 0; i < pwsize; i++){//b9
            printf("SETS[%d] - ", i);
            for(int j = 0; j < sizes[i]; j++){//b11
                printf("{%d,%d}", subsets[i][j].profit, subsets[i][j].weight);
            }//b11
            printf("\n");
        }//b9
    }//b22
    else{//b23
        printf("SOLUTION - [  ");
        for(int j = 0; j < pwsize-1; j++){//b24
            if(bit[j]) printf("{%d,%d}  ", prof[j+1], wght[j+1]);
        }//b24
        printf("]\n");
    }//b23
}//b10

void ans(pw** soln, int* sizes, int* bit, int length, int i){//b17
    pw target = {soln[length][sizes[length]-1].profit, soln[length][sizes[length]-1].weight};
    bool exists = false;
    int j = i - 1;
    
    for(int trav = length; trav >= 1; trav--){//b18
        for(int k = 0; k < sizes[trav-1]; k++){//b19
            if(soln[trav-1][k].profit == target.profit && 
               soln[trav-1][k].weight == target.weight){//b20
                exists = true;
                break;
            }//b20
        }//b19
        
        if(exists) bit[j] = 0;
        else{//b21
            bit[j] = 1;
            int f = target.profit - prof[trav];
            int s = target.weight - wght[trav];
            if(f < 0 || s < 0) {
                target.profit = 0;
                target.weight = 0;
            }
            else {
                target.profit = f;
                target.weight = s;
            }
        }//b21
        j--;
        exists = false;
    }//b18
}//b17

int main(){//b1

    pw* subsets[pwsize];
    int sizes[pwsize];
    
    for(int trav = 0; trav < pwsize; trav++){//b15
        if(!trav){
            subsets[trav] = NULL;
            sizes[trav] = 0;
            subsets[trav] = valid(prof[trav], wght[trav], subsets[trav], &sizes[trav]);
        }
        else{
            subsets[trav] = fill(subsets[trav-1], sizes[trav-1], trav, &sizes[trav]);
        }
    }//b15
    
    // Apply dominance to each stage
    for(int i = 0; i < pwsize; i++){//b16
        dominance(&subsets[i], &sizes[i]);
    }//b16
    
    display(subsets, sizes, soln, 0);
    ans(subsets, sizes, soln, pwsize-1, pwsize-1);
    display(subsets, sizes, soln, 1);
    
    // Free memory
    for(int i = 0; i < pwsize; i++){
        free(subsets[i]);
    }
    
    return 0;
}//b1
