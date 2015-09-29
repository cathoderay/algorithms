#include <iostream>
#include <stdio.h>
#include <cstdlib>

using namespace std;

#include "../sorts/sort.h"

int main() {
    int n = 6;
    string a[] = {"Z", "zangão", "zangao", "abelha", "casa", "coelho"};
    print(a, n);
    insertion_to_quick(a, 0, n - 1);
    print(a, n);
    cout << is_sorted(a, n) << endl;

    n = 100;
    int b[n];
    range_i(b, n);
    shuffle(b, n);
    print(b, n);
    insertion_to_quick(b, 0, n - 1);
    print(b, n);
    cout << is_sorted(b, n) << endl;

    return 0;
}
