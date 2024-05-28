#include <string>
using namespace std;

#define Error -1
#define NotSet -1
enum Locale {TW, US, UK};
enum DateFormat { Short, Full};

class Date
{
private:
    short int year;
    short int month;
    short int day;
public:    
    Date();  
    Date(string dateStr);
    Date(string dateStr, Locale loc);
    
    void setDate(string dateStr);
    void setDate(string dateStr, Locale loc);
    void setDate(Date d);

    void setYear(short int y);
    short int getYear();
    void setMonth(short int m);
    short int getMonth();
    void setDay(short int d);
    short int getDay();
    
    Date *older(Date *d);
    int compare(Date d);
    
    string toString(); 
    string toString(Locale loc, DateFormat formt);
};