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

Star::Star():Star("Unknown", Undef, "1/1/1900", "Undef"){}
//{
/*    Date temp;
    temp.setDate("1/1/1900");
    name="Unknown";
    gender=Undef;
    birthday=temp;
    address=NULL;
    setAddress("Undef"); */
 //   Star("Unknown", Undef, "1/1/1900", "Undef");
//}

Star::Star(string name, Gender gender, string address) : Star(name, gender, "1/1/1900", address) {} 
// {
   /*
    Date temp;
    temp.setDate("1/1/1900");
    this->name=name;
    this->gender=gender;
    this->birthday=temp;
    this->address=NULL;
    setAddress(address);
    */
 //   Star(name, gender, "1/1/1900", address);
  //  setAStar(name, gender, "1/1/1900", address);
 //   cout << "A\n" ;
//}

Star::Star(string name, Gender gender, string birthday, string address)
{
    Date temp;
    temp.setDate(birthday);
    this->name=name;
    this->gender=gender;
    this->birthday=temp;
    this->address=NULL;
    setAddress(address);
//    setAStar(name, gender, birthday, address);
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

void Star::show()
{
    cout << name << "(" <<  (gender==Male?"Male":gender==Female?"Female":"Undef") << ",";
    cout << birthday.toString() << ")";
    cout << " Address(" << strlen(address) <<") " << address << endl; 
}