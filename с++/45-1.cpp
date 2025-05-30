#include <iostream>
#include <vector>

int main() {
    int rows, cols;

    // Ввод размеров массива
    std::cout << "Введите количество строк: ";
    std::cin >> rows;
    std::cout << "Введите количество столбцов: ";
    std::cin >> cols;

    // Создание двумерного массива
    std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols));

    // Ввод элементов массива
    std::cout << "Введите элементы массива:" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << "Элемент [" << i << "][" << j << "]: ";
            std::cin >> matrix[i][j];
        }
    }

    int threshold;
    std::cout << "Введите число для сравнения суммы индексов: ";
    std::cin >> threshold;

    int count = 0;

    std::cout << "Неотрицательные элементы со значениями индексов, сумма которых больше " << threshold << ":\n";

    // Поиск неотрицательных элементов с нужными индексами
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] >= 0 && (i + j) > threshold) {
                std::cout << "Элемент [" << i << "][" << j << "] = " << matrix[i][j] << std::endl;
                count++;
            }
        }
    }

    std::cout << "Количество неотрицательных элементов: " << count << std::endl;

    return 0;
}
