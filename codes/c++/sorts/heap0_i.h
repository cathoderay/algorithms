#include "helper.h"


int left_i(int i) { return 2*i + 1; }
int right_i(int i) { return 2*i + 2; }


void max_heapify0_i(int a[], int heapsize, int i) {
    int l = left_i(i), 
        r = right_i(i),
        largest;
    
    if (l < heapsize && a[l] > a[i])
        largest = l;
    else
        largest = i;
    if (r < heapsize && a[r] > a[largest])
        largest = r;
    
    if (largest != i) {
        swap_i(&a[i], &a[largest]);
        max_heapify0_i(a, heapsize, largest);
    }
}

void build_max_heap0_i(int a[], int size, int heapsize){
    heapsize = size;
    for(int i = (heapsize-1)/2; i >= 0; i--)
        max_heapify0_i(a, heapsize, i);
}

void heapsort0_i(int a[], int size, int heapsize) {
    build_max_heap0_i(a, size, heapsize);
    heapsize = size;
    for(int i = size - 1; i >= 0; i--) {
        swap_i(&a[0], &a[i]);
        heapsize--;
        max_heapify0_i(a, heapsize, 0);
    }
}


void heap0_i(int a[], int size) {
    heapsort0_i(a, size, 0);
}
