#include <stdio.h>

// Function to print a table with colors
void printTable() {
    // ANSI escape codes for colors
    const char *reset = "\x1b[0m";
    const char *bold = "\x1b[1m";
    const char *blue = "\x1b[34m";
    const char *cyan = "\x1b[36m";
    const char *yellow = "\x1b[33m";

    // Print the header
    printf("%s+-----+----------------+-----+%s\n", blue, reset);
    printf("%s| ID  | Name           | Age |%s\n", bold, reset);
    printf("%s+-----+----------------+-----+%s\n", blue, reset);

    // Print the rows
    printf("| %-3d | %-14s | %s%-3d%s |\n", 1, "Alice", cyan, 30, reset);
    printf("| %-3d | %-14s | %s%-3d%s |\n", 2, "Bob",   yellow, 25, reset);
    printf("| %-3d | %-14s | %s%-3d%s |\n", 3, "Charlie", cyan, 28, reset);

    // Footer
    printf("%s+-----+----------------+-----+%s\n", blue, reset);
}

int main() {
    printTable();
    return 0;
}

