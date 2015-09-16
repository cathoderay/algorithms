#include <iostream>
#include <cstdlib>
#include <cstring>
#include <time.h>


void shuffle(int *a, int size) {   
    for(int i = 0; i < size; i++)
        a[i] = rand()%size;
}


void print(int *a, int size) {
    std::cout << a[0];
    for(int i=1; i < size; i++)
        std::cout << ',' << a[i];
    std::cout << '\n';
}


void copy_array(int *d, int *s, int size){
    memcpy(d, s, size*sizeof(int));
}


void shuffle_array(int *a, int size) {
    //TODO: MAKE IT WITHOUT REPETITIONS
    for (int i = 0; i < size; i++)
        a[i] = rand()%size;
}


double timeit(void (*sorter)(int *, int), int* a, int size) {
    clock_t time = clock();
    sorter(a, size);
    time = clock() - time;
    return (double)(time)/CLOCKS_PER_SEC;
}
