#include "helper.h"

int partition1_i(int a[], int p, int r) {
    int x = a[r],
        i = p - 1;

    //Lomuto
    for(int j = p; j < r; j++) 
        if (a[j] <= x) {
            i = i + 1;
            swap_i(&a[i], &a[j]);
        } 
    swap_i(&a[i+1], &a[r]);
    return i + 1;
}

void quicksort1_i(int a[], int p, int r) {
    int q;
    if (p < r) {
        q = partition1_i(a, p, r);
        quicksort1_i(a, p, q - 1);
        quicksort1_i(a, q + 1, r);
    }
}

void quick1_i(int a[], int size) {
    //now shuffling before
    shuffle_i(a, size);
    quicksort1_i(a, 0, size - 1);
}
