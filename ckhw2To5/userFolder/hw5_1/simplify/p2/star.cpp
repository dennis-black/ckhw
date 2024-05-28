#include <iostream>
#include <string>
#include <cstring>
#include "star.h"
using namespace std;

Star::Star(){
    // cout << "calling Star()" << endl;
    this -> address = nullptr;
    setAddress("Undef");
}

Star::Star(string name){
    // cout << "calling Star(string name)"<< endl;
    setAStar(name, Male, "1/1/1111", "Undef");
}

Star::Star(string name, Gender gender){
    // cout << "calling Star(string name, Gender gender)" << endl;
    setAStar(name, gender, "1/1/1111", "Undef");
}

Star::Star(string name, Gender gender, string address){ 
    // cout << "calling Star(string name, Gender gender, string address)" << endl;
    setAStar(name, gender, "1/1/1111", address);
}

Star::Star(string name, Gender gender, string birthday, string address = "Undef"){
    // cout << "calling Star(string name, Gender gender, string birthday, string address)" << endl;
    setAStar(name, gender, birthday, address);
}

void Star::setName(string n){
    // cout << "calling setName(string n)" << endl;
    this -> name = n;
}

string Star::getName(){
    // cout << "calling getName()" << endl;
    return name;
}

void Star::setGender(Gender g){
    // cout << "calling setGender(Gender g)" << endl;
    this -> gender = g;
}

Gender Star::getGender(){
    // cout << "calling getGender()" << endl;
    return gender;
}

void Star::setBirthday(string s){
    // cout << "calling setBirthday(string s)" << endl;
    this -> birthday = Date(s);
}

void Star::setBirthday(Date d){
    // cout << "calling setBirthday(Date d)"<< endl;
    this -> birthday = d;
}

void Star::setBirthday(string s, Locale l){
    // cout << "calling setBirthday(string s, Locale l)" << endl;
    this -> birthday = Date(s, l);
}

Date Star::getBirthday(){
    // cout << "calling getBirthday()" << endl;
    return birthday;
}

void Star::setAddress(string s){
    // cout << "calling setAddress(string s)" << endl;
    if((this -> address) != nullptr){ 
        delete[] this->address;
    }
    this -> address = new char[s.size() + 1];
    strcpy(address, s.c_str());
}

string Star::getAddress(){
    // cout << "calling getAddress()" << endl;
    return string(this -> address);
}

void Star::setAStar(string name, Gender gender, string birthday, string address){
    // cout << "calling setAStar(string name, Gender gender, string birthday, string address)" << endl;
    setName(name);
    setGender(gender);
    setBirthday(birthday);
    setAddress(address);
}
