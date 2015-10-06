#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

using namespace std;

#include "sorts/sort.h"

int main() {
    string s;
    vector<string> a;

    while(cin >> s)
        a.push_back(s);

    cout << timeit_s(selection, &a[0], a.size()) << ',';
    cout << timeit_s(insertion, &a[0], a.size()) << ',';
    cout << timeit_s(heap, &a[0], a.size()) << ',';
    cout << timeit_s(merge, &a[0], a.size()) << ',';
    cout << timeit_s(merge_insertion, &a[0], a.size()) << ',';
    cout << timeit_s(quick, &a[0], a.size()) << ',';
    cout << timeit_s(quick_insertion, &a[0], a.size()) << ',';
    cout << timeit_s(quick_insertion_end, &a[0], a.size()) << '\n';


    return 0;
}
