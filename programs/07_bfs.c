/* Experiment 7: Print vertices reachable from a start vertex using BFS.
   Input is a directed graph adjacency matrix; vertices are numbered 1..n.
   Compile: gcc .\07_bfs.c -o bfs
   Run:     ./bfs.exe
*/
#include <stdio.h>
#define MAX 100

int main(void) {
    int n, graph[MAX][MAX], visited[MAX] = {0}, queue[MAX];
    int source, front = 0, rear = 0;
    printf("Enter number of vertices (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid number of vertices.\n"); return 1;
    }
    printf("Enter adjacency matrix (0/1):\n");
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (scanf("%d", &graph[i][j]) != 1) {
                printf("Invalid matrix.\n"); return 1;
            }
    printf("Enter starting vertex (1-%d): ", n);
    if (scanf("%d", &source) != 1 || source < 1 || source > n) {
        printf("Invalid starting vertex.\n"); return 1;
    }
    --source; queue[rear++] = source; visited[source] = 1;
    printf("Reachable vertices in BFS order: ");
    while (front < rear) {
        int u = queue[front++];
        printf("%d ", u + 1);
        for (int v = 0; v < n; ++v)
            if (graph[u][v] && !visited[v]) {
                visited[v] = 1;
                queue[rear++] = v;
            }
    }
    printf("\n");
    return 0;
}
