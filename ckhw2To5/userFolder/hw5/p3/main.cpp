#include <iostream>
#include <string>
#include "star.h"
using namespace std;

class SHU{
private:
public:
    int room = 5;
    int index = 0;

    Star *aGroupPeople = new Star [room];

    void listAll(){
        for(int i=0; i<room; i++){
            cout << "#" << (i+1) << ": ";
            if(i<index)aGroupPeople[i].show();
            else cout << "--- empty ---" << endl;
        }
    }

    void insert(string name, Gender gender, string birthday, string address){
        if(index < room){
            aGroupPeople[index++].setAStar(name, gender, birthday, address);
        }
        else cout << "Not enough space!" << endl;
    }
    
    bool checkSpace(){
        bool val = true;
        if((index == room)||(index > room)){
            cout << "Not enough space!" << endl;
            val = false;
        }
        return val;
    }

    void memoryDoubled(){
        Star *newRoom = new Star[2 * room]; 
        for (int i = 0; i < room; i++) {
            newRoom[i] = aGroupPeople[i];
        }
        delete[] aGroupPeople;
        aGroupPeople = newRoom;
        room *= 2;
        cout << "Space doubled!" << endl;
    }
};

int main(){
    SHU jail;
    bool quit = false;
    char userCnmd;
    while(!quit){
        
        cout << "<CMD>? ";
        cin >> userCnmd;
        cin.ignore(); 
        switch(userCnmd){
            case 'i':
            case 'I':{
                if(jail.checkSpace()){
                    string inputName, inputBirthday, inputAddress;
                    char inputGender;
                    Gender insertGender;
                    cout << "Name: ";
                    getline(cin, inputName);
                    //cin.ignore();
                    cout << "Gender (F/M): ";
                    cin >> inputGender;
                    cin.ignore(); 
                    if((inputGender == 'M')||(inputGender == 'm')) insertGender = Male;
                    if((inputGender == 'F')||(inputGender == 'f')) insertGender = Female;
                    cout << "Birthday (MM/DD/YYYY): ";
                    getline(cin, inputBirthday);
                    //cin.ignore();
                    cout << "Address: ";
                    getline(cin, inputAddress);
                    //cin.ignore();
                    jail.insert(inputName, insertGender, inputBirthday, inputAddress);
                }
                break;
            }
            case 'l':
            case 'L':{
                jail.listAll();
                break;
            }

            case 'd':
            case 'D':{
                jail.memoryDoubled();
                break;
            }

            case 'q':
            case 'Q':{
                quit = true;
                break;
            }
        }
    }
}
