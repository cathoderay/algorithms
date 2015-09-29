#include "helper.h"

int partition2_i(int a[], int p, int r) {
    int i = p,
        j = r + 1,
        v = a[p];

    //replacing with Hoare's partitioning
    while(true){
        while(a[++i] < v)
            if (i == r) break;

        while (v < a[--j])
            if (j == p) break;

        if (i >= j) break;

        swap_i(&a[i], &a[j]);
    }
    swap_i(&a[p], &a[j]);
    return j;
}

void quicksort2_i(int a[], int p, int r) {
    int q;
    if (p < r) {
        q = partition2_i(a, p, r);
        quicksort2_i(a, p, q - 1);
        quicksort2_i(a, q + 1, r);
    }
}

void quick2_i(int a[], int size) {
    //shuffling before
    shuffle_i(a, size);
    quicksort2_i(a, 0, size - 1);
}
