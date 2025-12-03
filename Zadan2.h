#ifndef ZADAN2_H
#define ZADAN2_H

#include <iostream>

class Quadratic2 {
private:
    double a_;
    double b_;
    double c_;

public:
    // Конструкторы
    Quadratic2();
    Quadratic2(double a, double b, double c);
    Quadratic2(const Quadratic2& other);

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

    // Унарные операции
    Quadratic2& operator++();     // Префиксный ++
    Quadratic2 operator++(int);   // Постфиксный ++
    Quadratic2& operator--();     // Префиксный --
    Quadratic2 operator--(int);   // Постфиксный --

    // Операции приведения типа
    operator double() const;      // Неявное в double (дискриминант)
    explicit operator bool() const;  // Явное в bool (существование корней)

    // Бинарные операции
    bool operator==(const Quadratic2& other) const;  // ==
    bool operator!=(const Quadratic2& other) const;  // !=

    // Перегрузка оператора вывода
    friend std::ostream& operator<<(std::ostream& os, const Quadratic2& eq);
};

#endif