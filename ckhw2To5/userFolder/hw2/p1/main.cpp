#include <iostream>
#include <iomanip>
#include "string.h"
using namespace std;

int main()
{
    int w;
    char str[21];
    
    cout << "Width=? "; 
    cin >> w; 
    cout << "String=? ";
    cin >> str;
    
    show_string(str, string_length(str), w, Left_Alignment);
    show_string(str, string_length(str), w, Right_Alignment);
    show_string(str, string_length(str), w, Center_Alignment);
    
    return 0;
}