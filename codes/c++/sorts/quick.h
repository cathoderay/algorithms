#include "helper.h"


int partition(int a[], int p, int r) {
    int x = a[r],
        i = p - 1;

    for(int j = p; j < r; j++) 
        if (a[j] <= x) {
            i = i + 1;
            swap(&a[i], &a[j]);
        } 
    swap(&a[i+1], &a[r]);
    return i + 1;
}

void quicksort(int a[], int p, int r) {
    int q;
    if (p < r) {
        q = partition(a, p, r);
        quicksort(a, p, q - 1);
        quicksort(a, q + 1, r);
    }
}

void quick(int a[], int size) {
    quicksort(a, 0, size - 1);
}
