#include <iostream>
#include <time.h>
#include <stdio.h>

using namespace std;

#include "helper.h"
#include "insertion.h"
#include "selection.h"
#include "merge.h"
#include "qsort.h"
#include "heap.h"


void time() {
    for(int n = 100; n <= 100000; n+= 100){
        int a[n];

        srand(time(NULL));
        range(a, n);
        shuffle(a, n);

        cout << n << ',';
        cout << timeit(insertion, a, n) << ',';
        cout << timeit(selection, a, n) << ',';
        cout << timeit(merge, a, n) << ',';
        cout << timeit(qsort, a, n) << ',';
        cout << timeit(heap, a, n) << '\n';
    }
}


int main() {
    time();

    return 0;
}
