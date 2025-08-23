#pragma once
#include <iostream>
#include <vector>
using namespace std;

// Создадим класс для хранения координат вектора (coords)
class Vector3D
{
private:
    double *coords;
    int size;

public:
    // Конструктор без параметров
    Vector3D()
    {
        coords = new double[3];
        std::cout << "Called an empty constructor" << std::endl;
    }

    //Конструктор с параметрами
    Vector3D(int size_) : size(size_)
    {
        coords = new double[size_];
        std::cout << "Called a constructor with parameters" << std::endl;
    }

    // Конструктор копирования
    Vector3D(const Vector3D &vec)
    {
        size = vec.size;
        coords = vec.coords;
        std::cout << "Called a copy constructor" << std::endl;
    }

    //Деструктор
    ~Vector3D()
    {
        delete[] coords;
        std::cout << "Called a destructor" << std::endl;
    }

    // перегрузка оператора доступа к элементам матрицы
    double &operator()(int row); // возврат значения по ссылке (знак &)

    // Метод для вывода элементов матрицы
    void print();
};
