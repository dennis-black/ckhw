#include <iostream>
using namespace std;
#include "Movie.h"

int main()
{
    Movie tg1 ("Top Gun", 1986, 110, Action);
    Star tom {"Tom Cruise"};
    Star tim;
    tim.setName("Tim Robbins");
    Star *kelly = new Star("Kelluy McGillis");
    Star fake1 ("fake 1");
    Star fake2 ("fake 2");

    tg1.addStar(tom);
    tg1.addStar(tim);
    tg1.addStar(*kelly);
    tg1.addStar(fake1);
    tg1.addStar(fake2);
    tg1.showInfo();
    tg1.removeStar(fake1);
    tg1.removeStar(tim);
    tg1.removeStar(fake2);
    tg1.showInfo();
}   