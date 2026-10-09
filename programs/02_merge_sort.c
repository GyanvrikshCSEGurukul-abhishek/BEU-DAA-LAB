/* Experiment 2: Merge Sort and execution-time measurement
   Compile: gcc 02_merge_sort.c -o merge_sort
   Run:     ./merge_sort.exe
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static void merge(int a[], int temp[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right)
        temp[k++] = (a[i] <= a[j]) ? a[i++] : a[j++];
    while (i <= mid) temp[k++] = a[i++];
    while (j <= right) temp[k++] = a[j++];
    for (i = left; i <= right; ++i) a[i] = temp[i];
}

static void merge_sort(int a[], int temp[], int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    merge_sort(a, temp, left, mid);
    merge_sort(a, temp, mid + 1, right);
    merge(a, temp, left, mid, right);
}

int main(void) {
    int n;
    printf("Enter number of elements (1 to 1000000): ");
    if (scanf("%d", &n) != 1 || n < 1 || n > 1000000) {
        fprintf(stderr, "Invalid size.\n"); return 1;
    }
    int *a = malloc((size_t)n * sizeof *a);
    int *temp = malloc((size_t)n * sizeof *temp);
    if (!a || !temp) {
        fprintf(stderr, "Memory allocation failed.\n");
        free(a); free(temp); return 1;
    }
    srand((unsigned)time(NULL));
    for (int i = 0; i < n; ++i) a[i] = rand() % 100000;

    clock_t start = clock();
    merge_sort(a, temp, 0, n - 1);
    clock_t end = clock();

    printf("Sorted elements: ");
    if (n <= 100) {
        for (int i = 0; i < n; ++i) printf("%d ", a[i]);
    } else printf("(not printed because n > 100)");
    printf("\nCPU time: %.6f seconds\n",
           (double)(end - start) / CLOCKS_PER_SEC);
    free(a); free(temp);
    return 0;
}
