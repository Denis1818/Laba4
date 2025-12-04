#ifndef ZADAN1_H
#define ZADAN1_H

#include <iostream>

class Quadratic1 {
public:
    // Конструкторы
    Quadratic1();
    Quadratic1(double a, double b, double c);
    Quadratic1(const Quadratic1& other);

    // Геттеры
    double GetA() const;
    double GetB() const;
    double GetC() const;

    // Сеттеры
    void SetA(double a);
    void SetB(double b);
    void SetC(double c);

    // Метод для нахождения корней квадратного уравнения
    double* FindRoots() const;

    // Перегрузка оператора вывода
    friend std::ostream& operator<<(std::ostream& os, const Quadratic1& eq);
private:
    double a_;
    double b_;
    double c_;

};


#endif
