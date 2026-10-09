/* Experiment 6: Minimum Spanning Tree using Kruskal's algorithm
   Enter an undirected weighted graph as an edge list.
   Compile: gcc .\06_kruskal.c -o kruskal
   Run:     ./kruskal.exe
*/
#include <stdio.h>
#include <stdlib.h>
#define MAXV 100
#define MAXE 5000

typedef struct { int u, v, w; } Edge;
static int parent[MAXV], rankv[MAXV];

static int compare_edges(const void *a, const void *b) {
    const Edge *x = (const Edge *)a, *y = (const Edge *)b;
    return (x->w > y->w) - (x->w < y->w);
}
static int find_root(int x) {
    if (parent[x] != x) parent[x] = find_root(parent[x]);
    return parent[x];
}
static int unite(int a, int b) {
    a = find_root(a); b = find_root(b);
    if (a == b) return 0;
    if (rankv[a] < rankv[b]) parent[a] = b;
    else if (rankv[a] > rankv[b]) parent[b] = a;
    else { parent[b] = a; ++rankv[a]; }
    return 1;
}

int main(void) {
    int n, m, chosen = 0;
    long long total = 0;
    Edge edges[MAXE];
    printf("Enter vertices and edges (vertices 1-%d, edges 0-%d): ", MAXV, MAXE);
    if (scanf("%d%d", &n, &m) != 2 || n < 1 || n > MAXV || m < 0 || m > MAXE) {
        printf("Invalid graph size.\n"); return 1;
    }
    for (int i = 0; i < m; ++i) {
        printf("Enter edge %d (u v weight): ", i + 1);
        if (scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].w) != 3 ||
            edges[i].u < 1 || edges[i].u > n || edges[i].v < 1 ||
            edges[i].v > n || edges[i].u == edges[i].v) {
            printf("Invalid edge.\n"); return 1;
        }
        --edges[i].u; --edges[i].v;
    }
    for (int i = 0; i < n; ++i) { parent[i] = i; rankv[i] = 0; }
    qsort(edges, (size_t)m, sizeof edges[0], compare_edges);

    printf("Edges in the minimum spanning tree:\n");
    for (int i = 0; i < m && chosen < n - 1; ++i) {
        if (unite(edges[i].u, edges[i].v)) {
            printf("%d -- %d (weight %d)\n", edges[i].u + 1, edges[i].v + 1, edges[i].w);
            total += edges[i].w; ++chosen;
        }
    }
    if (chosen != n - 1) printf("Graph is disconnected; no spanning tree exists.\n");
    else printf("Total MST cost = %lld\n", total);
    return 0;
}
