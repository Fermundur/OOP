#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_STUDENTS = 100;

// ����, �� ����������� ��������
class Student {
public:
    string surname;
    string name;
    int math;
    int physics;
    int computer_science;

    // ������� ��� ���������� ���������� ���� ��������
    float average_mark() const {
        return (math + physics + computer_science) / 3.0;
    }
};

// ������� ��������� �������� ��� ����������
bool compareStudents(const Student& s1, const Student& s2) {
    return s1.average_mark() > s2.average_mark();
}

int main() {
    // ������������ ������� ��� ��������� ��������
    vector<Student> students;

    // ³������� ����� ��� �������
    ifstream file("data.txt");
    if (file.is_open()) {
        string surname, name;
        int math, physics, computer_science;

        // ���������� ����� ��� �������� � ����� �� ��������� �� �� �������
        while (file >> surname >> name >> math >> physics >> computer_science) {
            Student student;
            student.surname = surname;
            student.name = name;
            student.math = math;
            student.physics = physics;
            student.computer_science = computer_science;
            students.push_back(student);
        }

        // �������� ����� ���� ���������� �������
        file.close();
    }
    else {
        cout << "Error opening file!" << endl;
        return 1;
    }

    // ���������� �������� �� ������� ����� � ������� ��������
    sort(students.begin(), students.end(), compareStudents);

    // ��������� ���������� ��� �������� � ������� ����� ����� 4.0
    for (const Student& student : students) {
        if (student.average_mark() > 4.0) {
            cout << student.surname << " " << student.name << ": " << student.average_mark() << endl;
        }
    }

    return 0;
}
