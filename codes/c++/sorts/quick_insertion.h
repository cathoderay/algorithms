#include "helper.h"

#define THRESHOLD 15

template<typename T>
void insertion_to_quick(T a[], int s, int e) { 
    int i;
    T k;
    for(int j = s + 1; j <= e; j++) {
        k = a[j];
        i = j - 1;
        while (i >= s && a[i] > k) {
            a[i + 1] = a[i];
            i--;
        }
        a[i + 1] = k;
    }
}

template<typename T>
int partition_ins(T a[], int p, int r) {
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
void quicksort_ins(T a[], int p, int r) {
    int q;
    int n = r - p + 1;

    //skipping to insertion
    if (n <= THRESHOLD)
        insertion_to_quick(a, p, r);
    else if (p < r) {
        q = partition_ins(a, p, r);
        quicksort_ins(a, p, q - 1);
        quicksort_ins(a, q + 1, r);
    }
}

template<typename T>
void quick_insertion(T a[], int size) {
    quicksort_ins(a, 0, size - 1);
}
