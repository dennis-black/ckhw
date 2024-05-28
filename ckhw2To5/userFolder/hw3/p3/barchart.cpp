#include <iostream>
using namespace std;
int main(){

    int input[7];
    int output[7][10]={false};

    for(int i = 0; i < 7; i++){
        cin >> input[i];
    }

    for(int i = 0; i < 7; i++){
        for(int j = 0; j < input[i]; j++){
            output[i][j] = true;
        }
    }
    
    for(int i = 9; i >= 0; i--){
        for(int j = 0; j < 7; j++){
            if(output[j][i] == true)
                if(j == 6)
                    cout << "#";
                else
                    cout << "# ";

            else
                if(j == 6)
                    cout << ".";
                else
                    cout << ". ";
        }
        cout << endl;
    }
    cout << "1 2 3 4 5 6 7" << endl;
    return 0;
}