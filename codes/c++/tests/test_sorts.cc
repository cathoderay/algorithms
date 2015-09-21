#include <iostream>
#include <cstdlib>

using namespace std;

#include "../sorts/sort.h"


void run_tests() {
    int tests = 10;
    int passed = 0;

    //testing sorts for random seq of ints
    int n = 1000;
    int a[n];
    range(a, n);
    shuffle(a, n);
    if (check_if_sorts(selection, a, n)) passed++;
    if (check_if_sorts(insertion, a, n)) passed++;
    if (check_if_sorts(merge, a, n)) passed++;
    if (check_if_sorts(quick, a, n)) passed++;
    if (check_if_sorts(heap, a, n)) passed++;

    //testing sorts for strings
    n = 7;
    string b[] = {"z", "a", "ba", "aa", "bb", "de", "aa"};
    if (check_if_sorts_s(selection_s, b, n)) passed++;
    if (check_if_sorts_s(insertion_s, b, n)) passed++;
    if (check_if_sorts_s(merge_s, b, n)) passed++;
    if (check_if_sorts_s(quick_s, b, n)) passed++;
    if (check_if_sorts_s(heap_s, b, n)) passed++;

    cout << "Passed: " << passed << "\n";
    cout << "Total: " << tests << "\n";
}

int main() {
    run_tests();
    return 0;
}
