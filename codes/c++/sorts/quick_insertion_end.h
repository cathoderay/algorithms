#include "helper.h"

#define THRESHOLD_E 15

template<typename T>
int partition_ins_end(T a[], int p, int r) {
    //randomizing pivot
    int xp = p + rand() % (r - p + 1);
    swap(&a[xp], &a[p]);

    int i = p,
        j = r + 1;
    T   v = a[p];

    //Hoare
    while(true){
        while(a[++i] < v)
            if (i == r) break;

        while (v < a[--j])
            if (j == p) break;

        if (i >= j) break;

        swap(&a[i], &a[j]);
    }
    swap(&a[p], &a[j]);
    return j;
}

template<typename T>
void quicksort_ins_end(T a[], int p, int r) {
    int q;
    int n = r - p + 1;

    //skipping to solve later
    if (n <= THRESHOLD_E)
        return;
    if (p < r) {
        q = partition_ins_end(a, p, r);
        quicksort_ins_end(a, p, q - 1);
        quicksort_ins_end(a, q + 1, r);
    }
}

template<typename T>
void quick_insertion_end(T a[], int size) {
    quicksort_ins_end(a, 0, size - 1);
    insertion(a, size);
}
