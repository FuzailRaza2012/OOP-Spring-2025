#include <iostream>
#include <string>

using namespace std;

class TourGuide;
class TravelAgency;

class TourGuide {
    public:
        string name;
        int yearsOfExperience;
        string specialization;

        TourGuide(){
            name = "";
            yearsOfExperience = 0;
            specialization = "";
        }

        TourGuide(string n, int yof, string s){
            name = n;
            yearsOfExperience = yof;
            specialization = s;
        }

        void display(){
            cout << "Name of Guide: " << name << endl;
            cout << "Years Of Experience: " << yearsOfExperience << endl;
            cout << "Specializes in " << specialization << endl;
        }

};

class TravelAgency {
    public:
        TourGuide *tourguides;
        string agency;
        int count;
        int total;

        TravelAgency(){
            agency = "";
            count = 0;
            total = 0;
            tourguides = NULL;
        }

        TravelAgency(string a, int t){
            agency = a;
            count = 0;
            total = t;
            tourguides = new TourGuide[total];
        } 

        ~TravelAgency(){
            delete[] tourguides;
        }

        void addTGuide(TourGuide *tguide){
            if (count < total){
                tourguides[count] = *tguide;
                count++;
                cout << "Tour guide added successfully!" << endl;
            }
            else{
                cout << "Maximum limit has been reached!" << endl;
            }
        }

        void disp(){
            cout << "Travel Agency Name: " << agency << endl;
            cout << "--Tour Guides--" << endl;
            for (int i = 0; i < count; i++){
                tourguides[i].display();
            }
        }
};

int main(){
    TourGuide guide1("John", 1, "Historical Places");
    TourGuide guide2("Kareem", 2, "Cultural Showcase");
    TourGuide guide3("Abdul", 3, "Adventure Trips");

    TravelAgency agency1("Travel Trips", 5);

    agency1.addTGuide(&guide1);
    agency1.addTGuide(&guide2);
    agency1.addTGuide(&guide3);

    agency1.disp();
}
