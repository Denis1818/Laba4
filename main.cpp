#include <iostream>
#include <string>
#include <windows.h>

#include "Zadan1.h"
#include "Zadan2.h"

void SetupConsole() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
}

// Функции для ввода с проверкой
double InputDouble(const std::string& prompt) {
    double value;
    const int kMaxIgnore = 10000;

    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            break;
        }
        else {
            std::cout << "Ошибка: введите корректное число!" << std::endl;
            std::cin.clear();
            std::cin.ignore(kMaxIgnore, '\n');
        }
    }
    return value;
}

// Функция для задачи 1 (базовый класс)
void Task1() {
    std::cout << "\n=== ЗАДАЧА 1: Quadratic1 (Базовый класс) ===" << std::endl;

    // Тест 1: Конструктор по умолчанию
    std::cout << "\n1. Тестирование конструктора по умолчанию:" << std::endl;
    Quadratic1 eq1;
    std::cout << "Создано уравнение: " << eq1 << std::endl;
    double* roots1 = eq1.FindRoots();
    std::cout << "Корни уравнения: " << roots1[0] << ", " << roots1[1] << std::endl;

    // Тест 2: Конструктор с параметрами
    std::cout << "\n2. Тестирование конструктора с параметрами:" << std::endl;
    double a1 = InputDouble("Введите коэффициент a: ");
    double b1 = InputDouble("Введите коэффициент b: ");
    double c1 = InputDouble("Введите коэффициент c: ");
    Quadratic1 eq2(a1, b1, c1);
    std::cout << "Создано уравнение: " << eq2 << std::endl;
    double* roots2 = eq2.FindRoots();
    std::cout << "Корни уравнения: " << roots2[0] << ", " << roots2[1] << std::endl;

    // Тест 3: Конструктор копирования
    std::cout << "\n3. Тестирование конструктора копирования:" << std::endl;
    Quadratic1 eq3(eq2);
    std::cout << "Скопировано уравнение: " << eq3 << std::endl;
    double* roots3 = eq3.FindRoots();
    std::cout << "Корни уравнения: " << roots3[0] << ", " << roots3[1] << std::endl;

    // Тест 4: Сеттеры и геттеры
    std::cout << "\n4. Тестирование сеттеров и геттеров:" << std::endl;
    Quadratic1 eq4;
    double new_a = InputDouble("Введите новый коэффициент a: ");
    double new_b = InputDouble("Введите новый коэффициент b: ");
    double new_c = InputDouble("Введите новый коэффициент c: ");
    eq4.SetA(new_a);
    eq4.SetB(new_b);
    eq4.SetC(new_c);
    std::cout << "Уравнение после изменений: " << eq4 << std::endl;
    std::cout << "Коэффициенты (через геттеры): a=" << eq4.GetA()
        << ", b=" << eq4.GetB() << ", c=" << eq4.GetC() << std::endl;
    double* roots4 = eq4.FindRoots();
    std::cout << "Корни уравнения: " << roots4[0] << ", " << roots4[1] << std::endl;

    std::cout << "\nЗадача 1 завершена успешно!" << std::endl;
}

// Функция для задачи 2 (класс с перегруженными операциями)
void Task2() {
    std::cout << "\n=== ЗАДАЧА 2: Quadratic2 С ПЕРЕГРУЖЕННЫМИ ОПЕРАЦИЯМИ ===" << std::endl;

    // Создание тестовых уравнений
    std::cout << "\n1. Создание тестовых уравнений:" << std::endl;
    double a1 = InputDouble("Введите коэффициент a для уравнения 1: ");
    double b1 = InputDouble("Введите коэффициент b для уравнения 1: ");
    double c1 = InputDouble("Введите коэффициент c для уравнения 1: ");
    Quadratic2 eq1(a1, b1, c1);
    std::cout << "Создано уравнение 1: " << eq1 << std::endl;

    double a2 = InputDouble("Введите коэффициент a для уравнения 2: ");
    double b2 = InputDouble("Введите коэффициент b для уравнения 2: ");
    double c2 = InputDouble("Введите коэффициент c для уравнения 2: ");
    Quadratic2 eq2(a2, b2, c2);
    std::cout << "Создано уравнение 2: " << eq2 << std::endl;

    // Тестирование ударных операций
    std::cout << "\n2. Тестирование ударных операций:" << std::endl;

    // Префиксный ++
    std::cout << "Префиксный ++eq1:" << std::endl;
    std::cout << "До: " << eq1 << std::endl;
    Quadratic2 eq1_prefix = ++eq1;
    std::cout << "После: " << eq1 << std::endl;
    std::cout << "Результат: " << eq1_prefix << std::endl;

    // Постфиксный ++
    std::cout << "\nПостфиксный eq2++:" << std::endl;
    std::cout << "До: " << eq2 << std::endl;
    Quadratic2 eq2_postfix = eq2++;
    std::cout << "После: " << eq2 << std::endl;
    std::cout << "Результат: " << eq2_postfix << std::endl;

    // Префиксный --
    std::cout << "\nПрефиксный --eq1:" << std::endl;
    std::cout << "До: " << eq1 << std::endl;
    Quadratic2 eq1_prefix_dec = --eq1;
    std::cout << "После: " << eq1 << std::endl;
    std::cout << "Результат: " << eq1_prefix_dec << std::endl;

    // Постфиксный --
    std::cout << "\nПостфиксный eq2--:" << std::endl;
    std::cout << "До: " << eq2 << std::endl;
    Quadratic2 eq2_postfix_dec = eq2--;
    std::cout << "После: " << eq2 << std::endl;
    std::cout << "Результат: " << eq2_postfix_dec << std::endl;

    // Тестирование операций приведения типа
    std::cout << "\n3. Тестирование операций приведения типа:" << std::endl;

    // Неявное приведение к double (дискриминант)
    double discriminant = eq1;
    std::cout << "Неявное приведение eq1 к double: " << discriminant
        << " (дискриминант)" << std::endl;

    // Явное приведение к bool (существование корней)
    bool has_roots = static_cast<bool>(eq1);
    std::cout << "Явное приведение eq1 к bool: " << (has_roots ? "true" : "false")
        << " (действительные корни существуют)" << std::endl;

    // Тестирование бинарных операций
    std::cout << "\n4. Тестирование бинарных операций:" << std::endl;

    // Сравнение уравнений
    bool are_equal = (eq1 == eq2);
    std::cout << "eq1 == eq2: " << (are_equal ? "true" : "false") << std::endl;

    bool are_not_equal = (eq1 != eq2);
    std::cout << "eq1 != eq2: " << (are_not_equal ? "true" : "false") << std::endl;

    // Демонстрация вычисления корней для финальных уравнений
    std::cout << "\n5. Финальные уравнения и их корни:" << std::endl;
    std::cout << "Уравнение 1: " << eq1 << std::endl;
    double* roots1 = eq1.FindRoots();
    std::cout << "Корни уравнения 1: " << roots1[0] << ", " << roots1[1] << std::endl;

    std::cout << "Уравнение 2: " << eq2 << std::endl;
    double* roots2 = eq2.FindRoots();
    std::cout << "Корни уравнения 2: " << roots2[0] << ", " << roots2[1] << std::endl;

    std::cout << "\nЗадача 2 завершена успешно!" << std::endl;
}

// Главное меню
void ShowMenu() {
    std::cout << "\n=== ГЛАВНОЕ МЕНЮ ===" << std::endl;
    std::cout << "1 - Задача 1 (Базовый класс QuadraticEquation)" << std::endl;
    std::cout << "2 - Задача 2 (Класс QuadraticEquation с перегруженными операциями)" << std::endl;
    std::cout << "0 - Выход" << std::endl;
    std::cout << "Выберите задачу: ";
}

int main() {
    setlocale(LC_ALL, "Russian");
    SetupConsole();
    int choice = 0;

    do {
        ShowMenu();
        std::cin >> choice;

        switch (choice) {
        case 1:
            Task1();
            break;
        case 2:
            Task2();
            break;
        case 0:
            std::cout << "Выход из программы..." << std::endl;
            break;
        default:
            std::cout << "Неверный выбор! Попробуйте снова." << std::endl;
            break;
        }

        if (choice != 0) {
            std::cout << "\nНажмите Enter для продолжения...";
            std::cin.ignore();
            std::cin.get();
        }

    } while (choice != 0);

    return 0;
}