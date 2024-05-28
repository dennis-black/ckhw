#include <iostream>
using namespace std;
#include "star.h"
#include <string>

int main()
{
  int ssize = 5;
  int starNum = 0;
  bool quit = false;
  char cmd;
  Star *stars = new Star[10];

  while (!quit)
  {
    cout << "<CMD>? ";
    cin.get(cmd);
    cin.get();
    switch (cmd)
    {
    case 'L':
    case 'l':
      for (int i = 0; i < ssize; i++)
      {
        cout << "#" << (i + 1) << ": ";
        if (i < starNum)
          stars[i].show();
        else
          cout << "--- empty ---" << endl;
      }
      break;
    case 'i':
    case 'I':
    {
      if (starNum < ssize)
      {
        string name;
        Gender gender;
        string birthdayStr;
        string address;

        char g;
        cout << "Name: ";
        getline(cin, name);
        cout << "Gender (F/M): ";
        cin.get(g).get();
        gender = g == 'F' ? Female : Male;
        cout << "Birthday (MM/DD/YYYY): ";
        cin >> birthdayStr;
        cin.get();
        cout << "Address: ";
        getline(cin, address);
        stars[starNum++] = Star(name, gender, birthdayStr, address);
      }
      else
      {
        cout << "Not enough space!" << endl;
      }
    }
    break;
    case 'd':
    case 'D':
    {
      Star *temp;
      Star *dbSpace;

      dbSpace = new Star[ssize * 2];
      temp = stars;
      stars = dbSpace;
      for (int i = 0; i < ssize; i++)
        dbSpace[i] = temp[i];
      ssize *= 2;
      delete[] temp;
      cout << "Space doubled!" << endl;
    }
    break;
    case 'q':
    case 'Q':
      quit = true;
      break;
    }
  }
}