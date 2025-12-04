#ifndef QUADRATIC_OPERATORS_H_
#define QUADRATIC_OPERATORS_H_

#include <iostream>

class QuadraticOperators {
 public:
  // Конструкторы
  QuadraticOperators();
  QuadraticOperators(double a, double b, double c);
  QuadraticOperators(const QuadraticOperators& other);

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
  QuadraticOperators& operator++();      // Префиксный ++
  QuadraticOperators operator++(int);    // Постфиксный ++
  QuadraticOperators& operator--();      // Префиксный --
  QuadraticOperators operator--(int);    // Постфиксный --

  // Операции приведения типа
  operator double() const;               // Неявное в double (дискриминант)
  explicit operator bool() const;        // Явное в bool (существование корней)

  // Бинарные операции
  bool operator==(const QuadraticOperators& other) const;  // ==
  bool operator!=(const QuadraticOperators& other) const;  // !=

  // Перегрузка оператора вывода
  friend std::ostream& operator<<(std::ostream& os, const QuadraticOperators& eq);

 private:
  double a_;
  double b_;
  double c_;
};

#endif  // QUADRATIC_OPERATORS_H_
