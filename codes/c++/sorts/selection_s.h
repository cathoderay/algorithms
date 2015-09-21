#include "helper.h"

void selection_s(string a[], int size) {
    int k;
    for(int i = 0; i < size; i++) {
        k = i;
        for(int j = i + 1; j < size; j++)
            if (a[j] < a[k])
                k = j;
        swap_s(&a[k], &a[i]);
    }
}
