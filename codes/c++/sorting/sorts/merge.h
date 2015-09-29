template<typename T>
void combine(T a[], T t[], int s, int m, int e) {
    for(int k = s; k <= e; k++)
        t[k] = a[k];
    
    int i = s, j = m + 1;
    for(int k = s; k <= e; k++) {
        if (j > e) 
            a[k] = t[i++];
        else if (i > m)
            a[k] = t[j++];
        else if (t[j] < t[i])
            a[k] = t[j++];
        else
            a[k] = t[i++];
    }
}


template<typename T>
void mergesort(T a[], T t[], int s, int e) {
    if (s >= e) return;

    int m = s + (e - s)/2;
    mergesort(a, t,  s, m);
    mergesort(a, t, m + 1, e);
    combine(a, t, s, m, e);
}

template<typename T>
void merge(T a[], int size) {
    T t[size];
    mergesort(a, t, 0, size - 1);
}
