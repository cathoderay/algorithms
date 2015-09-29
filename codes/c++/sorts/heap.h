#include "helper.h"

int left(int i) { return 2*i + 1; }
int right(int i) { return 2*i + 2; }

template<typename T>
void max_heapify(T a[], int hsize, int i) {
    int l = left(i), 
        r = right(i),
        max;
    
    if (l < hsize && a[l] > a[i]) max = l;
    else max = i;
    if (r < hsize && a[r] > a[max]) max = r;
    
    if (max != i) {
        swap(&a[i], &a[max]);
        max_heapify(a, hsize, max);
    }
}

template<typename T>
void build_max_heap(T a[], int size, int hsize){
    hsize = size;
    for(int i = (hsize-1)/2; i >= 0; i--)
        max_heapify(a, hsize, i);
}

template<typename T>
void heapsort(T a[], int size, int hsize) {
    build_max_heap(a, size, hsize);
    hsize = size;
    for(int i = size - 1; i >= 0; i--) {
        swap(&a[0], &a[i]);
        hsize--;
        max_heapify(a, hsize, 0);
    }
}

template<typename T>
void heap(T a[], int size) {
    heapsort(a, size, 0);
}
