
#include <iostream>
#include <cmath>
#include <iomanip>

class FunctionCalculator {
public:
    // Метод для вычисления y(x) с помощью формул преобразования static double computeUsingFormulas(double x) {
    // Вычисляем компоненты по формулам double abs_x = std::abs(x);
    double sqrt_abs_x = std::sqrt(abs_x);
    double denominator = x * x + 1;

    // Арккосинус double acos_value = std::acos(std::sqrt(abs_x) / denominator);
    double y1 = std::pow(acos_value, 3);

    // Корень из корня double y2 = std::sqrt(std::sqrt_abs_x);

    // Логарифм по основанию 2 double exponent = std::pow(2.0, x + 2);
    double y3 = std::log( std::pow(3, exponent) ) / std::log(2);

    return y1 + y2 + y3;
}

// Метод для вычисления y(x) с использованием модуля Math
static double computeUsingMathModule(double x) {
    return computeUsingFormulas(x); // Используем тот же расчет, так как функции из cmath }
};

// Проверка, принадлежит ли точка (x, y) области D (верхний полукруг радиуса 5)
bool isInRegionD(double x, double y) {
    return (x*x + y*y <= 25) && (y >= 0);
}

int main() {
    double x;
    std::cout << "Введите значение x: ";
    std::cin >> x;

    // Вычисление y через формулы
    double y_formulas = FunctionCalculator::computeUsingFormulas(x);
    // Вычисление y через Math module (в данном случае это тоже функции из cmath)
    double y_math = FunctionCalculator::computeUsingMathModule(x);

    // Проверка принадлежности точки (x, y) области D
    bool belongs = isInRegionD(x, y_formulas);
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Значение y(x): " << y_formulas << std::endl;
    std::cout << "Точка (" << x << "; " << y_formulas << ")";
    if (belongs)
        std::cout << " принадлежит области D" << std::endl;
    else
        std::cout << " не принадлежит области D" << std::endl;

    return 0;
}
