#include <iostream>
using namespace std;
#include "twoNumbers.h"

void show(int i, int j)
{
    cout << "(" << i << ", " << j << ")" << endl;
}

void swap(int &a, int &b)
{
    int temp;
    temp=a;
    a=b;
    b=temp;
}

int & min(int &i, int &j)
{
    if(i<j)
        return i;
    else
        return j;
}

