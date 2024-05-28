#include <iostream>
using namespace std;
#include "contact.h"

int main()
{
  int i;

  Contact *mycontacts = new Contact [numContact];

  for(i=0;i<numContact;i++)
    mycontacts[i]=getAContact();


  sortContacts(mycontacts);

  for(i=0;i<numContact;i++)
    showAContact(mycontacts[i]); 
}
