#include <iostream>
#include "vector3d.h"

int main()
{
    std::cout << "creating of the first vector v1"<< std::endl; 
    // зададим первый вектор
    Vector3D v1(3);
    v1(0) = 1.;
    v1(1) = 2.;
    v1(2) = 1.;

    // выведем вектор v1 с помощью метода print
    std::cout << std::endl
              << "vector v1 is: " << std::endl;
    v1.print();

    std::cout << std::endl;
    std::cout << "Using of the copy constructor and the v2 vector creating"<< std::endl; 
    Vector3D v2{v1};

    // выведем вектор v2с помощью метода print
    std::cout << std::endl
              << "vector v2 is: " << std::endl;
    v2.print();
    
    std::cout << std::endl;
    std::cout << "creating of the third vector v3"<< std::endl; 
    // зададим третий вектор
    Vector3D v3(3);
    v3(0) = 1.46;
    v3(1) = 1.25;
    v3(2) = 1.15;
    std::cout << "the third vector v3 is created"<< std::endl; 

    //проверим оператор присваивания копированием
    std::cout << std::endl;
    std::cout << "creating of the fourth vector v4 by ising operator ="<< std::endl; 
    Vector3D v4 = v3;

    // выведем вектор v2с помощью метода print
    std::cout << std::endl
              << "vector v4 is: " << std::endl;
    v4.print();

    std::cout << std::endl;
    //Проверим перегруженный оператор вывода
    std::cout << "result of overloading << opreator is"<<std::endl;
    std::cout << v4 << std::endl;

    //протестируем  перемещение
    std::unique_ptr<Vector3D> v5(new Vector3D(3)); //выделим память
    *v5 = std::move(v4);
    //выведем результат
    std::cout << "the result of moving from v4 to v5 is"<<std::endl;
    std::cout << *v5 << std::endl;

    std::cout << "the result of moving from v5 to v6 is"<<std::endl;
    std::unique_ptr<Vector3D> v6; //выделим память
    v6 = std::move(v5);
    std::cout << *v6 << std::endl;

    //Выделяем Vector3D 
    Vector3D *v7 = new Vector3D(3);
    //Передаем указатель на него в std::shared_ptr и обозначаем как ptr1
    std::shared_ptr<Vector3D> ptr1(v7);
    //сформируем второй указатель ptr2. выполним копирующую инициализацию на базе prt1
    std::shared_ptr<Vector3D> ptr2(ptr1);

    std::cout << *ptr1 << std::endl;
    std::cout << *ptr2 << std::endl;

    return 0;


}