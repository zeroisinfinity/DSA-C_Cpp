#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Global board and backtrack counter
int sudoku_board[9][9];
long long backtrack_count = 0;

// EVIL PUZZLE #1 - "The Platinum Blonde" - 17 clues minimum
int evil_platinum[9][9] = {
    {0, 0, 0, 0, 0, 6, 0, 0, 0},
    {0, 5, 9, 0, 0, 0, 0, 0, 8},
    {2, 0, 0, 0, 0, 8, 0, 0, 0},
    {0, 4, 5, 0, 0, 0, 0, 0, 0},
    {0, 0, 3, 0, 0, 0, 0, 0, 0},
    {0, 0, 6, 0, 0, 3, 0, 5, 4},
    {0, 0, 0, 3, 2, 5, 0, 0, 6},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0}
};

// EVIL PUZZLE #2 - "The Backtrack Nightmare" - Forces maximum exploration
int evil_nightmare[9][9] = {
    {8, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 3, 6, 0, 0, 0, 0, 0},
    {0, 7, 0, 0, 9, 0, 2, 0, 0},
    {0, 5, 0, 0, 0, 7, 0, 0, 0},
    {0, 0, 0, 0, 4, 5, 7, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 3, 0},
    {0, 0, 1, 0, 0, 0, 0, 6, 8},
    {0, 0, 8, 5, 0, 0, 0, 1, 0},
    {0, 9, 0, 0, 0, 0, 4, 0, 0}
};

// EVIL PUZZLE #3 - "The Exponential Beast" - Classic hardest
int evil_exponential[9][9] = {
    {0, 0, 0, 0, 0, 0, 0, 1, 0},
    {4, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 6, 0, 0},
    {0, 0, 0, 0, 1, 0, 4, 0, 0},
    {0, 0, 0, 0, 6, 0, 2, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0}
};

// EVIL PUZZLE #4 - "The Sudoku Slayer" - Infamous for being slow
int evil_slayer[9][9] = {
    {1, 0, 0, 0, 0, 7, 0, 9, 0},
    {0, 3, 0, 0, 2, 0, 0, 0, 8},
    {0, 0, 9, 6, 0, 0, 5, 0, 0},
    {0, 0, 5, 3, 0, 0, 9, 0, 0},
    {0, 1, 0, 0, 8, 0, 0, 0, 2},
    {6, 0, 0, 0, 0, 4, 0, 0, 0},
    {3, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 4, 0, 0, 0, 0, 0, 0, 7},
    {0, 0, 7, 0, 0, 0, 3, 0, 0}
};

// EVIL PUZZLE #5 - "The CPU Melter" - Sparse and deadly
int evil_cpu_melter[9][9] = {
    {0, 0, 5, 3, 0, 0, 0, 0, 0},
    {8, 0, 0, 0, 0, 0, 0, 2, 0},
    {0, 7, 0, 0, 1, 0, 5, 0, 0},
    {4, 0, 0, 0, 0, 5, 3, 0, 0},
    {0, 1, 0, 0, 7, 0, 0, 0, 6},
    {0, 0, 3, 2, 0, 0, 0, 8, 0},
    {0, 6, 0, 5, 0, 0, 0, 0, 9},
    {0, 0, 4, 0, 0, 0, 0, 3, 0},
    {0, 0, 0, 0, 0, 9, 7, 0, 0}
};

// EVIL PUZZLE #6 - "The Recursive Rabbit Hole" - Deep backtracking
int evil_rabbit_hole[9][9] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 3, 0, 8, 5},
    {0, 0, 1, 0, 2, 0, 0, 0, 0},
    {0, 0, 0, 5, 0, 7, 0, 0, 0},
    {0, 0, 4, 0, 0, 0, 1, 0, 0},
    {0, 9, 0, 0, 0, 0, 0, 0, 0},
    {5, 0, 0, 0, 0, 0, 0, 7, 3},
    {0, 0, 2, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 4, 0, 0, 0, 9}
};

// EVIL PUZZLE #7 - "The Ultimate Time Sink" - Causes maximum branching
int evil_time_sink[9][9] = {
    {0, 2, 0, 6, 0, 8, 0, 0, 0},
    {5, 8, 0, 0, 0, 9, 7, 0, 0},
    {0, 0, 0, 0, 4, 0, 0, 0, 0},
    {3, 7, 0, 0, 0, 0, 5, 0, 0},
    {6, 0, 0, 0, 0, 0, 0, 0, 4},
    {0, 0, 8, 0, 0, 0, 0, 1, 3},
    {0, 0, 0, 0, 2, 0, 0, 0, 0},
    {0, 0, 9, 8, 0, 0, 0, 3, 6},
    {0, 0, 0, 3, 0, 6, 0, 9, 0}
};

void display() {
    const int cell_height = 5;
    const int cell_width  = 10;

    for (int r = 0; r < 9; r++) {
        for (int line = 0; line < cell_height; line++) {
            for (int c = 0; c < 9; c++) {
                int block_row = r / 3;
                int block_col = c / 3;

                if ((block_row + block_col) % 2 == 0)
                    printf("\x1b[47;30m");
                else
                    printf("\x1b[40;37m");

                for (int w = 0; w < cell_width; w++) {
                    if (line == cell_height / 2 && w == cell_width / 2) {
                        if (sudoku_board[r][c] != 0)
                            printf("%d",sudoku_board[r][c]);
                        else
                            printf(" ");
                    } else {
                        printf(" ");
                    }
                }
                printf("\x1b[0m");
            }
            printf("\n");
        }
    }
}

bool valid(int row , int col , int val){
    // Check row
    for(int c = 0 ; c < 9 ; c++){
        if(sudoku_board[row][c] == val)
            return false;
    }
    
    // Check column  
    for(int r = 0 ; r < 9 ; r++){
        if(sudoku_board[r][col] == val)
            return false;
    }
    
    // Check 3x3 block
    int blockrow = row - row%3;
    int blockcol = col - col%3;
    
    for(int br = 0 ; br < 3 ; br++){
        for(int bc = 0 ; bc < 3 ; bc++){
          if(sudoku_board[blockrow+br][blockcol+bc] == val)
              return false;
        }
    }
    return true;
}
bool sudoku(int row , int col ){//b66

      if(row == 9 && col == 0){//b7
            display();
            return true;
      }//b7
      
      else{//b67
          if(!sudoku_board[row][col]){//b6          
            for(int i = 1 ; i <= 9 ; i++){//b8           
                  if(valid(row,col,i)){//b11
                      sudoku_board[row][col] = i;
                      if (sudoku( col==8 ? row + 1:row , col==8 ? 0:col + 1 )) return true;
                      sudoku_board[row][col] = 0;
                  }//b11
                  
            }//b8
            
      }//b6        
      
          else{//b9
                      if (sudoku( col==8 ? row + 1 : row , col==8 ? 0 : col+1 )) return true;
           }//b9
           
    }//b67
    
}//b66

void copy_board(int source[9][9]) {
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            sudoku_board[i][j] = source[i][j];
        }
    }
    return false;
}

void test_evil_puzzle(int puzzle[9][9], const char* name) {
    printf("\n🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥\n");
    printf("💀 TESTING: %s 💀\n", name);
    printf("🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥\n");
    
    copy_board(puzzle);
    backtrack_count = 0;
    
    printf("Initial puzzle (prepare for pain):\n");
    display();
    
    printf("\n⚡ Starting solver... This might take a VERY long time...\n");
    printf("⚡ Watch the backtrack counter explode!\n\n");
    
    clock_t start = clock();
    
    if (sudoku(0,0)) {
        clock_t end = clock();
        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("\n🎉 SOLVED! But at what cost...\n");
        printf("⏰ Time taken: %.2f seconds\n", time_taken);
        printf("💀 Total backtracks: %lld\n", backtrack_count);
        printf("🔥 Backtracks per second: %.0f\n", backtrack_count/time_taken);
    } else {
        printf("\n💀 FAILED! Even after all that work!\n");
        printf("💀 Total backtracks attempted: %lld\n", backtrack_count);
    }
}

int main() {
    printf("\x1b[1;31m💀💀💀 WELCOME TO SUDOKU HELL 💀💀💀\x1b[0m\n");
    printf("These puzzles are VALID but will DESTROY your CPU!\n");
    printf("Each one is designed to cause maximum backtracking.\n");
    printf("Grab some popcorn... you'll be here a while.\n\n");
    
    printf("⚠️  WARNING: Some of these might take HOURS to solve!\n");
    printf("⚠️  Press Ctrl+C if you want to escape the pain.\n\n");
    
    // Test the evil puzzles - start with easier ones
    test_evil_puzzle(evil_platinum, "THE PLATINUM BLONDE (17 clues)");
    test_evil_puzzle(evil_slayer, "THE SUDOKU SLAYER (CPU Killer)");
    test_evil_puzzle(evil_cpu_melter, "THE CPU MELTER (Sparse Death)");
    test_evil_puzzle(evil_nightmare, "THE BACKTRACK NIGHTMARE");
    test_evil_puzzle(evil_rabbit_hole, "THE RECURSIVE RABBIT HOLE");
    test_evil_puzzle(evil_time_sink, "THE ULTIMATE TIME SINK");
    
    // This one is absolutely brutal - uncomment if you hate your CPU
    // test_evil_puzzle(evil_exponential, "THE EXPONENTIAL BEAST (WARNING: EXTREME!)");
    
    printf("\n🎯 If you made it this far, your CPU is a WARRIOR! 🎯\n");
    printf("Your poor solver just went through computational hell.\n");
    
    return 0;
}
