#include <iostream>
#include <string>
#include "star.h"
using namespace std;

int main() {
    int room = 5;
    int index = 0;
    Star* aGroupPeople = new Star[room];
    bool quit = false;
    char userCmd;

    while (!quit) {
        cout << "<CMD>? ";
        cin >> userCmd;
        cin.ignore();

        switch (userCmd) {
            case 'i':
            case 'I': {
                if (index < room) {
                    string inputName, inputBirthday, inputAddress;
                    char inputGender;
                    Gender insertGender;

                    cout << "Name: ";
                    getline(cin, inputName);
                    cout << "Gender (F/M): ";
                    cin >> inputGender;
                    cin.ignore();
                    if ((inputGender == 'M') || (inputGender == 'm')) insertGender = Male;
                    if ((inputGender == 'F') || (inputGender == 'f')) insertGender = Female;
                    cout << "Birthday (MM/DD/YYYY): ";
                    getline(cin, inputBirthday);
                    cout << "Address: ";
                    getline(cin, inputAddress);

                    aGroupPeople[index].setAStar(inputName, insertGender, inputBirthday, inputAddress);
                    index++;
                } else {
                    cout << "Not enough space!" << endl;
                }
                break;
            }
            case 'l':
            case 'L': {
                for (int i = 0; i < room; i++) {
                    cout << "#" << (i + 1) << ": ";
                    if (i < index) aGroupPeople[i].show();
                    else cout << "--- empty ---" << endl;
                }
                break;
            }
            case 'd':
            case 'D': {
                Star* newRoom = new Star[2 * room];
                for (int i = 0; i < room; i++) {
                    newRoom[i] = aGroupPeople[i];
                }
                delete[] aGroupPeople;
                aGroupPeople = newRoom;
                room *= 2;
                cout << "Space doubled!" << endl;
                break;
            }
            case 'q':
            case 'Q': {
                quit = true;
                break;
            }
        }
    }
    return 0;
}