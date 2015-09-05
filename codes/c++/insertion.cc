#include <iostream>
#include <cstdlib>
#include <time.h>


void insertion_sort(int v[], int length) {
    int k, i;
    for(int j = 1; j < length; j++) {
        k = v[j];
        i = j - 1;
        while (i > -1 && v[i] > k) {
            v[i + 1] = v[i];
            i--;
        }
        v[i + 1] = k;
    }
}

int main() {
    int v[] = {5, 1, 3, 4, 1};

    //testing
    //insertion_sort(v, 5);
    //for(int i = 0; i < 5; i++) std::cout << v[i];

    
    /*measuring time*/
    int k = 100000;
    int t[k];
    srand(time(NULL));

    //init
    for(int i = 0; i < k; i++)
        t[i] = i;

    //shuffle
    int pos, tmp;
    for(int i = 0; i < k; i++) {
        pos = rand()%k;
        tmp = t[i];
        t[i] = t[pos];
        t[pos] = tmp;
    }
    
    //go! 
    clock_t time = clock();
    insertion_sort(t, k);
    time = clock() - time;
    std::cout << (double)(time)/CLOCKS_PER_SEC << " seconds\n"; 
   

    return 0;
}
