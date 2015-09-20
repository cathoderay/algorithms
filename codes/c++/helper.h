#ifndef HELPER
#define HELPER

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <time.h>


void swap(int *a, int *b) {
   int t;
   t = *a;
   *a = *b;
   *b = t; 
}


void print(int *a, int size) {
    std::cout << a[0];
    for(int i=1; i < size; i++)
        std::cout << ',' << a[i];
    std::cout << '\n';
}


void copy(int *d, int *s, int size){
    memcpy(d, s, size*sizeof(int));
}


void range(int *a, int size) {
    for(int i = 0; i < size; i++)
       a[i] = i;
}


void shuffle(int *a, int size) {
    int pos;
    for (int i = 0; i < size; i++) {
        pos = rand()%size;
        swap(&a[i], &a[pos]);
    }
}


void randrept(int *a, int size, float perc) {
    int range = int((1-perc)*size);
    if (!range) range++; 

    for(int i = 0; i < range; i++)
        a[i] = i;
    for(int i = range; i < size; i++)
        a[i] = rand()%range;
    shuffle(a, size);
}


void reverse(int *a, int size) {
    for(int i = 0; i < size; i++)
       a[i] = size - 1 - i;
}


double timeit(void (*sorter)(int *, int), int* a, int size) {
    int b[size];
    copy(b, a, size);
    clock_t time = clock();
    sorter(b, size);
    time = clock() - time;
    return (double)(time)/CLOCKS_PER_SEC;
}

#endif
