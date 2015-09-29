#include "helper.h"

void insertion0_i(int a[], int size) {
    for(int i = 0; i < size; i++){
        for(int j = i; j > 0; j--)  
            if (a[j] < a[j - 1])
                swap_i(&a[j], &a[j - 1]);
            else break;
    }
}
