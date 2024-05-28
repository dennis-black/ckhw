#include <iostream>
using namespace std;

#include "Movie.h"

Movie::Movie(string t, int y, int l, Genre g)
{
    title=t;
    year=y;
    length=l;
    genre=g;
    stars=NULL;
    numStars=0;
}

void Movie::setTitle(string t) 
{ 
    title=t;
}

void Movie::setYear(int y)
{ 
    year=y; 
}

void Movie::setLength(int l)
{ 
    length=l; 
}

void Movie::setGenre(Genre g)
{ 
    genre=g; 
}

string Movie::getTitle()
{ 
    return title; 
}

int Movie::getYear()
{ 
    return year; 
}

int Movie::getLength()
{ 
    return length; 
}

Genre Movie::getGenre()
{
    return genre; 
}

void Movie::removeStar(Star s)
{
    int i,j;
    if(stars!=NULL)
    {
        for(i=0;i<numStars;i++)
        {
            if(stars[i].getName()==s.getName())
            {
                numStars--;
                break;
            }
        }
        for(j=i;j<numStars;j++)
        {
            stars[j]=stars[j+1];
        }
    }
}

void Movie::addStar(Star s)
{
    if(stars==NULL)
        stars = new Star [5];
    stars[numStars++]=s;
}

void Movie::showStars()
{
    cout << "[Stars:";
    if(numStars)
    {
        cout << stars[0].getName(); 
        for(int i=1;i<numStars;i++)
            cout << ", " << stars[i].getName();
    }
    else
    {
        cout << "None";
    }
    cout << "]" << endl;
}

void Movie::showInfo()
{
    string genreName[]={"Undefined", "Drama", "SciFi", "Comedy", "Action"};
    cout << "|Movie|"<< title << "[" << genreName[genre] << "]" 
         << "(" << length << ")" << endl;
    showStars();
}



