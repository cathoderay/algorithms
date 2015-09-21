#include "helper.h"

void selection(int v[], int size) {
    int k;
    for(int i = 0; i < size; i++) {
        k = i;
        for(int j = i + 1; j < size; j++)
            if (v[j] < v[k])
                k = j;
        swap(&v[k], &v[i]);
    }
}
