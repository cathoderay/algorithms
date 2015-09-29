#include "helper.h"

int partition3_i(int a[], int p, int r) {
    //randomizing pivot
    int xp = p + rand() % (r - p + 1);
    swap_i(&a[xp], &a[p]);

    int i = p,
        j = r + 1,
        v = a[p];

    //Hoare
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

void quicksort3_i(int a[], int p, int r) {
    int q;
    if (p < r) {
        q = partition3_i(a, p, r);
        quicksort3_i(a, p, q - 1);
        quicksort3_i(a, q + 1, r);
    }
}

void quick3_i(int a[], int size) {
    quicksort3_i(a, 0, size - 1);
}
