#include <iostream>
#include <cstdlib>

using namespace std;

#include "../sorts/sort.h"


void run_tests() {
    int t = 27;
    int p = 0;

    //testing sorts for random seq of ints
    int n = 1000;
    int a[n];
    range_i(a, n);
    shuffle_i(a, n);

    if (check_if_sorts_i(selection_i, a, n))         p++; 
    if (check_if_sorts_i(selection, a, n))           p++; 

    if (check_if_sorts_i(insertion0_i, a, n))        p++; 
    if (check_if_sorts_i(insertion1_i, a, n))        p++; 
    if (check_if_sorts_i(insertion, a, n))           p++; 

    if (check_if_sorts_i(merge0_i, a, n))            p++; 
    if (check_if_sorts_i(merge1_i, a, n))            p++; 
    if (check_if_sorts_i(merge, a, n))               p++; 
    if (check_if_sorts_i(merge_insertion, a, n))     p++; 

    if (check_if_sorts_i(quick0_i, a, n))            p++; 
    if (check_if_sorts_i(quick1_i, a, n))            p++; 
    if (check_if_sorts_i(quick2_i, a, n))            p++; 
    if (check_if_sorts_i(quick3_i, a, n))            p++; 
    if (check_if_sorts_i(quick, a, n))               p++; 
    if (check_if_sorts_i(quick_insertion, a, n))     p++; 
    if (check_if_sorts_i(quick_insertion_end, a, n)) p++; 

    if (check_if_sorts_i(heap0_i, a, n))             p++; 
    if (check_if_sorts_i(heap, a, n))                p++; 


    //testing sorts for strings
    n = 7;
    string b[] = {"z", "a", "ba", "aa", "bb", "de", "aa"};
    if (check_if_sorts_s(selection, b, n))           p++;

    if (check_if_sorts_s(insertion, b, n))           p++;

    if (check_if_sorts_s(merge0_s, b, n))            p++;
    if (check_if_sorts_s(merge, b, n))               p++; 
    if (check_if_sorts_s(merge_insertion, b, n))     p++; 
    
    if (check_if_sorts_s(quick, b, n))               p++;
    if (check_if_sorts_s(quick_insertion, b, n))     p++;
    if (check_if_sorts_s(quick_insertion_end, b, n)) p++; 

    if (check_if_sorts_s(heap, b, n))                p++;

    cout << "Passed: " << p << "\n";
    cout << "Total: " << t << "\n";
}

int main() {
    run_tests();
    return 0;
}
