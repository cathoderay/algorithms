#include "iostream"
using namespace std;


#include "../helper/matrix.h"


int main() 
{
    int n = 10;

    matrix m(n, row(n));
    printm(m);

    return 0; 
}
