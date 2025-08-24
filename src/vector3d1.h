#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Vector3D {
private:
    // Используем unique_ptr для автоматического управления памятью
    std::unique_ptr<double[]> coords;
    
public:
    // Конструктор с тремя параметрами
    Vector3D(double x = 0.0, double y = 0.0, double z = 0.0) 
        : coords(std::make_unique<double[]>(3)) {
        coords[0] = x;
        coords[1] = y;
        coords[2] = z;
    }
    
    // Деструктор (автоматически генерируется компилятором)
    ~Vector3D() = default;
    
    // Конструктор копирования
    Vector3D(const Vector3D& other) 
        : coords(std::make_unique<double[]>(3)) {
        coords[0] = other.coords[0];
        coords[1] = other.coords[1];
        coords[2] = other.coords[2];
    }
    
    // Оператор присваивания копированием
    Vector3D& operator=(const Vector3D& other) {
        if (this != &other) {
            coords[0] = other.coords[0];
            coords[1] = other.coords[1];
            coords[2] = other.coords[2];
        }
        return *this;
    }
    
    // Конструктор перемещения
    Vector3D(Vector3D&& other) noexcept 
        : coords(std::move(other.coords)) {
        // Перемещение не требует дополнительных действий
    }
    
    // Оператор присваивания перемещением
    Vector3D& operator=(Vector3D&& other) noexcept {
        if (this != &other) {
            coords = std::move(other.coords);
        }
        return *this;
    }
    
    // Методы доступа к координатам
    double& operator[](size_t index) {
        if (index >= 3) {
            throw std::out_of_range("Индекс выходит за пределы массива");
        }
        return coords[index];
    }
    
    const double& operator[](size_t index) const {
        if (index >= 3) {
            throw std::out_of_range("Индекс выходит за пределы массива");
        }
        return coords[index];
    }
    
    // Метод для вывода вектора
    void print() const {
        std::cout << "(" << coords[0] << ", " 
                  << coords[1] << ", " 
                  << coords[2] << ")" << std::endl;
    }
};
 /*// Пример использования
int main() {
    // Создание вектора
    Vector3D v1(1.0, 2.0, 3.0);
    v1.print();
    
    // Копирование
    Vector3D v2 = v1;
    v2.print();
    
    // Перемещение
    Vector3D v3 = std::move(v1);
    v3.print();
    
    return 0;
}*/