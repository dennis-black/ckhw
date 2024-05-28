#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int **create2DArray(int d1, int d2){
    int **mem = new int * [d1];
    int counter = 1;
    for(int i=0; i<d1; i++){
        mem[i] = new int [d2];
    }

    for(int i=0; i<d1; i++){
        for(int j=0; j<d2; j++){
            mem[i][j] = counter++;
        }
    }

    return mem;
}

void show2DArray(int **data, int d1, int d2){
    string temp = to_string(d1*d2);
    int preserve = temp.size();
    for(int i=0; i<d1; i++){
        for(int j=0; j<d2; j++){
            // cout.fill('^');
            if(j==0) cout << setw(preserve) << data[i][j];
            else cout << setw(preserve+1) << data[i][j];
        }
        cout << endl;
    }
}
