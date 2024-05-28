#include <iostream>
#include <iomanip>
#define Left_Alignment 0
#define Right_Alignment 1
#define Center_Alignment 2
using namespace std;

int string_length(char str[]){
    int count = 0;
    while(str[count]!= '\0'){
        count++;
    }
    return count;
}
void show_string(char str[], int len, int w, int align){
    double l = 0, r = 0;
    cout.fill('*');
    switch(align){
        case Left_Alignment:{
            cout << left << setw(w) << str << endl;
            break;
        }
            
        case Right_Alignment:{
            cout.fill('*');
            cout << right << setw(w) << str ;
            cout << endl;
            break;
        }
            
        case Center_Alignment:{
            l = static_cast<int>((((w-len)%2 == 0)||(w<len)) ? (w-len)/2 : (w-len)/2+1 ); //若無法整除，無條件進位
            r = l ;
            l+=len;
            r=w-l;
            cout << setw(l) << str << setw(r) << "" << endl;
            break;
        }
    }
}