/* Experiment 9: Find all subsets whose sum equals the target.
   Positive integers are expected, as specified in the lab sheet.
   Compile: gcc .\09_subset_sum.c -o subset_sum
   Run:     ./subset_sum.exe
*/
#include <stdio.h>
#define MAX 30

static int a[MAX], chosen[MAX], n, target, solutions = 0;

static void search(int index, int sum) {
    if (sum == target) {
        printf("{ ");
        for (int i = 0; i < n; ++i) if (chosen[i]) printf("%d ", a[i]);
        printf("}\n");
        ++solutions;
        return; /* Positive values mean adding more elements cannot keep this sum. */
    }
    if (index == n || sum > target) return;

    chosen[index] = 1;
    search(index + 1, sum + a[index]); /* Include current element. */
    chosen[index] = 0;
    search(index + 1, sum);            /* Exclude current element. */
}

int main(void) {
    printf("Enter number of positive integers (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid number of elements.\n"); return 1;
    }
    printf("Enter %d positive integers: ", n);
    for (int i = 0; i < n; ++i)
        if (scanf("%d", &a[i]) != 1 || a[i] <= 0) {
            printf("All values must be positive integers.\n"); return 1;
        }
    printf("Enter target sum: ");
    if (scanf("%d", &target) != 1 || target <= 0) {
        printf("Target must be a positive integer.\n"); return 1;
    }
    printf("Subsets with sum %d:\n", target);
    search(0, 0);
    if (!solutions) printf("No subset has the required sum.\n");
    else printf("Total solutions: %d\n", solutions);
    return 0;
}
