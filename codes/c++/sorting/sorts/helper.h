#ifndef HELPER
#define HELPER

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string.h>
#include <time.h>


/********************************************************|
|                INT VERSIONS                            |
\********************************************************/
//Kept here in order to show the progress...

void swap_i(int *a, int *b) {
   int t;
   t = *a;
   *a = *b;
   *b = t; 
}

void print_i(int *a, int size) {
    std::cout << a[0];
    for(int i=1; i < size; i++)
        std::cout << ',' << a[i];
    std::cout << '\n';
}

void copy_i(int *d, int *s, int size){
    memcpy(d, s, size*sizeof(int));
}

void range_i(int *a, int size) {
    for(int i = 0; i < size; i++)
       a[i] = i;
}

void shuffle_i(int *a, int size) {
    int pos;
    for (int i = 0; i < size; i++) {
        pos = rand()%size;
        swap_i(&a[i], &a[pos]);
    }
}

void randrept_i(int *a, int size, float perc) {
    int range = int((1-perc)*size);
    if (!range) range++; //not perfect, but useful

    for(int i = 0; i < range; i++)
        a[i] = i;
    for(int i = range; i < size; i++)
        a[i] = rand()%range;
    shuffle_i(a, size);
}

void reverse_i(int *a, int size) {
    for(int i = 0; i < size; i++)
       a[i] = size - 1 - i;
}

bool is_sorted_i(int *a, int size) {
    for(int i = 1; i < size; i++)
        if (a[i] < a[i-1])
            return false;
    return true;
}

double check_if_sorts_i(void (*sorter)(int *, int), int *a, int size) {
    int b[size];
    copy_i(b, a, size);
    sorter(b, size);
    return is_sorted_i(b, size);
}

double timeit_i(void (*sorter)(int *, int), int* a, int size) {
    int b[size];
    copy_i(b, a, size);
    clock_t time = clock();
    sorter(b, size);
    time = clock() - time;
    return (double)(time)/CLOCKS_PER_SEC;
}


/********************************************************|
|                GENERIC VERSIONS                        |
\********************************************************/
template<typename T>
void swap(T *a, T *b) {
   T t;
   t = *a;
   *a = *b;
   *b = t; 
}

template<typename T>
void print(T *a, int size) {
    std::cout << a[0];
    for(int i=1; i < size; i++)
        std::cout << ',' << a[i];
    std::cout << '\n';
}

template<typename T>
void shuffle(T *a, int size) {
    int pos;
    for (int i = 0; i < size; i++) {
        pos = rand()%size;
        swap(&a[i], &a[pos]);
    }
}

template<typename T>
bool is_sorted(T *a, int size) {
    for(int i = 1; i < size; i++)
        if (a[i] < a[i-1])
            return false;
    return true;
}


/********************************************************|
|                STRING VERSIONS                         |
\********************************************************/
double check_if_sorts_s(void (*sorter)(string *, int), string *a, int size) {
    string b[size];
    std::copy(a, a + size, b);
    sorter(b, size);
    return is_sorted(b, size);
}

double timeit_s(void (*sorter)(string *, int), string* a, int size) {
    string b[size];
    std::copy(a, a + size, b);
    clock_t time = clock();
    sorter(b, size);
    time = clock() - time;
    return (double)(time)/CLOCKS_PER_SEC;
}

// Used for insertion_sort cutoff
clock_t timeit_c(void (*sorter)(int *, int), int* a, int size) {
    int b[size];
    copy_i(b, a, size);
    clock_t time = clock();
    sorter(b, size);
    time = clock() - time;
    return time;
}
#endif
