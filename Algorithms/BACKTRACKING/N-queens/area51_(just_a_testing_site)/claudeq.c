#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

void exitOrNot(int* arg) {
    if(!arg) {
        fprintf(stderr,"Memory allocation failed\n");
        exit(1);
    }
}

bool valid_move(int k_row, int l_col, int* soln, int dxd, size_t* arr_len) {
    // Check all previously placed queens (from row 0 to k_row-1)
    for(int trav = 0; trav < k_row; trav++) {
        // Check column conflict
        if(soln[trav] == l_col) {
            return false;
        }
        
        // Check diagonal conflicts
        if(abs(soln[trav] - l_col) == abs(trav - k_row)) {
            return false;
        }
    }
    return true;
}

bool place_queen(int dxd, int k_row, int* soln, size_t* arr_len) {
    // Base case: all queens placed
    if(k_row == dxd) {
        return true; // Solution found
    }
    
    // Try placing queen in each column of current row
    for(int trav = 0; trav < dxd; trav++) {
        if(valid_move(k_row, trav, soln, dxd, arr_len)) {
            soln[k_row] = trav;  // Place queen at column trav
            if (place_queen(dxd, k_row + 1, soln, arr_len)) {
                return true;
            }
        }
    }
    return false;
}

void resize(int** arr, size_t* arr_len, int xve, int dxd) {
    // This function is not needed for basic N-Queens, but keeping for compatibility
    if(*arr_len != dxd) {
        *arr_len = dxd;
        int *tmp = realloc(*arr, *arr_len * sizeof(int));
        exitOrNot(tmp);
        *arr = tmp;
    }
}

void progs_bar(int xve, int* arr, size_t* arr_len, int dxd) {
    switch (xve) {
        case -1: {
            resize(&arr, arr_len, xve, dxd);
            break;
        }
        case 1: {
            resize(&arr, arr_len, xve, dxd);
            break;
        }
        case 0: {
            resize(&arr, arr_len, xve, dxd);
            break;
        }
        default: {
            fprintf(stderr, "Enter valid numeric value\n");
            exit(1);
        }
    }
}

void display(int* soln, int dxd) {
    printf("Solution found:\n");
    printf("Queen positions (row, col):\n");
    for(int col = 0; col < dxd; col++)
        printf("Queen %d: (%d,%d)\n", col + 1, col, soln[col]);
    
    printf("\nChessboard:\n");
    for(int i = 0; i < dxd; i++) {
        for(int j = 0; j < dxd; j++) {
            if(soln[i] == j) {
                printf(" Q ");
            } else {
                printf(" . ");
            }
        }
        printf("\n");
    }
}

int main() {
    printf("Enter your chessboard dimension - ");
    int* dxd = (int*)calloc(1, sizeof(int));
    exitOrNot(dxd);
    scanf("%d", dxd);
    
    // Allocate solution array with proper size
    int* soln = (int*)calloc(*dxd, sizeof(int));
    exitOrNot(soln);
    
    size_t* arr_len = (size_t*)malloc(sizeof(size_t));
    exitOrNot((int*)arr_len);
    *arr_len = *dxd;
    
    // Initialize solution array
    for(int i = 0; i < *dxd; i++) {
        soln[i] = -1;
    }
    
    printf("Solving %d-Queens problem...\n", *dxd);
    
    // Start solving from row 0
    bool solution_found = place_queen(*dxd, 0, soln, arr_len);
    
    if(solution_found) {
        display(soln, *dxd);
    } else {
        printf("No solution exists for %d-Queens problem.\n", *dxd);
    }
    
    // Clean up
    free(soln);
    free(dxd);
    free(arr_len);
    
    return 0;
}
