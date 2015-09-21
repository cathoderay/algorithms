#include "helper.h"

int partition_s(string a[], int p, int r) {
    string x = a[r];
    int i = p - 1;

    for(int j = p; j < r; j++) 
        if (a[j] <= x) {
            i = i + 1;
            swap_s(&a[i], &a[j]);
        } 
    swap_s(&a[i+1], &a[r]);
    return i + 1;
}

void quicksort_s(string a[], int p, int r) {
    int q;
    if (p < r) {
        q = partition_s(a, p, r);
        quicksort_s(a, p, q - 1);
        quicksort_s(a, q + 1, r);
    }
}

void quick_s(string a[], int size) {
    quicksort_s(a, 0, size - 1);
}
