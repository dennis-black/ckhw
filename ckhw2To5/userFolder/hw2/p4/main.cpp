#include <iostream>
using namespace std;
#include "value.h"

int main()
{
    char sys_input, sys_output;
    int value;
    
    cout << "Number system for input (T/O/H):";
    cin >> sys_input;
    cout << "Input a value:";
    value=get_value(sys_input);
    cout << "Number system for output (T/O/H):";
    cin >> sys_output;
    show_value(sys_output, value);
    cout << endl;
}