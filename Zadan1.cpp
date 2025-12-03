#include "Zadan1.h"
#include <cmath>
#include <iostream>

// Конструктор по умолчанию
Quadratic1::Quadratic1() : a_(1.0), b_(0.0), c_(0.0) {}

// Конструктор с параметрами
Quadratic1::Quadratic1(double a, double b, double c)
    : a_(a), b_(b), c_(c) {
}

// Конструктор копирования
Quadratic1::Quadratic1(const Quadratic1& other)
    : a_(other.a_), b_(other.b_), c_(other.c_) {
}

// Геттеры
double Quadratic1::GetA() const { return a_; }
double Quadratic1::GetB() const { return b_; }
double Quadratic1::GetC() const { return c_; }

// Сеттеры
void Quadratic1::SetA(double a) { a_ = a; }
void Quadratic1::SetB(double b) { b_ = b; }
void Quadratic1::SetC(double c) { c_ = c; }

// Метод для нахождения корней квадратного уравнения
double* Quadratic1::FindRoots() const {
    double discriminant = b_ * b_ - 4 * a_ * c_;
    static double roots[2];

    if (discriminant > 0) {
        roots[0] = (-b_ + sqrt(discriminant)) / (2 * a_);
        roots[1] = (-b_ - sqrt(discriminant)) / (2 * a_);
    }
    else if (discriminant == 0) {
        roots[0] = -b_ / (2 * a_);
        roots[1] = roots[0];
    }
    else {
        roots[0] = roots[1] = 0.0;
    }

    return roots;
}

// Реализация оператора вывода
std::ostream& operator<<(std::ostream& os, const Quadratic1& eq) {
    os << eq.a_ << "x²";
    if (eq.b_ >= 0) {
        os << " + " << eq.b_ << "x";
    }
    else {
        os << " - " << -eq.b_ << "x";
    }
    if (eq.c_ >= 0) {
        os << " + " << eq.c_;
    }
    else {
        os << " - " << -eq.c_;
    }
    os << " = 0";
    return os;
}