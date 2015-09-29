#define INFINITE 1000000000


void combine0_i(int a[], int s, int m, int e) {
    int i, j,
        ls = m - s + 1,
        rs = e - m,
        l[ls + 1],
        r[rs + 1];

    for(int i = 0; i < ls; i++)
        l[i] = a[s + i];

    for(int i = 0; i < rs; i++)
        r[i] = a[m + 1 + i];
    
    l[ls] = r[rs] = INFINITE;
    i = j = 0;
    for(int k = s; k <= e; k++)
        if (l[i] <= r[j])
            a[k] = l[i++];
        else
            a[k] = r[j++];
}


void mergesort0_i(int a[], int s, int e) {
    if (s >= e) return;

    int m = s + (e - s)/2;
    mergesort0_i(a, s, m);
    mergesort0_i(a, m + 1, e);
    combine0_i(a, s, m, e);
}


void merge0_i(int a[], int size) {
    mergesort0_i(a, 0, size - 1);
}
