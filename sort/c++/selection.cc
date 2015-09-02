#include <iostream>


void insertion_sort(int v[], int length) {
    int tmp, p;
    for(int i = 1; i < length; i++) {
        p = i;
        while (p > 0 && v[p] < v[p - 1]) {
            tmp = v[p];
            v[p] = v[p - 1];
            v[p - 1] = tmp;
            p -= 1;
        }
    }
}

int main() {
    int v[] = {5, 1, 3, 4, 1};

    insertion_sort(v, 5);

    //testing
    for(int i = 0; i < 5; i++) std::cout << v[i];

    return 0;
}
