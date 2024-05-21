
#include <windows.h>
#include <iostream>
#include <cmath> 
using namespace std;


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    const int rows = 3;
    const int col = 5;
    double matrix[rows][col];


    // Ввод элементов двумерного массива с клавиатуры

    for (int i = 0; i < rows; ++i) {

        cout << "Введите элементы " << i + 1 << "-й строки (через пробел): ";

        for (int j = 0; j < col; ++j) {

            cin >> matrix[i][j];
        }

    }
    cout << "\nСредние арифметические элементов строк:\n";
    for (int i = 0; i < rows; ++i) {

        double sum = 0;

        for (int j = 0; j < col; ++j) {

            sum += matrix[i][j];
        }

        double average = sum / col;

        cout << "Среднее элементов " << i + 1 << "-й строки: " << average << endl;
    }
    double sum_all = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < col; ++j) {

            sum_all += matrix[i][j];
        }

    }
    double average_all = sum_all / (col*rows);
    cout << "Среднее элементов всех строк: " << average_all << endl;

    return 0;

}