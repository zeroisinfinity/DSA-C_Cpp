#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
int* sol_no;
const char *reset = "\x1b[0m";
const char *white_bg_black_fg = "\x1b[47m\x1b[30m";
const char *black_bg_white_fg = "\x1b[40m\x1b[37m";

void display(int *soln, int n, int cellW, int cellH) {
    for (int row = 1; row <= n; row++) {
        for (int h = 0; h < cellH; h++) {
            for (int col = 1; col <= n; col++) {
                const char *style = ((row + col) % 2 == 0)
                                    ? white_bg_black_fg
                                    : black_bg_white_fg;

                if (h == cellH / 2) {
                    if (soln[row-1] == col) {
                        char qlabel[32];
                        snprintf(qlabel, sizeof(qlabel), "Q%d", row);// Queen label
                        int labelLen = (int)strlen(qlabel);
                        int padding = (cellW - labelLen) / 2;
                        printf("%s%*s%-*s%s",
                               style,
                               padding, "",
                               cellW - padding, qlabel,
                               reset);
                    } else {
                        for (int w = 0; w < cellW; w++)
                            printf("%s %s", style, reset);
                    }
                } else {
                    for (int w = 0; w < cellW; w++)
                        printf("%s %s", style, reset);
                }
            }
            printf("\n");
        }
    }
    printf("\n");
}

bool valid_move(int k_row , int l_col , int* soln) {
    for (int trav = 0; trav < k_row - 1; trav++) {
        bool same_diag = abs((trav+1) - k_row) == abs(soln[trav] - l_col);
        bool same_col  = (soln[trav] == l_col);
        if (same_diag || same_col) return false;
    }
    return true;
}

void place_queen(int dxd, int k_row, int* soln, int cellW, int cellH) {
    if (k_row > dxd) {
        printf("\x1b[1;30;102mSOLUTION NUMBER - %d\x1b[0m\n",(*sol_no)+1);
        (*sol_no)++;
        display(soln, dxd, cellW, cellH);  // print board when solution complete
        return;
    }
    for (int trav = 0; trav < dxd; trav++) {
        if (valid_move(k_row, trav+1, soln)) {
            soln[k_row-1] = trav+1;
            place_queen(dxd, k_row+1, soln, cellW, cellH);
        }
    }
}

int main() {
    int dxd;
    printf("Enter your chessboard dimension: ");
    scanf("%d", &dxd);

    int *soln = calloc(dxd, sizeof(int));
    sol_no = calloc(1, sizeof(int));
    if (!soln) exit(1);
    if (!sol_no) exit(1);

    place_queen(dxd, 1, soln, 6, 3);  // cell width=6, height=3
    
    if(!*sol_no) printf("\x1b[1;37;41mNO SOLUTION POSSIBLE\x1b[0m\n");
    
    free(soln);
    free(sol_no);
    return 0;
}

