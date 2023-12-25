#include <iostream>

class Polynomial {
public:
    // Конструктор
    Polynomial(double a, double b, double c) : a_(a), b_(b), c_(c) {}

    double evaluate(double x) {
        return a_ * x * x + b_ * x + c_;
    }

    // Сложение многочленов
    Polynomial add(const Polynomial& other) {
        return Polynomial(a_ + other.a_, b_ + other.b_, c_ + other.c_);
    }

    // Вычитание многочленов
    Polynomial subtract(const Polynomial& other) {
        return Polynomial(a_ - other.a_, b_ - other.b_, c_ - other.c_);
    }

    // Умножение многочленов
    Polynomial multiply(const Polynomial& other) {
        double new_a = a_ * other.a_;
        double new_b = a_ * other.b_ + b_ * other.a_;
        double new_c = a_ * other.c_ + b_ * other.b_ + c_ * other.a_;
        double new_d = b_ * other.c_ + c_ * other.b_;
        double new_e = c_ * other.c_;
        
        // Предполагаем, что результатом умножения также будет многочлен не выше второй степени
        // игнорируем коэффициенты при x^4 и x^3
        return Polynomial(new_c, new_d, new_e);
    }

    // Вывод на экран
    void print() {
        std::cout << a_ << "x^2 + " << b_ << "x + " << c_ << std::endl;
    }

private:
    double a_, b_, c_;
};

int main() {
    Polynomial p1(3, 4, 5); // Многочлен 3x^2 + 4x + 5
    Polynomial p2(1, 2, 3); // Многочлен 1x^2 + 2x + 3
    

    std::cout << "Polynomial p1: ";
    p1.print();
    std::cout << "Polynomial p2: ";
    p2.print();

    double value = p1.evaluate(2);
    std::cout << "Значение p1 с x=2: " << value << std::endl;

    Polynomial p3 = p1.add(p2);
    std::cout << "Сложение p1 и p2: ";
    p3.print();
    

    Polynomial p4 = p1.subtract(p2);
    std::cout << "Вычитание p1 - p2: ";
    p4.print();
    

    Polynomial p5 = p1.multiply(p2);
    std::cout << "Умножение p1 на p2 (упрощенно): ";
    p5.print();
    
    return 0;
}