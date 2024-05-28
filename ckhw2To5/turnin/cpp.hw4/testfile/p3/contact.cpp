#include <iostream>
using namespace std;
#include "contact.h"

int check(Contact a,Contact b)
{
	if(a.birthday.year<b.birthday.year)
		return 1;
	else
	{
		if(a.birthday.month<b.birthday.month)
			return 1;
		else 
		{
			if(a.birthday.day<b.birthday.day)
				return 1;
		}
	}
	return 0;
}

Contact getAContact()
{
	Contact c;
  	char genderSymbol;
	char mobileSymbol;
	char CarrierSymbol;

  	char arec[4],num[8];
	int  monthInt;
	char sizeStr[3];
	
	cout << "Name: ";
	cin >> c.name.firstname >> c.name.lastname;
	
	cout << "Gender (M/F): ";
	cin >> genderSymbol;
	
	switch(genderSymbol)
	{	
		case 'F':
			c.gender=Female;
			break;
		case 'M':
			c.gender=Male;
			break;

	}
  	cout << "Birthday (YYYY MM DD): ";
	cin >> c.birthday.year >> monthInt >> c.birthday.day;
	c.birthday.month = (Month)(monthInt-1);
	
	return c;
}
void showAContact(Contact c)
{
	cout << c.name.firstname << " " << c.name.lastname;
	
	switch(c.gender)	
	{
		case Male:
			cout << " (Male) ";
			break;
		case Female:
			cout << " (Female) ";
			break;
	}

	switch(c.birthday.month)
	{
		case 0:
			cout << "January";
			break;
		case 1:
			cout << "February";	
			break;
		case 2:
			cout << "March";	
			break;
		case 3:
			cout << "April";
			break;
		case 4:
			cout << "May";
			break;
		case 5:
			cout << "June";
			break;
		case 6:
			cout << "July";
			break;
		case 7:
			cout << "August";
			break;
		case 8:
			cout << "September";
			break;
		case 9:
			cout << "October";
			break;
		case 10:
			cout << "November";
			break;
		case 11:
			cout << "December";
			break;

	}

	cout << " " << c.birthday.day;
	
	switch(c.birthday.day)
	{
		case 1:
		case 21:
		case 31:
			cout << "st, ";
			break;
		case 2:
		case 22:
			cout << "nd, ";
			break;
		case 23:
			cout << "rd, ";
			break;
		default:
			cout << "th, ";
			break;

	}
	cout << c.birthday.year << "." << endl;
	
}
void sortContacts(Contact cs[])
{
	int i,j;
		
	for(j=0;j<numContact;j++)
	{
		for(i=0;i<numContact;i++)
		{
			if(check(cs[i],cs[i+1])==1)
			{
				Contact temp=cs[i];
				cs[i]=cs[i+1];
				cs[i+1]=temp;
			}				
			
			
		}		
	}

}
