#include <iostream>
#include <string>
#include <vector>
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
    Date(){}

    Date(string dateStr){
        dateStr += 'E';
        this -> month = static_cast<short>(stoi(dateStr.substr(0,dateStr.find('/'))));
        dateStr[dateStr.find('/')] = '*';
        this -> day   = static_cast<short>(stoi(dateStr.substr(dateStr.find('*')+1,dateStr.find('/'))));
        this -> year  = static_cast<short>(stoi(dateStr.substr(dateStr.find('/')+1,dateStr.find('E'))));
    }

    Date(string dateStr, Locale loc){
        if(loc == US){
            dateStr += 'E';
            this -> month = static_cast<short>(stoi(dateStr.substr(0,dateStr.find('/'))));
            dateStr[dateStr.find('/')] = '*';
            this -> day   = static_cast<short>(stoi(dateStr.substr(dateStr.find('*')+1,dateStr.find('/'))));
            this -> year  = static_cast<short>(stoi(dateStr.substr(dateStr.find('/')+1,dateStr.find('E'))));
        } else if(loc == UK){
            dateStr += 'E';
            this -> day = static_cast<short>(stoi(dateStr.substr(0,dateStr.find('/'))));
            dateStr[dateStr.find('/')] = '*';
            this -> month   = static_cast<short>(stoi(dateStr.substr(dateStr.find('*')+1,dateStr.find('/'))));
            this -> year  = static_cast<short>(stoi(dateStr.substr(dateStr.find('/')+1,dateStr.find('E'))));
        } else if(loc == TW){
            dateStr += 'E';
            this -> year = static_cast<short>(stoi(dateStr.substr(0,dateStr.find('/'))));
            dateStr[dateStr.find('/')] = '*';
            this -> month   = static_cast<short>(stoi(dateStr.substr(dateStr.find('*')+1,dateStr.find('/'))));
            this -> day  = static_cast<short>(stoi(dateStr.substr(dateStr.find('/')+1,dateStr.find('E'))));
        } 
    }
    
    void setDate(string dateStr){
        dateStr += 'E';
        this -> month = static_cast<short>(stoi(dateStr.substr(0,dateStr.find('/'))));
        dateStr[dateStr.find('/')] = '*';
        this -> day   = static_cast<short>(stoi(dateStr.substr(dateStr.find('*')+1,dateStr.find('/'))));
        this -> year  = static_cast<short>(stoi(dateStr.substr(dateStr.find('/')+1,dateStr.find('E'))));
    }

    void setDate(string dateStr, Locale loc){
        if(loc == US){
            dateStr += 'E';
            this -> month = static_cast<short>(stoi(dateStr.substr(0,dateStr.find('/'))));
            dateStr[dateStr.find('/')] = '*';
            this -> day   = static_cast<short>(stoi(dateStr.substr(dateStr.find('*')+1,dateStr.find('/'))));
            this -> year  = static_cast<short>(stoi(dateStr.substr(dateStr.find('/')+1,dateStr.find('E'))));
        } else if(loc == UK){
            dateStr += 'E';
            this -> day = static_cast<short>(stoi(dateStr.substr(0,dateStr.find('/'))));
            dateStr[dateStr.find('/')] = '*';
            this -> month   = static_cast<short>(stoi(dateStr.substr(dateStr.find('*')+1,dateStr.find('/'))));
            this -> year  = static_cast<short>(stoi(dateStr.substr(dateStr.find('/')+1,dateStr.find('E'))));
        } else if(loc == TW){
            dateStr += 'E';
            this -> year = static_cast<short>(stoi(dateStr.substr(0,dateStr.find('/'))));
            dateStr[dateStr.find('/')] = '*';
            this -> month   = static_cast<short>(stoi(dateStr.substr(dateStr.find('*')+1,dateStr.find('/'))));
            this -> day  = static_cast<short>(stoi(dateStr.substr(dateStr.find('/')+1,dateStr.find('E'))));
        } 
    }

    void setDate(Date d){
        this -> month = d.month;
        this -> day   = d.day;
        this -> year  = d.year;
    }

    void setYear(short int y){
        this -> year = y;
    }

    short int getYear(){
        return year;
    }

    void setMonth(short int m){
        this -> month = m;
    }

    short int getMonth(){
        return month;
    }

    void setDay(short int d){
        this -> day = d;
    }

    short int getDay(){
        return day;
    }
    
    int compare(Date d){
        int result = 0;
        int cprYear = this -> year - d.year;
        int cprMonth = this -> month - d.month;
        int cprDay = this -> day - d.day;
        if(cprYear > 0){ // this -> year is earlier
            result = 1;
            return result;
        } else if (cprYear < 0){
            result = -1;
            return result;
        } else if(cprMonth > 0){ 
            result = 1;
            return result;
        } else if (cprMonth < 0){
            result = -1;
            return result;
        } else if(cprDay > 0){ 
            result = 1;
            return result;
        } else if (cprDay < 0){
            result = -1;
            return result;
        }
        return result;
    }

    Date *older(Date *d){
        return (this->compare(*d)>0)? d: this;
    }
    
    string toString(){
        return (to_string(month) + "/" + to_string(day) + "/" + to_string(year));
    }

    string toString(Locale loc, DateFormat formt){
        string longMonth;
        switch (this->month) {
            case 1:  longMonth = "January"; break;
            case 2:  longMonth = "February"; break;
            case 3:  longMonth = "March"; break;
            case 4:  longMonth = "April"; break;
            case 5:  longMonth = "May"; break;
            case 6:  longMonth = "June"; break;
            case 7:  longMonth = "July"; break;
            case 8:  longMonth = "August"; break;
            case 9:  longMonth = "September"; break;
            case 10: longMonth = "October"; break;
            case 11: longMonth = "November"; break;
            case 12: longMonth = "December"; break;
        }
        string longDay;
        if((day>10)&&(day<20)){
            longDay = to_string(day)+"th";
        } else {
            switch(day%10){
                case 1:
                    longDay = to_string(day)+"st"; break;
                case 2:
                    longDay = to_string(day)+"nd"; break;
                case 3:
                    longDay = to_string(day)+"rd"; break;
            }
        }

        if(loc == US){
            if(formt == Short){
                return (to_string(month) + "/" + to_string(day) + "/" + to_string(year));
            } else if(formt == Full){
                return (longMonth + " " + longDay + ", " + to_string(year));
            }
        } else if (loc == UK){
            if(formt == Short){
                return (to_string(day) + "/" + to_string(month) + "/" + to_string(year));
            } else if(formt == Full){
                return (longDay + " " + longMonth + ", " + to_string(year));
            }
        } else if(loc == TW){
            if(formt == Short){
                
                return (((year - 1912) < 0 ? to_string((year - 1912)) : to_string(year - 1911)) + "/" + to_string(month) + "/" + to_string(day));
            } else if(formt == Full){
                return "民國" + ((year - 1912) < 0 ? string("前")+to_string(-(year - 1912)) : to_string(year - 1911)) + "年" + to_string(month) + "月" + to_string(day) + "日";
            }
        }
        return NULL;
    }
};

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