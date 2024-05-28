#include <iostream>
using namespace std;
int main(){
    char type, quantity, grade, isCsie;
    double fee;
    int fare;
    cin >> type >> quantity >> grade >> isCsie;
    if((!((type>='A')&&(type<='C'))||!((quantity>='1')&&(quantity<='9')||(quantity=='T'))||!((grade>='1')&&(grade<='6')||!((isCsie=='C')||(isCsie=='N'))))){
        cout << "Error!" << endl;
    } else { 
        quantity = (quantity=='T')? 10: (quantity - '0');
        grade = grade - '0';
        isCsie = (isCsie == 'C')? 1 : 0;

        switch(type){
            case 'A': {
                fee = 20*quantity; 
                break;
            }
            case 'B': {
                fee = 10*quantity; 
                break;
            }
            case 'C': {
                fee = 23*quantity; 
                break;
            }
        }

        if(isCsie) fee*=0.6;

        if(quantity == 10) fee*=0.8;
        else if(grade == 1) fee*=0.9;
        fare = static_cast<int>(fee);
        fare = (fare!=fee)? fare+1: fare;

        cout << "Fare=" << fare << endl;
    }
}