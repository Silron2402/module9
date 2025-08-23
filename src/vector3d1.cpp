#include <iostream>
#include "vector3d1.h"
#include <memory>


//функция доступа к элементам вектора
double &Vector3D::operator()(int row)
{
    if (row > this->size)
    {
        std::cerr << "Vector: element number is out of bounds" << std::endl;
    };
    return coords[row]; // неявный указатель this принадлежности к классу
}

// Функция, предназначенная для вывода вектора в консоль
void Vector3D::print()
{
    for (int i = 0; i < this->size; ++i)
    {
        std::cout << this->coords[i] << " ";
        
    }
    std::cout << std::endl;
}