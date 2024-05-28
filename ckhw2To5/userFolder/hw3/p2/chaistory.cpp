#include <iostream>
#include <string>
using namespace std;
int main(){
    string input, output;
    cin >> input;

    output = "阿財在";
    switch(input.at(0)){
        case 'M':
        case 'm':
            output += "早上"; break;
        case 'A':
        case 'a':
            output += "下午"; break;
        case 'E':
        case 'e':
            output += "晚上"; break;
        default: 
            output += "錯誤的時間";
    }

    output += "到";

    switch(input.at(1)){
        case 'S':
        case 's':
            output += "學校"; break;
        case 'R':
        case 'r':
            output += "餐廳"; break;
        case 'G':
        case 'g':
            output += "花園"; break;
        default: 
            output += "錯誤的地方";
    }

    switch(input.at(2)){
        case 'R':
        case 'r':
            output += "看書"; break;
        case 'S':
        case 's':
            output += "睡覺"; break;
        case 'W':
        case 'w':
            output += "工作"; break;
        default: 
            output += "做錯誤的事";
    }

    cout << output << endl;
    return 0;
}