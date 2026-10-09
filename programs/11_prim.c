/* Experiment 11: Minimum Spanning Tree using Prim's algorithm.
   Enter an undirected weighted adjacency matrix; 0 means no edge.
   Use positive weights for edges. Vertices are numbered 1..n.
   Compile: gcc .\11_prim.c -o prim
   Run:     ./prim.exe
*/
#include <stdio.h>
#include <limits.h>
#define MAX 100
#define INF (LLONG_MAX / 4)

int main(void) {
    int n, graph[MAX][MAX], selected[MAX] = {0}, parent[MAX];
    long long key[MAX], total = 0;
    printf("Enter number of vertices (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid number of vertices.\n"); return 1;
    }
    printf("Enter weighted symmetric adjacency matrix (0 means no edge):\n");
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (scanf("%d", &graph[i][j]) != 1 || graph[i][j] < 0) {
                printf("Invalid matrix; use non-negative weights.\n"); return 1;
            }
    for (int i = 0; i < n; ++i) { key[i] = INF; parent[i] = -1; }
    key[0] = 0;

    for (int count = 0; count < n; ++count) {
        int u = -1;
        for (int i = 0; i < n; ++i)
            if (!selected[i] && (u == -1 || key[i] < key[u])) u = i;
        if (u == -1 || key[u] == INF) {
            printf("Graph is disconnected; no spanning tree exists.\n"); return 0;
        }
        selected[u] = 1;
        for (int v = 0; v < n; ++v)
            if (!selected[v] && graph[u][v] > 0 && graph[u][v] < key[v]) {
                key[v] = graph[u][v]; parent[v] = u;
            }
    }
    printf("Edges in the minimum spanning tree:\n");
    for (int v = 1; v < n; ++v) {
        printf("%d -- %d (weight %lld)\n", parent[v] + 1, v + 1, key[v]);
        total += key[v];
    }
    printf("Total MST cost = %lld\n", total);
    return 0;
}
