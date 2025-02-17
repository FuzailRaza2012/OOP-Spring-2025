#include <iostream>
#include <string>

using namespace std;

class Professors;
class University;

class Professors {
    public:
        string name;
        string department;

        Professors(){
            name = "";
            department = "";
        }

        Professors(string na, string d){
            name = na;
            department = d;
        }
};

class University {
    public:
        Professors *professors;
        string uni;
        int count = 0;
        int max = 10;

        University(string u){
            uni = u;
            professors = new Professors[max];
        }

        ~University(){
            if (professors){
                delete[] professors;
            }
            
        }

        void addprofs(string na, string dept){
            if (count < max){
                professors[count] = Professors(na, dept);
                count++;
            }
            else{
                cout << "Maximum Teachers reached!" << endl;
            }
        }

        void display();
};

void University:: display(){
    cout << "--University Details--" << endl;
    for (int i = 0; i < count; i++){
        cout << "For Professor " << i + 1 << endl;
        cout << "Name: " << professors[i].name << endl;
        cout << "Department: " << professors[i].department << endl;
    }
}

int main(){
    University uni("FAST");

    uni.addprofs("Sir Akbar", "Computer Sciences");
    uni.addprofs("Sir Hakeem", "AI & DS");
    uni.addprofs("Sir Dablu", "S.E.");

    uni.display();
}
