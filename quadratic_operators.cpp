#include "quadratic_operators.h"
#include <cmath>
#include <iostream>

// Конструктор по умолчанию
QuadraticOperators::QuadraticOperators() : a_(1.0), b_(0.0), c_(0.0) {}

// Конструктор с параметрами
QuadraticOperators::QuadraticOperators(double a, double b, double c)
    : a_(a), b_(b), c_(c) {}

// Конструктор копирования
QuadraticOperators::QuadraticOperators(const QuadraticOperators& other)
    : a_(other.a_), b_(other.b_), c_(other.c_) {}

// Геттеры
double QuadraticOperators::GetA() const { return a_; }
double QuadraticOperators::GetB() const { return b_; }
double QuadraticOperators::GetC() const { return c_; }

// Сеттеры
void QuadraticOperators::SetA(double a) { a_ = a; }
void QuadraticOperators::SetB(double b) { b_ = b; }
void QuadraticOperators::SetC(double c) { c_ = c; }

// Метод для нахождения корней квадратного уравнения
double* QuadraticOperators::FindRoots() const {
  double discriminant = b_ * b_ - 4 * a_ * c_;
  static double roots[2];

  if (discriminant > 0) {
    roots[0] = (-b_ + sqrt(discriminant)) / (2 * a_);
    roots[1] = (-b_ - sqrt(discriminant)) / (2 * a_);
  } else if (discriminant == 0) {
    roots[0] = -b_ / (2 * a_);
    roots[1] = roots[0];
  } else {
    roots[0] = roots[1] = 0.0;
  }

  return roots;
}

// Префиксный ++ (увеличивает коэффициенты на 1)
QuadraticOperators& QuadraticOperators::operator++() {
  ++a_;
  ++b_;
  ++c_;
  return *this;
}

// Постфиксный ++ (увеличивает коэффициенты на 1)
QuadraticOperators QuadraticOperators::operator++(int) {
  QuadraticOperators temp(*this);
  ++a_;
  ++b_;
  ++c_;
  return temp;
}

// Префиксный -- (уменьшает коэффициенты на 1)
QuadraticOperators& QuadraticOperators::operator--() {
  --a_;
  --b_;
  --c_;
  return *this;
}

// Постфиксный -- (уменьшает коэффициенты на 1)
QuadraticOperators QuadraticOperators::operator--(int) {
  QuadraticOperators temp(*this);
  --a_;
  --b_;
  --c_;
  return temp;
}

// Неявное приведение к double (дискриминант)
QuadraticOperators::operator double() const {
  return b_ * b_ - 4 * a_ * c_;
}

// Явное приведение к bool (существование корней)
QuadraticOperators::operator bool() const {
  double discriminant = b_ * b_ - 4 * a_ * c_;
  return discriminant >= 0;
}

// Бинарная операция == (уравнения равны, если равны коэффициенты)
bool QuadraticOperators::operator==(const QuadraticOperators& other) const {
  return a_ == other.a_ && b_ == other.b_ && c_ == other.c_;
}

// Бинарная операция != (уравнения не равны, если не равны коэффициенты)
bool QuadraticOperators::operator!=(const QuadraticOperators& other) const {
  return !(*this == other);
}

// Реализация оператора вывода
std::ostream& operator<<(std::ostream& os, const QuadraticOperators& eq) {
  os << eq.a_ << "x²";
  if (eq.b_ >= 0) {
    os << " + " << eq.b_ << "x";
  } else {
    os << " - " << -eq.b_ << "x";
  }
  if (eq.c_ >= 0) {
    os << " + " << eq.c_;
  } else {
    os << " - " << -eq.c_;
  }
  os << " = 0";
  return os;
}
