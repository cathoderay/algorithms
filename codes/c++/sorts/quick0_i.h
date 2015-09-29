#include "helper.h"

int partition0_i(int a[], int p, int r) {
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

void quicksort0_i(int a[], int p, int r) {
    int q;
    if (p < r) {
        q = partition0_i(a, p, r);
        quicksort0_i(a, p, q - 1);
        quicksort0_i(a, q + 1, r);
    }
}

void quick0_i(int a[], int size) {
    quicksort0_i(a, 0, size - 1);
}
