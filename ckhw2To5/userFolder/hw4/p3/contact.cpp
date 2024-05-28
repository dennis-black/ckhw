#include <iostream>
using namespace std;

#define numContact 10

enum Gender {Male, Female};

enum Month {January, February, March, April, May, June, July,
            August, September, October, November, December};

struct Date
{
  Month month;
  short day;
  short year;
};

struct Name
{
  char firstname[20];
  char lastname[10];
};

struct Contact
{
  Name name;
  Gender gender;
  Date birthday;
};

Contact getAContact(){
    //----------------------------declear varible
    short dateTemp;
    Contact person;
    string tempString;
    Gender personGender;
    Month birthMonth;
    //----------------------------handling Names
    cout << "Name: ";
    cin >> person.name.firstname;
    cin >> person.name.lastname;
    //----------------------------handling Gender
    cout << "Gender (M/F): ";
    cin >> tempString;
    if(tempString == "M") personGender = Male;
    else if(tempString == "F") personGender = Female;
    person.gender = personGender;
    //----------------------------handling birthdy
    cout << "Birthday (YYYY MM DD): ";
    cin >> person.birthday.year;
    cin >> dateTemp;
    person.birthday.month = static_cast<Month>(dateTemp-1);
    cin >> person.birthday.day;

    return person;
}

void showAContact(Contact c){
    //----------------------------handling Names
    cout << c.name.firstname << " " << c.name.lastname;
    //----------------------------handling Gender
    cout << " (" << ((c.gender==Male)? "Male":"Female") << ") ";
    //----------------------------handling birthday
    switch(c.birthday.month){
        case January: cout << "January"; break;
        case February: cout << "February"; break;
        case March: cout << "March"; break;
        case April: cout << "April"; break;
        case May: cout << "May"; break;
        case June: cout << "June"; break;
        case July: cout << "July"; break;
        case August: cout << "August"; break;
        case September: cout << "September"; break;
        case October: cout << "October"; break;
        case November: cout << "November"; break;
        case December: cout << "December"; break;
    }
    cout << " " << c.birthday.day;
    switch(c.birthday.day){
        case 1:
        case 21:
        case 31:            cout << "st"; break;
        case 2:
        case 22:
            cout << "nd"; break;
        case 3:
        case 23:
            cout << "rd"; break;
        default:
            cout << "th";
    }
    cout << ", " << c.birthday.year << "." << endl;
}

void sortContacts(Contact cs[]){
    for(int i=0; i<numContact-1; i++){
        for(int j=0; j<numContact-i-1; j++){
            if (cs[j].birthday.day < cs[j+1].birthday.day) {
                Contact temp = cs[j];
                cs[j] = cs[j+1];
                cs[j+1] = temp;
            }
        }
    }

    for(int i=0; i<numContact-1; i++){
        for(int j=0; j<numContact-i-1; j++){
            if (cs[j].birthday.month < cs[j+1].birthday.month) {
                Contact temp = cs[j];
                cs[j] = cs[j+1];
                cs[j+1] = temp;
            }
        }
    }

    for(int i=0; i<numContact-1; i++){
        for(int j=0; j<numContact-i-1; j++){
            if (cs[j].birthday.year < cs[j+1].birthday.year) {
                Contact temp = cs[j];
                cs[j] = cs[j+1];
                cs[j+1] = temp;
            }
        }
    }
}
