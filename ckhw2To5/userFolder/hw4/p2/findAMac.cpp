#include <iostream>
#include <math.h>
#include <string>
using namespace std;

bool findAMac(string which2buy, string *mac, int *price){
    bool foundFlag = false;
    int payment = 0;
    int gap = price[5];
    string nextTarget;
    int nextTargetPrice = 0;
    for(int i=0; i<6; i++){
        if(which2buy==mac[i]){
            foundFlag = true;
            cout << which2buy << ":TWD " << price[i] << "." << endl;
            payment =  price[i];
        }
    }

    if(foundFlag == false){
        return 0;
    } else {
        cout << "You can also consider ";

        for(int i=0; i<6; i++){
            if((abs(payment - price[i])<gap)&&(payment != price[i])){
                gap = abs(payment - price[i]);
                nextTarget = mac[i];
                nextTargetPrice = price[i];
            }
        }
        cout << nextTarget << ":TWD " << nextTargetPrice << "." << endl;
        return true;
    }
}
