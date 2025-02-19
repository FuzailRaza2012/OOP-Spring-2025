#include <iostream>
#include <string>

using namespace std;

class Movie;
class CinemaHall;


class Movie{
    public:
        string title;
        string director;
        int duration;   //in mins

        Movie(){
            title = "";
            director = "";
            duration = 0;
        }

        Movie(string t, string d, int du){
            title = t;
            director = d;
            duration = du;
        }

        void disp(){
            cout << "Title of the Movie: " << title << endl;
            cout << "Director's Name: " << director << endl;
            cout << "Duration: " << duration << " mins" << endl;
        }

};

class CinemaHall{
    public:
        Movie *movies;
        string hallName;
        int count;
        int total;

    CinemaHall(){
        movies = NULL;
        hallName = "";
        count = 0;
        total = 0;
    }

    CinemaHall(string hn, int t){
        hallName = hn;
        total = t;
        movies = new Movie[total];
    }

    void addMovie(string t, string d, int du){
        if (count < total){
            movies[count] = Movie(t,d, du);
            count++;
            cout << "Movie added successfully!" << endl;
        }
        else{
            cout << "The Total Movie limit has been reached!" << endl;
        }
    }

    void display(){
        cout << "Cinema Hall Name: " << hallName << endl;
        cout << "--Details of Movies being Screened--" << endl;
        for (int i = 0; i < count; i++){
            movies[i].disp();
        }
    }
};

int main(){
    CinemaHall cinema("Nuplex", 5);

    cinema.addMovie("Inception", "Christopher Nolan", 150);
    cinema.addMovie("Oppenheimer", "Christopher Nolan", 180);

    cinema.display();
}
