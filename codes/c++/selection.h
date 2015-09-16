void selection(int v[], int length) {
    int k, t;
    for(int i = 0; i < length; i++) {
        k = i;
        for(int j = i + 1; j < length; j++)
            if (v[j] < v[k])
                k = j;
        t = v[k];
        v[k] = v[i];
        v[i] = t;
    }
}

