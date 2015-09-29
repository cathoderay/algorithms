#include "helper.h"

template<typename T>
void selection(T a[], int size) {
    int k;
    for(int i = 0; i < size; i++) {
        k = i;
        for(int j = i + 1; j < size; j++)
            if (a[j] < a[k])
                k = j;
        swap(&a[k], &a[i]);
    }
}
