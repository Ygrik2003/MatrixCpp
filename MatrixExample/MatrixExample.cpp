#include <iostream>
#include "matrix.h"


int main()
{
    Matrix m1(2, 2);
    Matrix m2(3, 3);
    try {
        m1 = m1 * m2;
    }
    catch (MatrixException e){
        
    }
}