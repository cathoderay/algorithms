#include "helper.h"

template<typename T>
int partition(T a[], int p, int r) {
    int xp = p + rand() % (r - p + 1);
    swap(&a[xp], &a[p]);

    int i = p,
        j = r + 1;
    T   v = a[p];

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
void quicksort(T a[], int p, int r) {
    int q;
    if (p < r) {
        q = partition(a, p, r);
        quicksort(a, p, q - 1);
        quicksort(a, q + 1, r);
    }
}

template<typename T>
void quick(T a[], int size) {
    quicksort(a, 0, size - 1);
}
