#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

bool is_safe(int* board, int row, int col, int n) {
    // Check previously placed queens (rows 0 to row-1)
    for (int i = 0; i < row; i++) {
        // Check column conflict
        if (board[i] == col) {
            return false;
        }
        
        // Check diagonal conflicts
        if (abs(board[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

bool solve_nqueens(int* board, int row, int n) {
    // Base case: all queens placed
    if (row == n) {
        return true;
    }
    
    // Try placing queen in each column of current row
    for (int col = 0; col < n; col++) {
        if (is_safe(board, row, col, n)) {
            // Place queen
            board[row] = col;
            
            // Recursively place queens in remaining rows
            if (solve_nqueens(board, row + 1, n)) {
                return true;  // Solution found
            }
            
            // Backtrack - no need to explicitly remove queen
            // It will be overwritten in next iteration
        }
    }
    
    return false;  // No solution found for this configuration
}

void print_solution(int* board, int n) {
    printf("\nSolution found!\n");
    printf("Queen positions (row, col):\n");
    for (int i = 0; i < n; i++) {
        printf("Queen %d: (%d, %d)\n", i + 1, i, board[i]);
    }
    
    printf("\nChessboard:\n");
    printf("   ");
    for (int j = 0; j < n; j++) {
        printf("%2d ", j);
    }
    printf("\n");
    
    for (int i = 0; i < n; i++) {
        printf("%2d ", i);
        for (int j = 0; j < n; j++) {
            if (board[i] == j) {
                printf(" Q ");
            } else {
                printf(" . ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

bool find_all_solutions(int* board, int row, int n, int* solution_count) {
    // Base case: all queens placed
    if (row == n) {
        (*solution_count)++;
        printf("Solution %d:\n", *solution_count);
        printChessboard(board, n, 8, 3);  // Use fancy chessboard display
        printf("Queen positions: ");
        for (int i = 0; i < n; i++) {
            printf("Q%d:(%d,%d) ", i + 1, i, board[i]);
        }
        printf("\n\n");
        return false;  // Continue searching for more solutions
    }
    
    bool found_any = false;
    // Try placing queen in each column of current row
    for (int col = 0; col < n; col++) {
        if (is_safe(board, row, col, n)) {
            // Place queen
            board[row] = col;
            
            // Recursively place queens in remaining rows
            if (find_all_solutions(board, row + 1, n, solution_count)) {
                found_any = true;
            }
            
            // Continue to find more solutions (backtrack automatically)
        }
    }
    
    return found_any;
}

int main() {
    int n;
    printf("Enter the size of the chessboard (N for N-Queens): ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Invalid input! N must be positive.\n");
        return 1;
    }
    
    if (n == 2 || n == 3) {
        printf("No solution exists for %d-Queens problem.\n", n);
        return 0;
    }
    
    // Allocate memory for the board - ONE allocation for entire solution
    int* board = (int*)malloc(n * sizeof(int));
    if (!board) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }
    
    printf("Solving %d-Queens problem...\n\n", n);
    
    char choice;
    printf("Find (f)irst solution or (a)ll solutions? ");
    scanf(" %c", &choice);
    
    if (choice == 'f' || choice == 'F') {
        // Find first solution
        if (solve_nqueens(board, 0, n)) {
            print_solution(board, n);
        } else {
            printf("No solution exists for %d-Queens problem.\n", n);
        }
    } else if (choice == 'a' || choice == 'A') {
        // Find all solutions
        int solution_count = 0;
        find_all_solutions(board, 0, n, &solution_count);
        
        if (solution_count == 0) {
            printf("No solution exists for %d-Queens problem.\n", n);
        } else {
            printf("Total solutions found: %d\n", solution_count);
        }
    } else {
        printf("Invalid choice! Finding first solution...\n");
        if (solve_nqueens(board, 0, n)) {
            print_solution(board, n);
        } else {
            printf("No solution exists for %d-Queens problem.\n", n);
        }
    }
    
    // Clean up - ONE deallocation
    free(board);
    return 0;
}
