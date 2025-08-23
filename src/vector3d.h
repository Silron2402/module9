#pragma once
#include <iostream>
#include <vector>
using namespace std;

// Создадим класс для хранения координат вектора (coords)
class Vector3D
{
private:
    // Объявим закрытые переменные класса
    std::vector<double> coords_; //вектор координат
    int n_; // длина вектора
    //std::unique_ptr<double[]> ptr_; //умный указатель на данные внутри Vector3D

public:
    // Конструктор без параметров
    Vector3D()
    {
        n_ = 3;
        coords_ = std::vector<double>(3);
        std::cout << "Called a default constructor" << std::endl;
    }

    // Конструктор с параметрами
    Vector3D(int n) : n_(n), coords_(std::vector<double>(n))
    {
        std::cout << "Called a constructor with parameters " << std::endl;
    };

    // Конструктор копирования
    Vector3D(const Vector3D &vec)
    {
        n_ = vec.n_;
        coords_ = vec.coords_;
        std::cout << "Called a copy constructor" << std::endl;
    }
/*
    // Конструктор перемещения
    Vector3D(Vector3D &&moved) : coords_(nullptr) , n_(0) , // ссылка rvalue
    {
    // код конструктора перемещения
      v_ = std::move(moved.v_);  // перемещаем вектор
      //n_ = moved.n_; // перемещаем число элементов
//        v_ = nullptr;
//        std::cout << "Called a move constructor" << std::endl;
  //  }

    // Деструктор*/
    ~Vector3D() { std::cout<<"Item destroyed\n"; }

    // перегрузка оператора доступа к элементам матрицы
    double &operator()(int row); // возврат значения по ссылке (знак &)
    
    //Метод для вывод аэлементов матрицы
    void print();

    // перегрузка операции ввода элементов вектора
    //friend std::istream &operator>>(std::istream &in, Vector3D &v);

    //перегрузка оператора присваивания копированием
    Vector3D& operator= (const Vector3D &other);
    
    // перегрузка операции вывода
    friend std::ostream &operator<<(std::ostream &out, const Vector3D &v);

    Vector3D& operator= (Vector3D&& moved);

};