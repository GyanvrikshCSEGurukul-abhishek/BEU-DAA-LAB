/* Experiment 1: Quick Sort and execution-time measurement
   Compile: gcc 01_quick_sort.c -o quick_sort
   Run:     .\quick_sort.exe
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static void swap(int *a, int *b) { int t = *a; *a = *b; *b = t; }

/* Partition FUnction: places the pivot at its correct sorted position. */
static int partition(int a[], int low, int high) {
    int pivot = a[high], i = low - 1;
    for (int j = low; j < high; ++j) {
        if (a[j] <= pivot) { ++i; swap(&a[i], &a[j]); }
    }
    swap(&a[i + 1], &a[high]);
    return i + 1;
}

static void quick_sort(int a[], int low, int high) {
    if (low < high) {
        int p = partition(a, low, high);
        quick_sort(a, low, p - 1);
        quick_sort(a, p + 1, high);
    }
}

int main(void) {
    int n;
    printf("Enter number of elements (1 to 100000): ");
    if (scanf("%d", &n) != 1 || n < 1 || n > 100000) {
        fprintf(stderr, "Invalid size.\n"); return 1;
    }
    int *a = malloc((size_t)n * sizeof *a);
    if (!a) { fprintf(stderr, "Memory allocation failed.\n"); return 1; }

    srand((unsigned)time(NULL));
    for (int i = 0; i < n; ++i) a[i] = rand() % 100000;
    printf("Generated %d random integers. \n", n);

    clock_t start = clock();
    quick_sort(a, 0, n - 1);
    clock_t end = clock();

    printf("Sorted elements: ");
    if (n <= 100) {
        for (int i = 0; i < n; ++i) printf("%d ", a[i]);
    } else {
        printf("(not printed because n > 100)");
    }
    printf("\nCPU time: %.6f seconds\n",
           (double)(end - start) / CLOCKS_PER_SEC);
    free(a);
    return 0;
}
