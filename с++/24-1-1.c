#include <iostream>
#include <math.h>

double y(double x) {
    if (x < -1) {
        // y(x) = x^6 * lg(abs((6^x) - abs(x - 5)^x))
        return pow(x, 6) * log10(fabs(pow(6, x) - pow(fabs(x - 5), x)));
    } else if (x >= -1 && x < 1) {
        // y(x) = sin(x)/(1 - 2x^2)
        return sin(x) / (1 - 2 * pow(x, 2));
    } else { // x >= 1
        // y(x) = arcsin(1 / (x^4))
        return asin(1 / pow(x, 4));
    }
}

int main() {
    double x;

    // Ввод значения x с клавиатуры
    std::cout << "Введите значение x: ";
    std::cin >> x;

    // Проверка допустимости для третьего случая
    if (x >= 1 && fabs(1 / pow(x, 4)) > 1) {
        std::cout << "Ошибка: значение x слишком большое для arcsin." << std::endl;
        return 1;
    }

    // Вычисление y(x)
    double result = y(x);

    // Вывод результата
    std::cout << "y(" << x << ") = " << result << std::endl;

    return 0;
}
