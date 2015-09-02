#include <iostream>


void selection_sort(int v[], int length) {
    int min, tmp;
    for(int i = 0; i < length; i++) {
        min = i;
        for(int j = i + 1; j < length; j++)
            if (v[j] < v[min])
                min = j;
        tmp = v[min];
        v[min] = v[i];
        v[i] = tmp;
    }
}

int main() {
    int v[] = {5, 1, 3, 4, 1};

    selection_sort(v, 5);

    //testing
    for(int i = 0; i < 5; i++) std::cout << v[i];

    return 0;
}
