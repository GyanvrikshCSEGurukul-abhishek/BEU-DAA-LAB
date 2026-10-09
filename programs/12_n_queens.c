/* Experiment 12: N-Queens using Backtracking.
   Place N queens on an N x N chessboard so no two queens attack each other.
   Compile: gcc .\12_n_queens.c -o n_queens
   Run:     ./n_queens.exe
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_N 15

static int n, col[MAX_N], solutions = 0;

static int safe(int row, int c) {
    for (int r = 0; r < row; ++r) {
        if (col[r] == c) return 0; /* Same column. */
        if (abs(col[r] - c) == abs(r - row)) return 0; /* Same diagonal. */
    }
    return 1;
}

static void solve(int row) {
    if (row == n) {
        ++solutions;
        printf("Solution %d:\n", solutions);
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c)
                printf("%c ", col[r] == c ? 'Q' : '.');
            printf("\n");
        }
        printf("\n");
        return;
    }
    for (int c = 0; c < n; ++c) {
        if (safe(row, c)) {
            col[row] = c;   /* Place a queen in this row and column. */
            solve(row + 1); /* Recurse to the next row. */
        }
    }
}

int main(void) {
    printf("Enter N (1-%d): ", MAX_N);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX_N) {
        printf("Invalid N.\n"); return 1;
    }
    solve(0);
    if (!solutions) printf("No solution exists for N = %d.\n", n);
    else printf("Total solutions = %d\n", solutions);
    return 0;
}
