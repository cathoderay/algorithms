#include <iostream>
#include <cstdlib>

using namespace std;

#include "../sorts/helper.h"


bool test_swap() {
    int a = 1, b = 2;
    swap(&a, &b);
    return b == 1 && a == 2;
}


bool test_is_not_sorted() {
    int a[] = {3, 2, 1};
    return !(is_sorted(a, 3));
}


bool test_is_sorted() {
    int a[] = {1, 2, 3};
    return is_sorted(a, 3);
}


bool test_copy() {
   int a[] = {5, 6, 20};
   int b[3];
   copy(b, a, 3);
   return (b[0] == 5 && 
           b[1] == 6 && 
           b[2] == 20 && 
           b!=a);
}


bool test_reverse() {
    int b[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int a[10];
    reverse(a, 10);
    for(int i= 0; i < 10; i++) 
        if (b[i] != a[i])
            return false;
    return true;
}


void test() {
    int tests = 5;
    int passed = 0;

    if (test_swap()) passed++;
    if (test_is_not_sorted()) passed++;
    if (test_is_sorted()) passed++;
    if (test_copy()) passed++;
    if (test_reverse()) passed++;

    cout << "Passed: " << passed << "\n";
    cout << "Total: " << tests << "\n";
}


int main() {
    test();
    return 0;
}
