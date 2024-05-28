#include <iostream>
#include "date.h"
using namespace std;

enum Gender
{
    Male,
    Female,
    Undef
};

class Star
{
private:
    string name;
    Gender gender;
    Date birthday;
    char *address;

public:
    Star();
    Star(string name);
    Star(string name, Gender gender);
    Star(string name, Gender gender, string birthday, string address);
    Star(string name, Gender gender, string address);

    void setName(string n);
    string getName();
    void setGender(Gender g);
    Gender getGender();
    void setBirthday(string s);
    void setBirthday(Date d);
    void setBirthday(string s, Locale l);
    Date getBirthday();
    void setAddress(string s);
    string getAddress();
    void setAStar(string name, Gender gender, string birthday, string address);
    void show()
    {
        cout << name << "(" 
             << (gender == Male ? "Male" : gender == Female ? "Female" : "Undef")
             << "," << birthday.toString() << ") Address: " << address << endl;
    }
};