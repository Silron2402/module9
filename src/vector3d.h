#pragma once
#include <iostream>
#include <vector>
using namespace std;

// Создадим класс для хранения координат вектора (coords)
class Vector3D
{
private:
    // Объявим закрытые переменные класса
    std::vector<double> coords_;
    int n_; // номер элемента

public:
    // Конструктор без параметров
    Vector3D() {}

    // Конструктор с параметрами
    Vector3D(int n) : n_(n), coords_(std::vector<double>(n)) {};

    // Деструктор
    ~Vector3D() { std::cout<<"Item destroyed\n"; }

    // перегрузка оператора доступа к элементам матрицы
    double &operator()(int row); // возврат значения по ссылке (знак &)

    void print();

    // перегрузка операции ввода элементов вектора
    // friend std::istream &operator>>(std::istream &in, Vector3D &v);
};