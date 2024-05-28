#include "date.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
using namespace std;

Date::Date()
{
    Date("0/0/0", US);
}

Date::Date(string dateStr)
{
    setDate(dateStr, US);
}

Date::Date(string dateStr, Locale loc)
{
    setDate(dateStr, loc);
}

void Date::setDate(string dateStr, Locale loc)
{
    int p1, p2, s1, s2, s3;
    p1 = dateStr.find_first_of("/", 0);
    p2 = dateStr.find_first_of("/", p1 + 1);
    s1 = atoi(dateStr.substr(0, p1).c_str());
    s2 = atoi(dateStr.substr(p1 + 1, p2 - p1 - 1).c_str());
    s3 = atoi(dateStr.substr(p2 + 1, dateStr.length() - p2).c_str());
    switch (loc)
    {
    case TW:
        year = s1 + 1911;
        month = s2;
        day = s3;
        break;
    case US:
        month = s1;
        day = s2;
        year = s3;
        break;
    case UK:
        day = s1;
        month = s2;
        year = s3;
        break;
    }
}

void Date::setDate(Date d) { *this = d; }
void Date::setDate(string dateStr) {setDate(dateStr, US);}

void Date::setYear(short int y) { year = y; }
short int Date::getYear() { return year; }
void Date::setMonth(short int m) { month = m; }
short int Date::getMonth() { return month; }
void Date::setDay(short int d) { day = d; }
short int Date::getDay() { return day; }

Date *Date::older(Date *d)
{
    return ((getYear() * 12 + getMonth()) * 30 + getDay()) < ((d->getYear() * 12 + d->getMonth()) * 30 + d->getDay()) ? this : d;
}

int Date::compare(Date d)
{
    return ((getYear() * 12 + getMonth()) * 30 + getDay()) -
           ((d.getYear() * 12 + d.getMonth()) * 30 + d.getDay());
}

string Date::toString()
{
    // default format is US-Short
    return toString(US, Short);
}

string Date::toString(Locale loc, DateFormat format)
{
    stringstream ss;
    char Month[][11] = {"January", "February", "March", "April",
                        "May", "June", "July", "August", "September",
                        "October", "November", "December"};

    if (format == Short)
    {
        switch (loc)
        {
        case TW:
            if((year-1911)>0)
                ss << (year-1911);
            else
                ss << (year-1911-1);
            ss << "/" << month << "/" << day;
            break;
        case US:
            ss << month << "/" << day << "/" << year;
            break;
        case UK:
            ss << day << "/" << month << "/" << year;
            break;
        }
    }
    else if (format == Full)
    {
        switch (loc)
        {
        case TW:
            ss << "民國";
            if((year-1911)<=0)
                ss << "前" << (1912-year);
            else
                ss << (year - 1911);
            ss << "年" << month << "月" << day << "日";
            break;
        case US:
            ss << Month[month-1] << " " << day;
            switch (day)
            {
            case 1: case 21: case 31:
                ss << "st, "; break;
            case 2: case 22:
                ss << "nd, "; break;
            case 3: case 23:
                ss << "rd, "; break;
            default:
                ss << "th, "; break;
            }
            ss << year;
            break;
        case UK:
            ss << day;
            switch (day)
            {
            case 1: case 21: case 31:
                ss << "st "; break;
            case 2: case 22:
                ss << "nd "; break;
            case 3: case 23:
                ss << "rd "; break;
            default:
                ss << "th "; break;
            }
            ss << Month[month-1] << ", " << year;
            break;
        }
    }
    return ss.str();
}