#include <iostream>
#include <time.h>
#include <stdio.h>

#include "helper.h"
#include "insertion.h"
#include "selection.h"


void time() {
    for(int n = 10; n <= 100000; n+= 100){ 
        int a[n], b[n];

        srand(time(NULL));

        shuffle_array(a, n);
        copy_array(b, a, n);

        std::cout << n << ',';
        std::cout << timeit(insertion, a, n) << ',';
        std::cout << timeit(selection, b, n) << '\n';
    }
}


int main() {
    time();
    return 0;
}
