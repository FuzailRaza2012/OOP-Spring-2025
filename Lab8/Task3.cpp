#include <iostream>
#include <string>
using namespace std;

class Teacher;

class Student {
    string name;
    int grades[3];

public:
    Student(string n, int g1, int g2, int g3) {
        name = n;
        grades[0] = g1;
        grades[1] = g2;
        grades[2] = g3;
    }

    friend class Teacher;
    friend float calculateAverageGrade(Student s);
};

class Teacher {
public:
    void displayGrades(Student s) {
        cout << "Grades for " << s.name << ": ";
        for(int i = 0; i < 3; i++) {
            cout << s.grades[i] << " ";
        }
        cout << endl;
    }

    void updateGrade(Student &s, int index, int newGrade) {
        if(index >= 0 && index < 3) {
            s.grades[index] = newGrade;
        }

        else {
            cout << "Invalid grade index" << endl;
        }
    }
};

float calculateAverageGrade(Student s) {
    float sum = 0;
    for(int i = 0; i < 3; i++) {
        sum += s.grades[i];
    }
    return sum / 3;
}

int main() {
    Student s("Ali", 70, 80, 90);
    Teacher t;

    t.displayGrades(s);

    float avg = calculateAverageGrade(s);
    cout << "Initial Average: " << avg << endl;

    t.updateGrade(s, 1, 95);

    t.displayGrades(s);

    avg = calculateAverageGrade(s);
    cout << "New Average: " << avg << endl;

    return 0;
}
