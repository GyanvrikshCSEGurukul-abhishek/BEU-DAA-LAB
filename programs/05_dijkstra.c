/* Experiment 5: Dijkstra shortest paths
   Enter a weighted adjacency matrix. Use 0 for no edge, positive weights
   for edges, and 0 on the diagonal. Edge weights must be non-negative.
   Compile: gcc .\05_dijkstra.c -o dijkstra
   Run:     ./dijkstra.exe
*/
#include <stdio.h>
#include <limits.h>
#define MAX 100
#define INF (LLONG_MAX / 4)

int main(void) {
    int n, source, graph[MAX][MAX], used[MAX] = {0};
    long long dist[MAX];
    printf("Enter number of vertices (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid number of vertices.\n"); return 1;
    }
    printf("Enter weighted adjacency matrix (0 means no edge) :\n");
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            if (scanf("%d", &graph[i][j]) != 1 || graph[i][j] < 0) {
                printf("Invalid input; weights must be non-negative.\n"); return 1;
            }
        }
    printf("Enter source vertex (1-%d): ", n);
    if (scanf("%d", &source) != 1 || source < 1 || source > n) {
        printf("Invalid source.\n"); return 1;
    }
    --source;
    for (int i = 0; i < n; ++i) dist[i] = INF;
    dist[source] = 0;

    for (int count = 0; count < n; ++count) {
        int u = -1;
        for (int i = 0; i < n; ++i)
            if (!used[i] && (u == -1 || dist[i] < dist[u])) u = i;
        if (u == -1 || dist[u] == INF) break; /* Remaining vertices are unreachable. */
        used[u] = 1;
        for (int v = 0; v < n; ++v) {
            if (!used[v] && graph[u][v] > 0 && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }
    printf("Shortest distances from vertex %d:\n", source + 1);
    for (int i = 0; i < n; ++i) {
        if (dist[i] == INF) printf("To %d: unreachable\n", i + 1);
        else printf("To %d: %lld\\n", i + 1, dist[i]);
    }
    return 0;
}
