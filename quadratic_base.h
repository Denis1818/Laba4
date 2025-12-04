#ifndef QUADRATIC_BASE_H_
#define QUADRATIC_BASE_H_

#include <iostream>

class QuadraticBase {
 public:
  // Конструкторы
  QuadraticBase();
  QuadraticBase(double a, double b, double c);
  QuadraticBase(const QuadraticBase& other);

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
  friend std::ostream& operator<<(std::ostream& os, const QuadraticBase& eq);

 private:
  double a_;
  double b_;
  double c_;
};

#endif  // QUADRATIC_BASE_H_
