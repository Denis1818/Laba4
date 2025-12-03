#include "Zadan2.h"
#include <cmath>
#include <iostream>

// Конструктор по умолчанию
Quadratic2::Quadratic2() : a_(1.0), b_(0.0), c_(0.0) {}

// Конструктор с параметрами
Quadratic2::Quadratic2(double a, double b, double c)
    : a_(a), b_(b), c_(c) {
}

// Конструктор копирования
Quadratic2::Quadratic2(const Quadratic2& other)
    : a_(other.a_), b_(other.b_), c_(other.c_) {
}

// Геттеры
double Quadratic2::GetA() const { return a_; }
double Quadratic2::GetB() const { return b_; }
double Quadratic2::GetC() const { return c_; }

// Сеттеры
void Quadratic2::SetA(double a) { a_ = a; }
void Quadratic2::SetB(double b) { b_ = b; }
void Quadratic2::SetC(double c) { c_ = c; }

// Метод для нахождения корней квадратного уравнения
double* Quadratic2::FindRoots() const {
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

// Префиксный ++ (увеличивает коэффициенты на 1)
Quadratic2& Quadratic2::operator++() {
    ++a_;
    ++b_;
    ++c_;
    return *this;
}

// Постфиксный ++ (увеличивает коэффициенты на 1)
Quadratic2 Quadratic2::operator++(int) {
    Quadratic2 temp(*this);
    ++a_;
    ++b_;
    ++c_;
    return temp;
}

// Префиксный -- (уменьшает коэффициенты на 1)
Quadratic2& Quadratic2::operator--() {
    --a_;
    --b_;
    --c_;
    return *this;
}

// Постфиксный -- (уменьшает коэффициенты на 1)
Quadratic2 Quadratic2::operator--(int) {
    Quadratic2 temp(*this);
    --a_;
    --b_;
    --c_;
    return temp;
}

// Неявное приведение к double (дискриминант)
Quadratic2::operator double() const {
    return b_ * b_ - 4 * a_ * c_;
}

// Явное приведение к bool (существование корней)
Quadratic2::operator bool() const {
    double discriminant = b_ * b_ - 4 * a_ * c_;
    return discriminant >= 0;
}

// Бинарная операция == (уравнения равны, если равны коэффициенты)
bool Quadratic2::operator==(const Quadratic2& other) const {
    return a_ == other.a_ && b_ == other.b_ && c_ == other.c_;
}

// Бинарная операция != (уравнения не равны, если не равны коэффициенты)
bool Quadratic2::operator!=(const Quadratic2& other) const {
    return !(*this == other);
}

// Реализация оператора вывода
std::ostream& operator<<(std::ostream& os, const Quadratic2& eq) {
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