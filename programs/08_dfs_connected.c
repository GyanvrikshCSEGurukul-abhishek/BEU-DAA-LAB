/* Experiment 8: Check graph connectivity using DFS.
   This program treats the input as an UNDIRECTED graph.
   Compile: gcc .\08_dfs_connected.c -o dfs_connected
   Run:     ./dfs_connected.exe
*/
#include <stdio.h>
#define MAX 100

static void dfs(int u, int n, int graph[MAX][MAX], int visited[MAX]) {
    visited[u] = 1;
    for (int v = 0; v < n; ++v)
        if (graph[u][v] && !visited[v]) dfs(v, n, graph, visited);
}

int main(void) {
    int n, graph[MAX][MAX], visited[MAX] = {0};
    printf("Enter number of vertices (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid number of vertices.\n"); return 1;
    }
    printf("Enter symmetric adjacency matrix (0/1) for an undirected graph:\n");
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (scanf("%d", &graph[i][j]) != 1) {
                printf("Invalid matrix.\n"); return 1;
            }
    dfs(0, n, graph, visited);
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            printf("Graph is NOT connected.\n"); return 0;
        }
    }
    printf("Graph is connected.\n");
    return 0;
}
