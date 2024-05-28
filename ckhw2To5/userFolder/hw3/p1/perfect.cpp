#include <iostream>
using namespace std;
int main(){
    int num, addToTheSum=0;
    bool foundFlag = false;
    cout << "Please input a number: ";
    cin >> num;

    if(num <= 0) cout << "Error" << endl;
    else{
        for(int i=1; i<=num; i++){
            for(int j=1; j<=i; j++){
                if((i%j == 0)&&(i != j))
                    addToTheSum += j;
            }

            if(addToTheSum == i){
                cout << i << " is a perfect number." << endl;
                foundFlag = true;
            }
            addToTheSum = 0;
        }
        if(!foundFlag)
            cout << "Perfect number was not found!" << endl;
    }
    return 0;
}