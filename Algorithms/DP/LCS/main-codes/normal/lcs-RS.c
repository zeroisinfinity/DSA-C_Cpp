#include <stdio.h>
#include <stdlib.h>

char *str[2] = {NULL,NULL};

int max(int a,int b){ return a > b ? a : b; }

int lcs(int i , int j){//b3
	
	if(i == -1 || j == -1) return 0;
	if(str[0][i] == str[1][j]) return 1 + lcs(i - 1 , j - 1);
	else return max(lcs(i - 1 , j) , lcs(i , j - 1));
	
}//b3
 

int main(){//b1

	size_t slen[2] = {0,0};
	for(int i = 0 ; i < 2 ; ++i){//b2
		size_t len = 0;
		printf("Enter your string[%d] - ",i);
		ssize_t eos = getline(&str[i],&len,stdin);
		// ssize_t getline(char **lineptr, size_t *n, FILE *stream);
		if(eos!=-1) printf("Your string is - %s",str[i]);
		slen[i] = eos;
	}//b2
	
	printf("%d\n" , lcs(slen[0] - 2, slen[1] - 2));
//	That “4” isn’t a sign of some hidden magic in your code, it’s the newline messing with you.
//	getline keeps the \n if there’s room in the buffer. So when you type ace⏎, the string in memory is actually:
//	'a' 'c' 'e' '\n' '\0'		
//	Length (eos) = 4, not 3.
//	So when you run your LCS, it happily counts the newline characters too, and your result gets inflated.
	return 0;
}//b1
