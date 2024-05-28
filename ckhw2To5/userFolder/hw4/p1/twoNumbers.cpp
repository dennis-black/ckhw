#include <iostream>
using namespace std;

void show(int i, int j){
    cout << "(" << i << ", " << j << ")" << endl;
}

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int & min(int &i, int &j){
    return (i<j)? i: j;
}
