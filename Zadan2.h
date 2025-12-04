#ifndef ZADAN2_H
#define ZADAN2_H

#include <iostream>

class Quadratic2 {
public:
    // Êîíñòðóêòîðû
    Quadratic2();
    Quadratic2(double a, double b, double c);
    Quadratic2(const Quadratic2& other);

    // Ãåòòåðû
    double GetA() const;
    double GetB() const;
    double GetC() const;

    // Ñåòòåðû
    void SetA(double a);
    void SetB(double b);
    void SetC(double c);

    // Ìåòîä äëÿ íàõîæäåíèÿ êîðíåé êâàäðàòíîãî óðàâíåíèÿ
    double* FindRoots() const;

    // Óíàðíûå îïåðàöèè
    Quadratic2& operator++();     // Ïðåôèêñíûé ++
    Quadratic2 operator++(int);   // Ïîñòôèêñíûé ++
    Quadratic2& operator--();     // Ïðåôèêñíûé --
    Quadratic2 operator--(int);   // Ïîñòôèêñíûé --

    // Îïåðàöèè ïðèâåäåíèÿ òèïà
    operator double() const;      // Íåÿâíîå â double (äèñêðèìèíàíò)
    explicit operator bool() const;  // ßâíîå â bool (ñóùåñòâîâàíèå êîðíåé)

    // Áèíàðíûå îïåðàöèè
    bool operator==(const Quadratic2& other) const;  // ==
    bool operator!=(const Quadratic2& other) const;  // !=

    // Ïåðåãðóçêà îïåðàòîðà âûâîäà
    friend std::ostream& operator<<(std::ostream& os, const Quadratic2& eq);
private:
    double a_;
    double b_;
    double c_;

};


#endif
