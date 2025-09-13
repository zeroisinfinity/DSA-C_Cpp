#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("Enter your chessboard dimension - ");
    int dxd;
    scanf("%d",&dxd);
    int* soln = (int*)calloc(dxd,sizeof(int));
    soln[0] = 9;
    soln[1] = 10;
    int* x=soln;
    x[1]=4;
    printf("%d %d",x[1],soln[1]);
    return 0;
}

