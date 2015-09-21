#define INFINITE_S "zzzzzzzzzzzzzzzzzzzzzzzzzzzz"


void combine_s(string a[], int s, int m, int e) {
    int i, j,
        ls = m - s + 1,
        rs = e - m;
    string l[ls + 1],
           r[rs + 1];

    for(int i = 0; i < ls; i++)
        l[i] = a[s + i];

    for(int i = 0; i < rs; i++)
        r[i] = a[m + 1 + i];
    
    l[ls] = r[rs] = INFINITE_S;
    i = j = 0;
    for(int k = s; k <= e; k++)
        if (l[i] <= r[j])
            a[k] = l[i++];
        else
            a[k] = r[j++];
}


void mergesort_s(string a[], int s, int e) {
    if (s >= e) return;

    int m = s + (e - s)/2;
    mergesort_s(a, s, m);
    mergesort_s(a, m + 1, e);
    combine_s(a, s, m, e);
}


void merge_s(string a[], int size) {
    mergesort_s(a, 0, size - 1);
}
