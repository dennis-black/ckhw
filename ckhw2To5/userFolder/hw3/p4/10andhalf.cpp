#include <iostream>
using namespace std;

int card[5];

void getCards(){
    for(int i=0; i < 5; i++){
        cin >> card[i];
    }
}

void showACard(int i){
    if(card[i] != -1){
        double eachPoint = (card[i] % 13) + 1;
        string suit;
        if((card[i] >= 0) && (card[i] <= 12)) suit = "\u2660"; // spade
        else if((card[i] >= 13) && (card[i] <= 25)) suit = "\u2665"; // heart
        else if((card[i] >= 26) && (card[i] <= 38)) suit = "\u2666"; // diamond
        else if((card[i] >= 39) && (card[i] <= 51)) suit = "\u2663"; // club

        if(suit != ""){
            cout << "[" << suit;
            if(eachPoint == 1){ 
                cout << "A";
                eachPoint = 1;
            } else if(eachPoint > 10){ 
                if(eachPoint == 11) cout << "J";
                else if(eachPoint == 12) cout << "Q";
                else if(eachPoint == 13) cout << "K";
                eachPoint = 2000;
            } else{
                cout << eachPoint;
            }
            cout << "]";
            card[i] = eachPoint; 
        }
    }
}


void showCards(){
    for(int i=0; i<5; i++){
        showACard(i);
    }
}

double calculatePoint(){
    double total = 0;
    for(int i=0; i<5; i++){
        if(card[i]==2000)
            total += 0.5;
        else if (card[i] == -1)
            total += 0;
        else
            total += card[i];
    }
    return total;
}