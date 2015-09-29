#define THRESHOLD_M  15

template<typename T>
void insertion_to_merge(T a[], int s, int e) { 
    int i;
    T k;
    for(int j = s + 1; j <= e; j++) {
        k = a[j];
        i = j - 1;
        while ((i + 1) > s && a[i] > k) {
            a[i + 1] = a[i];
            i--;
        }
        a[i + 1] = k;
    }
}

template<typename T>
void combine_ins(T a[], T t[], int s, int m, int e) {
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
void mergesort_ins(T a[], T t[], int s, int e) {
    if (s >= e) return;

    if ((e - s + 1) <= THRESHOLD_M) {
        insertion_to_merge(a, s, e);
        return;
    }

    int m = s + (e - s)/2;
    mergesort_ins(a, t,  s, m);
    mergesort_ins(a, t, m + 1, e);
    combine_ins(a, t, s, m, e);
}

template<typename T>
void merge_insertion(T a[], int size) {
    T t[size];
    mergesort_ins(a, t, 0, size - 1);
}
