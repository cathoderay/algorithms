
void combine1_i(int a[], int t[], int s, int m, int e) {
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


void mergesort1_i(int a[], int t[], int s, int e) {
    if (s >= e) return;

    int m = s + (e - s)/2;
    mergesort1_i(a, t,  s, m);
    mergesort1_i(a, t, m + 1, e);
    combine1_i(a, t, s, m, e);
}


void merge1_i(int a[], int size) {
    int t[size];
    mergesort1_i(a, t, 0, size - 1);
}
