#include <iostream>
#include <cstdlib>

using namespace std;

#include "../sorts/sort.h"


void run_tests() {
    int passed = 0;
    int tests = 5;
    int n = 1000;
    int a[n];

    range(a, n);
    shuffle(a, n);
    if (check_if_sorts(selection, a, n)) passed++;
    if (check_if_sorts(insertion, a, n)) passed++;
    if (check_if_sorts(merge, a, n)) passed++;
    if (check_if_sorts(quick, a, n)) passed++;
    if (check_if_sorts(heap, a, n)) passed++;

    cout << "Passed: " << passed << "\n";
    cout << "Total: " << tests << "\n";
}

int main() {
    run_tests();
    return 0;
}
