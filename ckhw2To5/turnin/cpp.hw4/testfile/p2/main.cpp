#include<iostream>
using namespace std;
#include "findAMac.h"

int main()
{
    string mac[6]={"MacBook Air", 
                   "MacBook Pro", 
                   "iMac", 
                   "Mac Mini", 
                   "Mac Studio",
                   "Mac Pro"};
    int price[6]= { 41900,
                    54900,
                    44900,
                    24900,
                    64999,
                   229900 }; 
    
    string which2buy;
    bool found=false;
    
    cout << "Which Mac do you want to buy?";
    getline(cin, which2buy);

    found=findAMac(which2buy, mac, price);    

    if(!found)
    {
        cout << "Not Found!" << endl;
    }
}
