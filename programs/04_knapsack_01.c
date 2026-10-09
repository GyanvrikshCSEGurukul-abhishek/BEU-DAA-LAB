/* Experiment 4: 0/1 Knapsack using Dynamic Programming
   Each item is either selected once or not selected.
   Compile: gcc .\04_knapsack_01.c -o knapsack_01
   Run:     ./knapsack_01.exe
*/
#include <stdio.h>
#define MAX_ITEMS 100
#define MAX_CAPACITY 10000

int main(void) {
    int n, capacity, weight[MAX_ITEMS + 1], value[MAX_ITEMS + 1];
    static int dp[MAX_ITEMS + 1][MAX_CAPACITY + 1];

    printf("Enter number of items (1-%d): ", MAX_ITEMS);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX_ITEMS) {
        printf("Invalid number of items.\n"); return 1;
    }
    printf("Enter capacity (0-%d): ", MAX_CAPACITY);
    if (scanf("%d", &capacity) != 1 || capacity < 0 || capacity > MAX_CAPACITY) {
        printf("Invalid capacity.\n"); return 1;
    }
    for (int i = 1; i <= n; ++i) {
        printf("Enter weight and value of item %d: ", i);
        if (scanf("%d%d", &weight[i], &value[i]) != 2 ||
            weight[i] < 0 || value[i] < 0) {
            printf("Weights and values must be non-negative integers.\n"); return 1;
        }
    }

    /* dp[i][w] = maximum value using first i items and capacity w. */
    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= capacity; ++w) {
            dp[i][w] = dp[i - 1][w]; /* Exclude item i. */
            if (weight[i] <= w) {
                int take = value[i] + dp[i - 1][w - weight[i]];
                if (take > dp[i][w]) dp[i][w] = take;
            }
        }
    }
    printf("Maximum obtainable value = %d\n", dp[n][capacity]);

    printf("Selected item numbers: ");
    int w = capacity, found = 0;
    for (int i = n; i >= 1; --i) {
        if (dp[i][w] != dp[i - 1][w]) {
            printf("%d ", i); found = 1; w -= weight[i];
        }
    }
    if (!found) printf("none");
    printf("\n");
    return 0;
}
