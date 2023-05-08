#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_STUDENTS = 100;

// Êëàñ, ùî ïðåäñòàâëÿº ñòóäåíòà
class Student {
public:
    string surname;
    string name;
    int math;
    int physics;
    int computer_science;

    // Ôóíêö³ÿ äëÿ ðîçðàõóíêó ñåðåäíüîãî áàëó ñòóäåíòà
    float average_mark() const {
        return (math + physics + computer_science) / 3.0;
    }
};

// Ôóíêö³ÿ ïîð³âíÿííÿ ñòóäåíò³â äëÿ ñîðòóâàííÿ
bool compareStudents(const Student& s1, const Student& s2) {
    return s1.average_mark() > s2.average_mark();
}

int main() {
    // Âèêîðèñòàííÿ âåêòîðà äëÿ çáåð³ãàííÿ ñòóäåíò³â
    vector<Student> students;

    // Â³äêðèòòÿ ôàéëó äëÿ ÷èòàííÿ
    ifstream file("data.txt");
    if (file.is_open()) {
        string surname, name;
        int math, physics, computer_science;

        // Ç÷èòóâàííÿ äàíèõ ïðî ñòóäåíò³â ç ôàéëó òà äîäàâàííÿ ¿õ äî âåêòîðà
        while (file >> surname >> name >> math >> physics >> computer_science) {
            Student student;
            student.surname = surname;
            student.name = name;
            student.math = math;
            student.physics = physics;
            student.computer_science = computer_science;
            students.push_back(student);
        }

        // Çàêðèòòÿ ôàéëó ï³ñëÿ çàâåðøåííÿ ÷èòàííÿ
        file.close();
    }
    else {
        cout << "Error opening file!" << endl;
        return 1;
    }

    // Ñîðòóâàííÿ ñòóäåíò³â çà ñåðåäí³ì áàëîì â ïîðÿäêó ñïàäàííÿ
    sort(students.begin(), students.end(), compareStudents);

    // Âèâåäåííÿ ³íôîðìàö³¿ ïðî ñòóäåíò³â ç ñåðåäí³ì áàëîì á³ëüøå 4.0
    for (const Student& student : students) {
        if (student.average_mark() > 4.0) {
            cout << student.surname << " " << student.name << ": " << student.average_mark() << endl;
        }
    }

    return 0;
}
