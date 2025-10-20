#include <windows.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

// 🔹 Опис структури Student
// Має три поля: ПІБ, номер групи, середній бал
struct Student {
    string PIB;       // Прізвище, ім’я, по батькові
    string group;     // Номер групи
    double avgMark;   // Середній бал
};

int main() {
    // 🔹 Увімкнення підтримки української мови в консолі
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int N = 3;
    Student students[N];

    // 🔹 Введення даних
    cout << "Введіть дані про 3 студентів:\n";
    for (int i = 0; i < N; i++) {
        cout << "\nСтудент " << i + 1 << ":\n";
        cout << "ПІБ: ";
        getline(cin >> ws, students[i].PIB);
        cout << "Номер групи: ";
        getline(cin, students[i].group);
        cout << "Середній бал: ";
        cin >> students[i].avgMark;
    }

    // 🔹 Сортування за спаданням середнього балу
    sort(students, students + N, [](Student a, Student b) {
        return a.avgMark > b.avgMark;
        });

    // 🔹 Виведення таблиці у форматі трьох колонок
    cout << "\n=====================================================\n";
    cout << "| П.І.П.                     | Група   | Середній бал |\n";
    cout << "=====================================================\n";

    bool found = false;
    for (int i = 0; i < N; i++) {
        if (students[i].avgMark > 4.0) {
            cout.setf(ios::left);
            cout.width(28); cout << ("| " + students[i].PIB);
            cout.width(10); cout << ("| " + students[i].group);
            cout.width(5);  cout << ("| " + to_string(students[i].avgMark).substr(0, 4));
            cout << " |\n";
            found = true;
        }
    }

    cout << "=====================================================\n";

    if (!found) {
        cout << "Немає студентів із середнім балом більше 4.0.\n";
    }

    return 0;
}
