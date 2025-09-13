#include <stdio.h>

// Print an N x N chessboard with given labels
void printChessboard(int n, const char *labels[], int cellW, int cellH) {
    const char *reset = "\x1b[0m";
    const char *white_bg_black_fg = "\x1b[47m\x1b[30m";  // white bg, black text
    const char *black_bg_white_fg = "\x1b[40m\x1b[37m";  // black bg, white text

    int idx = 0;

    for (int row = 0; row < n; row++) {
        for (int h = 0; h < cellH; h++) {   // expand vertically
            for (int col = 0; col < n; col++) {
                const char *style = ((row + col) % 2 == 0)
                                    ? white_bg_black_fg
                                    : black_bg_white_fg;

                if (h == cellH / 2) {
                    // center the label in the middle line
                    int labelLen = 3; // "Qxx" = 3 chars
                    int padding = (cellW - labelLen) / 2;
                    printf("%s%*s%-3s%*s%s",
                           style, padding, "", labels[idx],
                           cellW - padding - labelLen, "", reset);
                    idx++;  // ✅ advance to next label after printing it
                } else {
                    // filler rows
                    for (int w = 0; w < cellW; w++)
                        printf("%s %s", style, reset);
                }
            }
            printf("\n");
        }
    }
}

int main() {

    printf("Enter your chessboard dimension - ");
    int dxd;
    scanf("%d",&dxd);
    int* soln = (int*)malloc(sizeof(int*dxd));
    int n = 4;  // 4x4 board
    const char *labels[16];
    static char buffer[16][4]; // "Q16\0" fits easily

    for (int i = 0; i < n * n; i++) {
        sprintf(buffer[i], "Q%d", i + 1);
        labels[i] = buffer[i];
    }

    printChessboard(n, labels, 10, 5); // each square: width=10, height=5
    return 0;
}

