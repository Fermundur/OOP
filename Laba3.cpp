#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_STUDENTS = 100;

// Клас, який представляє студента
class Student {
public:
    string surname;
    string name;
    int math;
    int physics;
    int computer_science;

    // Метод для обчислення середнього балу студента
    float average_mark() const {
        return (math + physics + computer_science) / 3.0;
    }
};

// Функція порівняння студентів для сортування
bool compareStudents(const Student& s1, const Student& s2) {
    return s1.average_mark() > s2.average_mark();
}

int main() {
    // Створення вектора для зберігання студентів
    vector<Student> students;

    // Відкриття файлу для зчитування
    ifstream file("data.txt");
    if (file.is_open()) {
        string surname, name;
        int math, physics, computer_science;

        // Зчитування даних про студентів з файлу та додавання до вектора
        while (file >> surname >> name >> math >> physics >> computer_science) {
            Student student;
            student.surname = surname;
            student.name = name;
            student.math = math;
            student.physics = physics;
            student.computer_science = computer_science;
            students.push_back(student);
        }

        // Закриття файлу після зчитування
        file.close();
    }
    else {
        cout << "Помилка відкриття файлу!" << endl;
        return 1;
    }

    // Сортування студентів за середнім балом у зворотньому порядку
    sort(students.begin(), students.end(), compareStudents);

    // Виведення інформації про студентів з середнім балом більше 4.0
    for (const Student& student : students) {
        if (student.average_mark() > 4.0) {
            cout << student.surname << " " << student.name << ": " << student.average_mark() << endl;
        }
    }

    return 0;
}
