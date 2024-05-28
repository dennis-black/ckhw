#include <iostream>
using namespace std;
int get_value(char sys){
    int base;
    switch(sys){
        case 'O':
            cin >> oct >> base;
            break;
        case 'T':
            cin >> dec >>base;
            break;
        case 'H':
            cin >> hex >>base;
            break;
    }
    return base;
}

void show_value(char sys, int value){
    switch(sys){
        case 'O':
            cout << oct << value;
            break;
        case 'T':
            cout << dec << value;
            break;
        case 'H':
            cout << hex << uppercase << value;
            break;
    }
}