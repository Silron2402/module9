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
    //std::unique_ptr<Vector3D> ptr;

public:
    // Конструктор без параметров
    Vector3D()
    {
        std::cout << "Created an empty vector " << std::endl;
    }

    // Конструктор с параметрами
    Vector3D(int n) : n_(n), coords_(std::vector<double>(n)) {
        std::cout << "Created a vector with parameters " << std::endl;
    };

    //Конструктор копирования
    Vector3D(const Vector3D &vec)
    {
        n_ = vec.n_;
        coords_ = vec.coords_; 
        std::cout << "Created a copied vector " << std::endl;   
    }    
/*
    //Конструктор перемещения
    Vector3D(Vector3D&& moved) // ссылка rvalue
    {
    // код конструктора перемещения
        coords_ = std::unique_ptr(moved);  // перемещаем вектор
        n_ = moved.n_;  // перемещаем число элементов
        moved.coords_.clear();
        moved.n_ = 0;
    }
*/
    // Деструктор
    ~Vector3D() { std::cout<<"Item destroyed\n"; }

    // перегрузка оператора доступа к элементам матрицы
    double &operator()(int row); // возврат значения по ссылке (знак &)
    
    //Метод для вывод аэлементов матрицы
    void print();

    // перегрузка операции ввода элементов вектора
    friend std::istream &operator>>(std::istream &in, Vector3D &v);

    //перегрузка оператора присваивания копированием
    Vector3D& operator= (const Vector3D &other);
    
    // перегрузка операции вывода
    friend std::ostream &operator<<(std::ostream &out, const Vector3D &v);

    //Vector3D& operator= (Vector3D&& moved);

};