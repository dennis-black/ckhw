#include <iostream>
using namespace std;
#include "twoNumbers.h"

int main()
{
    int x,y;
    cin >> x;
    cin >> y;

    if(x!=y)
    {
        show(x,y);
        swap(x,y);
        show(x,y);
        min(x,y)=0;
        show(x,y);
    }
    else
        cout << "Error!" << endl;
}
