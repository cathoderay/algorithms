template<typename T>
void insertion(T a[], int size) {
    T k;
    int i;
    for(int j = 1; j < size; j++) {
        k = a[j];
        i = j - 1;
        while (i > -1 && a[i] > k) {
            a[i + 1] = a[i];
            i--;
        }
        a[i + 1] = k;
    }
}
