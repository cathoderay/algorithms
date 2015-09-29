#include <iostream>
#include <cstdlib>

using namespace std;

#include "../sorts/helper.h"


bool test_swap_i() {
    int a = 1, b = 2;
    swap(&a, &b);
    return b == 1 && a == 2;
}

bool test_swap() {
    //works for int
    int a = 1, b = 2;
    swap(&a, &b);
    bool v = (b == 1 && a == 2);

    //works for strings
    string c = "foo", d = "bar";
    swap(&c, &d);
    v &= (c == "bar" && d == "foo");
    return v;
}

bool test_is_not_sorted_i() {
    int a[] = {3, 2, 1};
    return !(is_sorted_i(a, 3));
}

bool test_is_sorted_i() {
    int a[] = {1, 2, 3};
    return is_sorted_i(a, 3);
}

bool test_is_not_sorted() {
    //works for int
    int a[] = {5, 2, 3};
    bool v = !(is_sorted(a, 3));

    //works for strings
    string b[] = {"c", "b", "a"};
    v &= !(is_sorted(b, 3));
    return v;
}

bool test_is_sorted() {
    //works for int
    int a[] = {1, 2, 3};
    bool v = is_sorted(a, 3);

    //works for strings
    string b[] = {"a", "b", "c"};
    v &= (is_sorted(b, 3));
    return v;
}

bool test_copy_i() {
   int a[] = {5, 6, 20};
   int b[3];
   copy_i(b, a, 3);
   return (b[0] == 5 && 
           b[1] == 6 && 
           b[2] == 20 && 
           b!=a);
}

bool test_reverse_i() { 
    int b[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int a[10];
    reverse_i(a, 10);
    for(int i= 0; i < 10; i++) 
        if (b[i] != a[i])
            return false;
    return true;
}


void test() {
    int tests = 8;
    int passed = 0;

    if (test_swap_i()) passed++;
    if (test_is_sorted_i()) passed++;
    if (test_is_not_sorted_i()) passed++;
    if (test_reverse_i()) passed++;
    if (test_copy_i()) passed++;

    if (test_swap()) passed++;
    if (test_is_sorted()) passed++;
    if (test_is_not_sorted()) passed++;

    cout << "Passed: " << passed << "\n";
    cout << "Total: " << tests << "\n";
}


int main() {
    test();
    return 0;
}
