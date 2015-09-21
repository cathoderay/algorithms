#include "helper.h"


int left_s(int i) { return 2*i + 1; }
int right_s(int i) { return 2*i + 2; }


void max_heapify_s(string a[], int heapsize, int i) {
    int l = left_s(i), 
        r = right_s(i),
        largest;
    
    if (l < heapsize && a[l] > a[i])
        largest = l;
    else
        largest = i;
    if (r < heapsize && a[r] > a[largest])
        largest = r;
    
    if (largest != i) {
        swap_s(&a[i], &a[largest]);
        max_heapify_s(a, heapsize, largest);
    }
}

void build_max_heap_s(string a[], int size, int heapsize){
    heapsize = size;
    for(int i = (heapsize-1)/2; i >= 0; i--)
        max_heapify_s(a, heapsize, i);
}

void heapsort_s(string a[], int size, int heapsize) {
    build_max_heap_s(a, size, heapsize);
    heapsize = size;
    for(int i = size - 1; i >= 0; i--) {
        swap_s(&a[0], &a[i]);
        heapsize--;
        max_heapify_s(a, heapsize, 0);
    }
}


void heap_s(string a[], int size) {
    heapsort_s(a, size, 0);
}
