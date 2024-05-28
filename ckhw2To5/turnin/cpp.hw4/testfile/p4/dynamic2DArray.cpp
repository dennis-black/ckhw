using namespace std;
#include <iostream>

int **create2DArray(int d1, int d2)
{
  int i,j,k=1;
  int **data;
  data= new int * [d1];
  for(int i=0;i<d1;i++)
  {
    data[i] = new int [d2];
  }

  for(i=0;i<d1;i++)
    for(j=0;j<d2;j++)
      data[i][j] = k++;
  return data;
}

void show2DArray(int **data, int d1, int d2)
{
  int i,j;
  for(i=0;i<d1;i++)
  {
    for(j=0;j<d2;j++)
    {
      cout << data[i][j] << " " ;
    }
    cout << endl;
  }
}
 
