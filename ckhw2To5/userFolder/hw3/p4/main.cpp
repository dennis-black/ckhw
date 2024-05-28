#include <iostream>
#include <iomanip>
#include "10andhalf.h"
using namespace std;

int main()
{
    getCards();
    showCards();
    cout.precision(1);
    cout << fixed << calculatePoint() << " Points" << endl;
}

