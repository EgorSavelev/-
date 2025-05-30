#include <iostream>
#include <cmath>

const double g = 9.81;  // Ускорение свободного падения (м/с^2)
const double soundSpeed = 343.0;  // Скорость звука в воздухе (м/с)

double calculateDepth(double t) {
    // Расчет глубины шахты
    // t = время падения + время звука
    // t = sqrt(2 * h / g) + h / v_sound
    // Решаем уравнение относительно h

    double h = 0.0;
    // Две переменные для итерации
    double low = 0.0, high = t * soundSpeed;  // Глубина не может быть больше, чем максимальная глубина, при условии, что звук идет всю дорогу
    double epsilon = 0.001;  // Точность

    while (high - low > epsilon) {
        h = (low + high) / 2.0;
        double timeFall = sqrt(2 * h / g);  // Время падения камня
        double timeSound = h / soundSpeed;   // Время звука
        double totalTime = timeFall + timeSound;

        if (totalTime < t) {
            low = h;  // Увеличиваем нижнюю границу
        } else {
            high = h; // Уменьшаем верхнюю границу
        }
    }

    return h;
}

int main() {
    double t;

    // Ввод времени с клавиатуры
    std::cout << "Введите время t (в секундах): ";
    std::cin >> t;

    // Проверка корректности значения времени
    if (t <= 0) {
        std::cout << "Ошибка: время должно быть положительным." << std::endl;
        return 1;
    }

    // Вычисление глубины шахты
    double depth = calculateDepth(t);

    // Вывод результата
    std::cout << "Глубина шахты: " << depth << " метров." << std::endl;

    return 0;
}
