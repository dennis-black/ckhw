#define numContact 10

enum Gender {Male, Female};

enum Month {January, February, March, April, May, June, July,
            August, September, October, November, December};

struct Date
{
  Month month;
  short day;
  short year;
};

struct Name
{
  char firstname[20];
  char lastname[10];
};

struct Contact
{
  Name name;
  Gender gender;
  Date birthday;
};

Contact getAContact();
void showAContact(Contact c);
void sortContacts(Contact cs[]);
