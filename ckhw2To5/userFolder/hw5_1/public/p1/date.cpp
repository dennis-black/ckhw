#include "date.h"
#include <iostream>
using namespace std;

Date::Date() {}

Date::Date(string dateStr) {
    dateStr += 'E';
    this->month = static_cast<short>(stoi(dateStr.substr(0, dateStr.find('/'))));
    dateStr[dateStr.find('/')] = '*';
    this->day = static_cast<short>(stoi(dateStr.substr(dateStr.find('*') + 1, dateStr.find('/'))));
    this->year = static_cast<short>(stoi(dateStr.substr(dateStr.find('/') + 1, dateStr.find('E'))));
}

Date::Date(string dateStr, Locale loc) {
    if (loc == US) {
        dateStr += 'E';
        this->month = static_cast<short>(stoi(dateStr.substr(0, dateStr.find('/'))));
        dateStr[dateStr.find('/')] = '*';
        this->day = static_cast<short>(stoi(dateStr.substr(dateStr.find('*') + 1, dateStr.find('/'))));
        this->year = static_cast<short>(stoi(dateStr.substr(dateStr.find('/') + 1, dateStr.find('E'))));
    }
    else if (loc == UK) {
        dateStr += 'E';
        this->day = static_cast<short>(stoi(dateStr.substr(0, dateStr.find('/'))));
        dateStr[dateStr.find('/')] = '*';
        this->month = static_cast<short>(stoi(dateStr.substr(dateStr.find('*') + 1, dateStr.find('/'))));
        this->year = static_cast<short>(stoi(dateStr.substr(dateStr.find('/') + 1, dateStr.find('E'))));
    }
    else if (loc == TW) {
        dateStr += 'E';
        this->year = static_cast<short>(stoi(dateStr.substr(0, dateStr.find('/'))));
        dateStr[dateStr.find('/')] = '*';
        this->month = static_cast<short>(stoi(dateStr.substr(dateStr.find('*') + 1, dateStr.find('/'))));
        this->day = static_cast<short>(stoi(dateStr.substr(dateStr.find('/') + 1, dateStr.find('E'))));
    }
}

void Date::setDate(string dateStr) {
    dateStr += 'E';
    this->month = static_cast<short>(stoi(dateStr.substr(0, dateStr.find('/'))));
    dateStr[dateStr.find('/')] = '*';
    this->day = static_cast<short>(stoi(dateStr.substr(dateStr.find('*') + 1, dateStr.find('/'))));
    this->year = static_cast<short>(stoi(dateStr.substr(dateStr.find('/') + 1, dateStr.find('E'))));
}

void Date::setDate(string dateStr, Locale loc) {
    if (loc == US) {
        dateStr += 'E';
        this->month = static_cast<short>(stoi(dateStr.substr(0, dateStr.find('/'))));
        dateStr[dateStr.find('/')] = '*';
        this->day = static_cast<short>(stoi(dateStr.substr(dateStr.find('*') + 1, dateStr.find('/'))));
        this->year = static_cast<short>(stoi(dateStr.substr(dateStr.find('/') + 1, dateStr.find('E'))));
    }
    else if (loc == UK) {
        dateStr += 'E';
        this->day = static_cast<short>(stoi(dateStr.substr(0, dateStr.find('/'))));
        dateStr[dateStr.find('/')] = '*';
        this->month = static_cast<short>(stoi(dateStr.substr(dateStr.find('*') + 1, dateStr.find('/'))));
        this->year = static_cast<short>(stoi(dateStr.substr(dateStr.find('/') + 1, dateStr.find('E'))));
    }
    else if (loc == TW) {
        dateStr += 'E';
        this->year = static_cast<short>(stoi(dateStr.substr(0, dateStr.find('/'))));
        dateStr[dateStr.find('/')] = '*';
        this->month = static_cast<short>(stoi(dateStr.substr(dateStr.find('*') + 1, dateStr.find('/'))));
        this->day = static_cast<short>(stoi(dateStr.substr(dateStr.find('/') + 1, dateStr.find('E'))));
    }
}

void Date::setDate(Date d) {
    this->month = d.month;
    this->day = d.day;
    this->year = d.year;
}

void Date::setYear(short int y) {
    this->year = y;
}

short int Date::getYear() {
    return year;
}

void Date::setMonth(short int m) {
    this->month = m;
}

short int Date::getMonth() {
    return month;
}

void Date::setDay(short int d) {
    this->day = d;
}

short int Date::getDay() {
    return day;
}

int Date::compare(Date d) {
    int result = 0; //預設回傳false
    int yearGap = this->year - d.year;
    int monthGap = this->month - d.month;
    int dayGap = this->day - d.day;

    if(yearGap > 0) { //如果年的差值是正的，表示引入的類別日期比較小(早)
        result = 1;
    } else if(yearGap == 0) { //如果年的差值等於0，進行下一步比較
        if(monthGap > 0) { //如果月的差值是正的，表示引入的類別日期比較小(早)
            result = 1;
        } else if(month == 0){ //如果月的差值等於0，進行下一步比較
            if(dayGap > 0) //如果日的差值是正的，表示引入的類別日期比較小(早)
                result = 1;
        }
    }
    return result;
}

Date* Date::older(Date* d) {
    return (this->compare(*d) > 0) ? d : this;
}

string Date::toString() {
    return (to_string(month) + "/" + to_string(day) + "/" + to_string(year));
}

string Date::toString(Locale loc, DateFormat formt){
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
            default:
                longDay = to_string(day)+"th"; break;
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