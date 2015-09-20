#include "helper.h"


int left(int i) { return 2*i + 1; }
int right(int i) { return 2*i + 2; }


void max_heapify(int a[], int heapsize, int i) {
    int l = left(i), 
        r = right(i),
        largest;
    
    if (l < heapsize && a[l] > a[i])
        largest = l;
    else
        largest = i;

    if (r < heapsize && a[r] > a[largest])
        largest = r;
    
    if (largest != i) {
        swap(&a[i], &a[largest]);
        max_heapify(a, heapsize, largest);
    }
}

void build_max_heap(int a[], int size, int heapsize){
    heapsize = size;
    for(int i = (heapsize-1)/2; i >= 0; i--)
        max_heapify(a, heapsize, i);
}

void heapsort(int a[], int size, int heapsize) {
    build_max_heap(a, size, heapsize);
    heapsize = size;
    for(int i = size - 1; i >= 0; i--) {
        swap(&a[0], &a[i]);
        heapsize--;
        max_heapify(a, heapsize, 0);
    }
}


void heap(int a[], int size) {
    heapsort(a, size, 0);
}
