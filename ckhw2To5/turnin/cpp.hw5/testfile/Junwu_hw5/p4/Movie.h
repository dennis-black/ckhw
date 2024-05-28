#include <iostream>
using namespace std;

#include "Star.h"

typedef enum {Undefined=0, Drama, SciFi, Comedy, Action} Genre;

class Movie
{
private:
    string title;
    int year;
    int length;
    Genre genre;
    Star *stars;
    int numStars;
public:
    Movie(string t, int y, int l, Genre g);
    void setTitle(string t);
    void setYear(int y);
    void setLength(int l);
    void setGenre(Genre g);
    string getTitle();
    int getYear();
    int getLength();
    Genre getGenre();
    void removeStar(Star s);
    void addStar(Star s);
    void showStars();
    void showInfo();
};


