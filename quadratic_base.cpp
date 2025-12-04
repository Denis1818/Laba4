#include "quadratic_base.h"
#include <cmath>
#include <iostream>

// Конструктор по умолчанию
QuadraticBase::QuadraticBase() : a_(1.0), b_(0.0), c_(0.0) {}

// Конструктор с параметрами
QuadraticBase::QuadraticBase(double a, double b, double c)
    : a_(a), b_(b), c_(c) {}

// Конструктор копирования
QuadraticBase::QuadraticBase(const QuadraticBase& other)
    : a_(other.a_), b_(other.b_), c_(other.c_) {}

// Геттеры
double QuadraticBase::GetA() const { return a_; }
double QuadraticBase::GetB() const { return b_; }
double QuadraticBase::GetC() const { return c_; }

// Сеттеры
void QuadraticBase::SetA(double a) { a_ = a; }
void QuadraticBase::SetB(double b) { b_ = b; }
void QuadraticBase::SetC(double c) { c_ = c; }

// Метод для нахождения корней квадратного уравнения
double* QuadraticBase::FindRoots() const {
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

// Реализация оператора вывода
std::ostream& operator<<(std::ostream& os, const QuadraticBase& eq) {
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
