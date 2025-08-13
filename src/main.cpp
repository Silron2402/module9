#include <iostream>
#include "vector3d.h"

int main()
{
    // зададим первую матрицу
    Vector3D v1(3);
    v1(0) = 1.;
    v1(1) = 2.;
    v1(2) = 1.;

    // выведем вектор v1 с помощью метода print
    std::cout << std::endl
              << "vector v1 is: " << std::endl;
    v1.print();

    return 0;
}