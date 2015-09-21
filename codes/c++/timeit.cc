#include <iostream>
#include <time.h>
#include <stdio.h>

using namespace std;

#include "sorts/sort.h"


void generate_nums(int a[], int type, int n) {
    switch (type) {
        case 0: //random sequences
            range(a, n);
            shuffle(a, n);
            break;
        case 1: //sorted
            range(a, n);
            break;
        case 2: //reversed
            reverse(a, n);
            break;
        case 3: //lot of repetitions
            randrept(a, n, 0.8);
            break;
        case 4: //few repetitions
            randrept(a, n, 0.2);
            break;
    }
}

void times(int type, int start, int end, int step) {
    srand(time(NULL));
    cout << "n,selection,insertion,merge,quick,heap\n";
    for(int n = start; n <= end; n+= step){
        int a[n];

        generate_nums(a, type, n);

        cout << n << ',';
        cout << timeit(selection, a, n) << ',';
        cout << timeit(insertion, a, n) << ',';
        cout << timeit(merge, a, n) << ',';
        cout << timeit(quick, a, n) << ',';
        cout << timeit(heap, a, n) << '\n';
    }
}

void usage() {
    cout << "Usage: timeit TYPE START END STEP\n";
    cout << "TYPE: \n\t0-random\n\t1-sorted\n\t2-reversed\n\t3-lot of rep.\n\t4-few rep.\n";
    cout << "START: starts with inputs of size START\n";
    cout << "END: ends with inputs of size END\n";
    cout << "STEP: increase size of inputs by STEP\n";
    cout << "e.g.: ./timeit 0 100 1000 100\n";
    exit(-1);
}


int main(int argc, char *argv[]) {
    if (argc == 1)
        usage();
    else if (argc > 5) {
        cout << "Invalid number of arguments.";
        exit(-1);
    }
    else if (argc == 5)
        times(atoi(argv[1]), 
              atoi(argv[2]), 
              atoi(argv[3]), 
              atoi(argv[4]));

    return 0;
}
