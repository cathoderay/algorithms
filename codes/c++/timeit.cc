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

void times(int type, int step) {
    cout << "n,selection,insertion,merge,quick,heap\n";
    for(int n = step; n <= 100000; n+= step){
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


int main(int argc, char *argv[]) {
    if (argc == 1) {
        cout << "Usage: timeit type [step]\n";
        cout << "types: 0-random,1-sorted,2-reversed,3-lot of rep.,4-few rep.\n";
        exit(-1);
    }
    else {
        int arg = atoi(argv[1]);
        if (arg < 0 || arg > 4) {
            cout << "Invalid argument.";
            exit(-1);
        }
        srand(time(NULL));
        if (argc == 3)
            times(arg, atoi(argv[2]));
        else
            times(arg, 10000);
    }

    return 0;
}
