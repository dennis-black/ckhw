#include <iostream>
using namespace std;
#include "star.h"
#include <string>

int main()
{
  Star tom;

  tom.setName("Tom Cruise");
  tom.setGender(Male);
  tom.setBirthday("7/31/1962");
  tom.setAddress("No. 19, Happy Rd, NY");

  Star *kelly = new Star("Kelluy McGillis");
  kelly->setBirthday(Date("9/7/1957", UK));
  kelly->setGender(Female);

  Star val("Val Edward Kilmer", Male, "12/31/1959", "19 La Lita Ln, Santa Barbara, CA");
  Star meg("Meg Ryan", Female, "No. 101, Almond St, PA");
  meg.setBirthday(Date("12/19/1961"));

  tom.show();
  kelly->show();
  val.show();
  meg.show();
}