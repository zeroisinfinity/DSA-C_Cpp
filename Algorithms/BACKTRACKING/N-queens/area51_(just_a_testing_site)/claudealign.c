#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

void exitOrNot(int* arg){
    if(!arg){
        fprintf(stderr,"Memory allocation failed\n");
        exit(1);
    }
}

bool valid_move(int k_row, int l_col, int* soln, int dxd, size_t* arr_len){
    // Check conflicts with previously placed queens
    for(int trav = 0; trav < *arr_len; trav++){
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

void resize(int** arr, size_t* arr_len, int xve, int dxd){
    if(xve == 1) {
        // Grow array by 1
        (*arr_len)++;
        int *tmp = realloc(*arr, *arr_len * sizeof(int));
        exitOrNot(tmp);
        *arr = tmp;
        printf("Array grown to size %zu\n", *arr_len);
    }
    else if(xve == -1 && *arr_len > 0) {
        // Shrink array by 1
        (*arr_len)--;
        if(*arr_len == 0) {
            free(*arr);
            *arr = NULL;
        } else {
            int *tmp = realloc(*arr, *arr_len * sizeof(int));
            exitOrNot(tmp);
            *arr = tmp;
        }
        printf("Array shrunk to size %zu\n", *arr_len);
    }
    else if(xve == 0) {
        // Free array completely
        if(*arr) {
            free(*arr);
            *arr = NULL;
        }
        *arr_len = 0;
        printf("Array freed\n");
    }
}

void progs_bar(int xve, int** arr, size_t* arr_len, int dxd) {
    switch (xve) {
        case -1: {
            resize(arr, arr_len, xve, dxd);
            break;
        }
        case 1: {
            resize(arr, arr_len, xve, dxd);
            break;
        }
        case 0: {
            resize(arr, arr_len, xve, dxd);
            break;
        }
        default: {
            fprintf(stderr, "Enter valid numeric value\n");
            exit(1);
        }
    }
}

bool place_queen(int dxd, int k_row, int** soln, size_t* arr_len ){
    // Base case: all queens placed
    if(k_row == dxd) {
        return true;
    }
    
    for(int trav = 0; trav < dxd; trav++){
        if(valid_move(k_row, trav, *soln, dxd, arr_len)){
            // Grow array to accommodate new queen
            progs_bar(1, soln, arr_len, dxd);
            
            // Place queen
            (*soln)[*arr_len - 1] = trav;
            
            printf("Placed queen at row %d, col %d (array index %zu)\n", 
                   k_row, trav, *arr_len - 1);
            
            // Recursive call
            if(place_queen(dxd, k_row + 1, soln, arr_len)) {
                return true;  // Solution found
            }
            
            // Backtrack: remove queen (shrink array)
            printf("Backtracking from row %d\n", k_row);
            progs_bar(-1, soln, arr_len, dxd);
        }
    }
    
    return false;  // No solution found
}

void display(int* soln, int dxd, size_t arr_len){
    printf("\nSolution found with array length %zu:\n", arr_len);
    printf("Queen positions (row, col):\n");
    for(int col = 0; col < arr_len; col++)
        printf("Queen %d: (%d,%d)\n", col + 1, col, soln[col]);
    
    printf("\nChessboard:\n");
    for(int i = 0; i < dxd; i++) {
        for(int j = 0; j < dxd; j++) {
            if(i < arr_len && soln[i] == j) {
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
    int* dxd = (int*)calloc(1,sizeof(int));
    exitOrNot(dxd);
    scanf("%d",dxd);
    
    // Start with NULL pointer (no memory allocated)
    int* soln = NULL;
    size_t* arr_len = (size_t*)calloc(1, sizeof(size_t));
    exitOrNot((int*)arr_len);
    *arr_len = 0;  // Start with 0 elements
    
    printf("Solving %d-Queens problem with dynamic array...\n", *dxd);
    
    bool solution_found = place_queen(*dxd, 0, &soln, arr_len);
    
    if(solution_found) {
        display(soln, *dxd, *arr_len);
    } else {
        printf("No solution exists for %d-Queens problem.\n", *dxd);
    }
    
    // Clean up
    if(soln) free(soln);
    free(dxd);
    free(arr_len);
    
    return 0;
}
