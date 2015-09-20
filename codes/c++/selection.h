void selection(int v[], int size) {
    int k, t;
    for(int i = 0; i < size; i++) {
        k = i;
        for(int j = i + 1; j < size; j++)
            if (v[j] < v[k])
                k = j;
        t = v[k];
        v[k] = v[i];
        v[i] = t;
    }
}
