#include <iostream>
#include "vector3d.h"
/*
std::istream &operator>>(std::istream &in, Vector3D &v)
{
    double myvar;
    // Ввод элементов матрицы
    std::cout << "Let's fill in the matrix A, you created" << std::endl;

    // организуем вложенный цикл для поэлементного ввода элементов
    for (int i = 0; i < v.n_; ++i)
    {
        std::cout << "Enter element v(" << i << " ):" << std::endl;
        in >> myvar;
        // допишем введенный элемент в конец вектора
        //v.n_.push_back(myvar);
    }
    return in; // TODO: insert return statement here
}*/

//функция доступа к элементам вектора
double &Vector3D::operator()(int row)
{
    // TODO: insert return statement here
    if (row > this->n_)
    {
        std::cerr << "Vector: element number is out of bounds" << std::endl;
    };
    return this->coords_.at(row); // неявный указатель this принадлежности к классу
}

// Функция, предназначенная для вывода вектора в консоль
void Vector3D::print()
{
    for (int i = 0; i < this->n_; ++i)
    {
        std::cout << this->coords_.at(i) << " ";
        
    }
    std::cout << std::endl;
};
