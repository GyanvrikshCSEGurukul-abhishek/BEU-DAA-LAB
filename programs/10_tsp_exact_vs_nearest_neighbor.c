/* Experiment 10: Exact TSP solution and approximation comparison.
   Exact method: brute force over permutations, suitable only for small n.
   Approximation: nearest-neighbour heuristic.
   Enter a complete, symmetric distance matrix with positive off-diagonal
   distances and zero diagonal. Vertices are numbered 1..n.
   Compile: gcc .\10_tsp_exact_vs_nearest_neighbor.c -o tsp_exact_vs_nearest_neighbor
   Run:     ./tsp_exact_vs_nearest_neighbor.exe
*/
#include <stdio.h>
#include <limits.h>
#define MAX 10
#define INF (LLONG_MAX / 4)

static int n, cost[MAX][MAX], used[MAX];
static long long best = INF;
static int best_path[MAX], path[MAX];

static void permute(int depth, int current, long long total) {
    if (total >= best) return; /* Safe pruning because distances are non-negative. */
    if (depth == n) {
        long long full = total + cost[current][0]; /* Return to starting city 1. */
        if (full < best) {
            best = full;
            for (int i = 0; i < n; ++i) best_path[i] = path[i];
        }
        return;
    }
    for (int next = 1; next < n; ++next) {
        if (!used[next]) {
            used[next] = 1; path[depth] = next;
            permute(depth + 1, next, total + cost[current][next]);
            used[next] = 0;
        }
    }
}

int main(void) {
    printf("Enter number of cities (2-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 2 || n > MAX) {
        printf("Invalid number of cities.\n"); return 1;
    }
    printf("Enter %d x %d distance matrix (symmetric, diagonal 0):\n", n, n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            if (scanf("%d", &cost[i][j]) != 1 || cost[i][j] < 0) {
                printf("Distances must be non-negative integers.\n"); return 1;
            }
        }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (cost[i][j] != cost[j][i] || (i == j && cost[i][j] != 0)) {
                printf("Matrix must be symmetric with zero diagonal.\n"); return 1;
            }

    used[0] = 1; path[0] = 0;
    permute(1, 0, 0);
    printf("Exact optimal tour: ");
    for (int i = 0; i < n; ++i) printf("%d -> ", best_path[i] + 1);
    printf("1\nExact optimal cost = %lld\n", best);

    /* Nearest neighbour: repeatedly visit the closest unvisited city. */
    int seen[MAX] = {0}, current = 0;
    long long approx = 0;
    printf("Nearest-neighbour tour: 1");
    seen[0] = 1;
    for (int step = 1; step < n; ++step) {
        int next = -1;
        for (int j = 0; j < n; ++j)
            if (!seen[j] && (next == -1 || cost[current][j] < cost[current][next]))
                next = j;
        approx += cost[current][next];
        current = next; seen[current] = 1;
        printf(" -> %d", current + 1);
    }
    approx += cost[current][0];
    printf(" -> 1\nApproximate cost = %lld\n", approx);
    printf("Absolute error = %lld\n", approx - best);
    if (best != 0)
        printf("Relative error = %.2f%%\n", 100.0 * (double)(approx - best) / (double)best);
    else printf("Relative error undefined because optimal cost is zero.\n");
    return 0;
}
