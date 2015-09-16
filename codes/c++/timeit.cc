#include <iostream>
#include <time.h>
#include <stdio.h>

#include "helper.h"
#include "insertion.h"
#include "selection.h"
#include "merge.h"
#include "qsort.h"
#include "heap.h"


void time() {
    for(int n = 10; n <= 100000; n+= 100){ 
        int a[n];

        srand(time(NULL));

        shuffle_array(a, n);

        std::cout << n << ',';

        std::cout << timeit(insertion, a, n) << ',';
        std::cout << timeit(selection, a, n) << ',';
        std::cout << timeit(merge, a, n) << ',';
        std::cout << timeit(qsort, a, n) << ',';
        std::cout << timeit(heap, a, n) << '\n';

    }
}


int main() {
    time();
    return 0;
}
