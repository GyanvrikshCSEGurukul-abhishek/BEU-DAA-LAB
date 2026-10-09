/* Experiment 3: Transitive closure using Warshall's algorithm
   Vertices are numbered 1..n. Enter 1 for an edge and 0 otherwise.
   Compile: gcc .\03_warshall.c -o warshall
   Run:     ./warshall.exe
*/
#include <stdio.h>
#define MAX 100

int main(void) {
    int n, reach[MAX][MAX];
    printf("Enter number of vertices (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid number of vertices.\n"); return 1;
    }
    printf("Enter adjacency matrix (%d rows, %d values per row):\n", n, n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            if (scanf("%d", &reach[i][j]) != 1) {
                printf("Invalid matrix input.\n"); return 1;
            }
            reach[i][j] = (reach[i][j] != 0);
        }

    /* If i reaches k and k reaches j, then i reaches j. */
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);

    printf("Transitive closure matrix:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) printf("%d ", reach[i][j]);
        printf("\n");
    }
    return 0;
}
