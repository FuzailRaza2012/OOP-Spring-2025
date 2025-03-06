#include <iostream>
#include <string>

using namespace std;

class Person{
	public:
		string name;
		int age;
		
		Person(string n, int a) : name(n), age(a) {}
		
		virtual void displayDetails(){
			cout << "name: " << name << endl << "age: " << age << endl;
		}
};

class Teacher: virtual public Person{
	public:
		string subject;
		
		Teacher(string n, int a, string s) : Person(n, a), subject(s){}
		
		void displayDetails() override{
			Person::displayDetails();
			cout << "subject: " << subject << endl;
		}
};

class Researcher: virtual public Person{
	public:
		string researchArea;
		
		Researcher(string n, int a, string ra) : Person(n, a), researchArea(ra){}
		
		void displayDetails() override{
			Person::displayDetails();
			cout << "Research Area: " << researchArea << endl;
		}
};

class Professor: public Teacher, public Researcher{
	public:
		int publications;
		
		Professor(string n, int a, string s, string ra, int p) : Person(n, a), Teacher(n, a, s), Researcher(n, a, ra), publications(p){}
		
		void displayDetails() override{
			Person::displayDetails();
			cout << "subject" << subject << endl << "research area: " << researchArea << endl << "Number of publications: " << publications << endl;
		}
};

int main(){
	Professor professor("Akbar", 42, "Computer Science", "AI", 3);
	professor.displayDetails();
}
