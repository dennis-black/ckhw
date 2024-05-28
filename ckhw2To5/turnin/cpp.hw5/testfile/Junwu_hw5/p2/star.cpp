#include <iostream>
using namespace std;
#include "star.h"
#include <cstring>

void Star::setAddress(string s)
{
    int len;
    if(address!=NULL)
        delete [] address;

    len=s.length()+1;
    address=new char[len];
    strcpy(address,s.c_str());
}

Star::Star()
{
    setAStar("Unknown", Undef, "1/1/1900", "Undef");
}

Star::Star(string name)
{
    setAStar(name, Undef, "1/1/1900", "Undef");
}

Star::Star(string name, Gender gender)
{
    setAStar(name, gender, "1/1/1900", "Undef");
}

Star::Star(string name, Gender gender, string address)
{
    setAStar(name, gender, "1/1/1900", address);
}

Star::Star(string name, Gender gender, string birthday, string address)
{
    setAStar(name, gender, birthday, address);
}



void Star::setAStar(string name, Gender gender, string birthday, string address)
{
    Date temp;
    temp.setDate(birthday);
    this->name=name;
    this->gender=gender;
    this->birthday=temp;
    this->address=NULL;
    setAddress(address);
}

void Star::setName(string n)
{
    name=n;
}

string Star::getName()
{
    return name;
}

void Star::setGender(Gender g)
{
    gender=g;
}

Gender Star::getGender()
{
    return gender;
}

void Star::setBirthday(string s)
{
    Date d (s);
    birthday=d;
}

void Star::setBirthday(string s, Locale l)
{
    Date d (s,l);
    birthday=d;
}

void Star::setBirthday(Date d)
{
    birthday=d;
}

Date Star::getBirthday()
{
    return birthday;
}

string Star::getAddress()
{
    return address;
}
