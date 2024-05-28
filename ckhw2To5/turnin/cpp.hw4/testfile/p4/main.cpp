#include <iostream>
using namespace std;
#include "dynamic2DArray.h"

int main()
{
  int **data;
  int i, j, d1, d2;
  
  cout << "Dimension 1: ";
  cin >> d1;
  cout << "Dimension 2: ";
  cin >> d2;

  data=create2DArray(d1, d2);  
  show2DArray(data, d1, d2);
 
  for(int i=0;i<d1; i++)
    delete [] data[i];
 
  delete [] data;
 
  return 0;
}