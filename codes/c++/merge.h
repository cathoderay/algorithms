#define INFINITE 1000000000


void combine(int a[], int s, int m, int e) {
    int i, j;
    int ls = m - s + 1;
    int rs = e - m;
    int l[ls + 1], r[rs + 1];

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


void mergesort(int a[], int s, int e) {
    if (s >= e) return;

    int m = s + (e - s)/2;
    mergesort(a, s, m);
    mergesort(a, m + 1, e);
    combine(a, s, m, e);
}


void merge(int a[], int size) {
    mergesort(a, 0, size - 1);
}

