void insertion(int v[], int size) {
    int k, i;
    for(int j = 1; j < size; j++) {
        k = v[j];
        i = j - 1;
        while (i > -1 && v[i] > k) {
            v[i + 1] = v[i];
            i--;
        }
        v[i + 1] = k;
    }
}
