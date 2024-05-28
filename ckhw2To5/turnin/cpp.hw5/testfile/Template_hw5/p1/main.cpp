#include <iostream>
using namespace std;
#include "date.h"

int main()
{
    string dateStr;
    int m,d,y;

    Date d1 ("9/11/2021"); // 若無指定日期格式，預設為US
    Date d2;
    Date *d3, *d4=new Date("113/5/19", TW);
    Date d5;
    Date *older;

    cout << "Please input a date (US: MM/DD/YYYY): ";
    cin >> dateStr;    
    d2.setDate(dateStr);  // 若無指定日期格式，預設為US
    
    cout << "Please input a date (UK: DD/MM/YYYY): ";
    cin >> dateStr;
    d3=new Date();
    d3->setDate(dateStr,UK);

    d4->setDate(*d3);

    d4->setYear(d4->getYear()-1);
    
    cout << "Month: ";
    cin >> m;
    d5.setMonth(m);
    cout << "Day: ";
    cin >> d;
    d5.setDay(d);
    cout << "Year: ";
    cin >> y;
    d5.setYear(y);

    cout << "d1:" << endl;
    cout << "Default: " << d1.toString() << endl;
    cout << "US: "      << d1.toString(US, Short) << endl;
    cout << "UK: "      << d1.toString(UK, Short) << endl;
    cout << "TW: "      << d1.toString(TW, Short) << endl;
    cout << "US-F: "    << d1.toString(US, Full) << endl;
    cout << "UK-F: "    << d1.toString(UK, Full) << endl;
    cout << "TW-F: "    << d1.toString(TW, Full) << endl;

    cout << "d2:" << endl;
    cout << "Default: " << d2.toString() << endl;
    cout << "US: "      << d2.toString(US, Short) << endl;
    cout << "UK: "      << d2.toString(UK, Short) << endl;
    cout << "TW: "      << d2.toString(TW, Short) << endl;
    cout << "US-F: "    << d2.toString(US, Full) << endl;
    cout << "UK-F: "    << d2.toString(UK, Full) << endl;
    cout << "TW-F: "    << d2.toString(TW, Full) << endl;
    
    cout << "d3:" << endl;
    cout << "Default: " << d3->toString() << endl;
    cout << "US: "      << d3->toString(US, Short) << endl;
    cout << "UK: "      << d3->toString(UK, Short) << endl;
    cout << "TW: "      << d3->toString(TW, Short) << endl;
    cout << "US-F: "    << d3->toString(US, Full) << endl;
    cout << "UK-F: "    << d3->toString(UK, Full) << endl;
    cout << "TW-F: "    << d3->toString(TW, Full) << endl;

    cout << "d4:" << endl;
    cout << "Default: " << d4->toString() << endl;
    cout << "US: "      << d4->toString(US, Short) << endl;
    cout << "UK: "      << d4->toString(UK, Short) << endl;
    cout << "TW: "      << d4->toString(TW, Short) << endl;
    cout << "US-F: "    << d4->toString(US, Full) << endl;
    cout << "UK-F: "    << d4->toString(UK, Full) << endl;
    cout << "TW-F: "    << d4->toString(TW, Full) << endl;
    
    cout << "d5:" << endl;
    cout << "Default: " << d5.toString() << endl;
    cout << "US: "      << d5.toString(US, Short) << endl;
    cout << "UK: "      << d5.toString(UK, Short) << endl;
    cout << "TW: "      << d5.toString(TW, Short) << endl;
    cout << "US-F: "    << d5.toString(US, Full) << endl;
    cout << "UK-F: "    << d5.toString(UK, Full) << endl;
    cout << "TW-F: "    << d5.toString(TW, Full) << endl;

    cout << endl;

    if(d2.compare(*d3)==0)
    {
        cout << "d2 is equal to d3.\n";
    }
    else
    {
        older=d3->older(&d2);
        cout << "The date " << older->toString() << " is earlier than ";
        if(d3->compare(d2)>0)
            cout << d3->toString() << ".\n";
        else
            cout << d2.toString() << ".\n"; 
    }
    
}   