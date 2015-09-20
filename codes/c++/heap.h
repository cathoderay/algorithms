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
        int t;
        t = a[i];
        a[i] = a[largest];
        a[largest] = t;
        max_heapify(a, heapsize, largest);
    }
}

void build_max_heap(int a[], int size, int heapsize){
    heapsize = size;
    for(int i = (heapsize-1)/2; i >= 0; i--)
        max_heapify(a, heapsize, i);
}

void heapsort(int a[], int size, int heapsize) {
    int t;
    build_max_heap(a, size, heapsize);
    heapsize = size;
    for(int i = size - 1; i >= 0; i--) {
        t = a[0];
        a[0] = a[i];
        a[i] = t;
        heapsize--;
        max_heapify(a, heapsize, 0);
    }
}


void heap(int a[], int size) {
    heapsort(a, size, 0);
}
