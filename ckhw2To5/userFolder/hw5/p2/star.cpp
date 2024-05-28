#include <iostream>
#include <string>
#include <cstring>
#include "star.h"
using namespace std;

Star::Star(){
    // cout << "Star()" << endl;
    this -> address = nullptr;
    setAddress("Undef");
}

Star::Star(string name){
    // cout << "Star(string name)"<< endl;
    this -> name = name;
    this -> address = nullptr;
    setAddress("Undef");
}

Star::Star(string name, Gender gender){
    // cout << "Star(string name, Gender gender)" << endl;
    this -> name = name;
    this -> gender = gender;
    this -> address = nullptr;
    setAddress("Undef");
}

Star::Star(string name, Gender gender, string address){ 
    // cout << "Star(string name, Gender gender, string address)" << endl;
    this -> name = name;
    this -> gender = gender;
    this -> address = nullptr;
    setAddress(address);
}

Star::Star(string name, Gender gender, string birthday, string address){
    // cout << "Star(string name, Gender gender, string birthday, string address)" << endl;
    this -> name = name;
    this -> gender = gender;
    this -> birthday = Date(birthday);
    this -> address = nullptr;
    setAddress(address);
}

void Star::setName(string n){
    // cout << "setName(string n)" << endl;
    this -> name = n;
}

string Star::getName(){
    // cout << "getName()" << endl;
    return name;
}

void Star::setGender(Gender g){
    // cout << "setGender(Gender g)" << endl;
    this -> gender = g;
}

Gender Star::getGender(){
    // cout << "getGender()" << endl;
    return gender;
}

void Star::setBirthday(string s){
    // cout << "setBirthday(string s)" << endl;
    this -> birthday = Date(s);
}

void Star::setBirthday(Date d){
    // cout << "setBirthday(Date d)"<< endl;
    this -> birthday = d;
}

void Star::setBirthday(string s, Locale l){
    // cout << "setBirthday(string s, Locale l)" << endl;
    this -> birthday = Date(s, l);
}

Date Star::getBirthday(){
    // cout << "getBirthday()" << endl;
    return birthday;
}

void Star::setAddress(string s){
    // cout << "setAddress(string s)" << endl;
    if((this -> address) != nullptr){ 
        delete[] this->address;
    }
    this -> address = new char[s.size() + 1];
    strcpy(address, s.c_str());
}

string Star::getAddress(){
    // cout << "getAddress()" << endl;
    return string(this -> address);
}

void Star::setAStar(string name, Gender gender, string birthday, string address){
    // cout << "setAStar(string name, Gender gender, string birthday, string address)" << endl;
    this -> name = name;
    this -> gender = gender;
    this -> birthday = Date(birthday);
    setAddress(address);
}

