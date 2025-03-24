#include<iostream>
#include<string>
using namespace std;

class Person {
public:
    string name, id, address, phonenumber, email;

    Person(string n, string i, string addr, string phone, string mail)
        : name(n), id(i), address(addr), phonenumber(phone), email(mail) {}

    virtual void displayInfo() {
        cout << "Name: " << name << " | ID: " << id << " | Address: " << address
             << " | Phone: " << phonenumber << " | Email: " << email << endl;
    }

    void updateInfo(string n, string addr, string phone, string mail) {
        name = n; address = addr; phonenumber = phone; email = mail;
        cout << "Info updated!" << endl;
    }

    virtual ~Person() {}
};

class Student : public Person {
public:
    int coursesenrolled, enrollyear;
    float gpa;

    Student(string n, string i, string addr, string phone, string mail, int ce, float g, int ey)
        : Person(n, i, addr, phone, mail), coursesenrolled(ce), gpa(g), enrollyear(ey) {}

    void displayinfo() {
        Person::displayInfo();
        cout << "Courses: " << coursesenrolled << " | GPA: " << gpa << " | Year: " << enrollyear << endl;
    }
};

class Professor : public Person {
public:
    int coursestaught;
    double salary;
    string dept;

    Professor(string n, string i, string addr, string phone, string mail, int ce, float g, string ey)
        : Person(n, i, addr, phone, mail), coursestaught(ce), salary(g), dept(ey) {}

    void displayinfo() {
        Person::displayInfo();
        cout << "Courses: " << coursestaught << " | Salary: " << salary << " | Dept: " << dept << endl;
    }
};

class Staff : public Person {
public:
    string dep, position;
    float salary;

    Staff(string n, string i, string addr, string phone, string mail, string ce, float g, string ey)
        : Person(n, i, addr, phone, mail), dep(ce), salary(g), position(ey) {}

    void displayinfo() {
        Person::displayInfo();
        cout << "Dept: " << dep << " | Salary: " << salary << " | Position: " << position << endl;
    }
};

class Course {
private:
    string courseId, courseName;
    int credits, studentCount;
    Professor* instructor;
    Student* students[10];  

public:
    Course(string id, string name, int cr, Professor* prof)
        : courseId(id), courseName(name), credits(cr), instructor(prof), studentCount(0) {}

    void enrollStudent(Student* student) {
        if (studentCount < 10) {
            students[studentCount++] = student;
            cout << student->id << " joined " << courseName << "!" << endl;
        } else {
            cout << "Sorry, " << courseName << " is full." << endl;
        }
    }

    void displayCourseInfo() {
        cout << "\n[Course] " << courseName << " (" << courseId << ") | Credits: " << credits << endl;
        cout << "Prof: " << instructor->name << " (ID: " << instructor->id << ")" << endl;
        cout << "Students Enrolled: " << studentCount << endl;
        for (int i = 0; i < studentCount; i++) {
            cout << "- " << students[i]->name << " (ID: " << students[i]->id << ")" << endl;
        }
    }
};

int main() {
    Professor* prof = new Professor("Dr. Johnson", "P2001", "456 College Rd", "555-4321", "johnson@univ.edu", 4, 85000.0, "Mathematics");
    Student* stu1 = new Student("Charlie", "S3001", "12 Elm St", "555-6789", "charlie@univ.edu", 3, 3.9, 2024);
    Student* stu2 = new Student("Diana", "S3002", "99 Oak Ave", "555-2468", "diana@univ.edu", 4, 3.7, 2021);

    Course* course = new Course("MATH201", "Advanced Calculus", 3, prof);
    course->enrollStudent(stu1);
    course->enrollStudent(stu2);
    course->displayCourseInfo();

    delete prof;
    delete stu1;
    delete stu2;
    delete course;

    return 0;
}
