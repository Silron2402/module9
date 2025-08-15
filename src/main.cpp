#include <iostream>
#include "vector3d.h"

int main()
{
    // зададим первый вектор
    Vector3D v1(3);
    v1(0) = 1.;
    v1(1) = 2.;
    v1(2) = 1.;

    // выведем вектор v1 с помощью метода print
    std::cout << std::endl
              << "vector v1 is: " << std::endl;
    v1.print();

    Vector3D v2{v1};

    // выведем вектор v2с помощью метода print
    std::cout << std::endl
              << "vector v2 is: " << std::endl;
    v2.print();

    // зададим третий вектор
    Vector3D v3(3);
    v3(0) = 1.46546;
    v3(1) = 1.2566;
    v3(2) = 1.456410;
    
    //проверим оператор присваивания копированием
    Vector3D v4 = v3;

    // выведем вектор v2с помощью метода print
    std::cout << std::endl
              << "vector v4 is: " << std::endl;
    v4.print();

    //протестируем конструктор перемещения
    Vector3D v5{std::move(v3)};

      // выведем вектор v2с помощью метода print
    std::cout << std::endl
              << "vector v5 is: " << std::endl;
    v5.print();

    return 0;


}