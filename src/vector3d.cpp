#include <iostream>
#include "vector3d.h"
#include <memory>

std::istream &operator>>(std::istream &in, Vector3D &v)
{
    double myvar;
    // Ввод элементов 
    std::cout << "Let's fill in the vector, you created" << std::endl;

    // организуем цикл для поэлементного ввода элементов
    for (int i = 0; i < v.n_; ++i)
    {
        std::cout << "Enter element v(" << i << " ):" << std::endl;
        in >> myvar;
        // допишем введенный элемент в конец вектора
        v.coords_.push_back(myvar);
    }
    return in;
}

//функция доступа к элементам вектора
double &Vector3D::operator()(int row)
{
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
}
// Оператор присваивания копированием
Vector3D &Vector3D::operator=(const Vector3D &vect)
{
    // проверка самоприсваивания
    if (&vect == this)
        return *this;
    // 
    this->coords_ = vect.coords_;

    return *this;
}
/*
Vector3D &Vector3D::operator=(Vector3D &&moved)
{
    if (&moved != this) // избегаем самоприсваивания
    {
    //протестируем  перемещение
    std::unique_ptr<Vector3D> new_v(new Vector3D(moved.n_)); //выделим память
    *new_v = std::move(moved);
    return *new_v; 
    }

    return *this;
};*/
 
std::ostream &operator<<(std::ostream &out, const Vector3D &v)
{
    out << "[ ";
    
    for (int i = 0; i < v.n_; ++i)
    {
        out << v.coords_.at(i) << " ";
    }    
    
    out << "]";

    out << std::endl;
    
    return out;
}



/*
const A& operator=(const A& other)
{
   if(this == &other) return *this;
   A my_tmp_a(other._size);
   std::copy(&other[0], &other[other._size], &my_tmp_a[0]); 
   swap(my_tmp_a);       
   return *this;
}
*/