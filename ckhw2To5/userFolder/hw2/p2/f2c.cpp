#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    double f;
    cout << "Fahrenheit:";
    cin>>f;
cout << "Fahrenheit " << setprecision(2) << fixed << f << " = Celsius " << ((f-32)*(5/9.0)) << endl;
    return 0;
}
