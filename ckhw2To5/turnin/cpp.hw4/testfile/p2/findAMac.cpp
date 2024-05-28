#include "findAMac.h"

bool findAMac(string which2buy, string *mac, int *price)
{
    bool found=false;
    int i;
    for(int i=0;i<5;i++)
    {
        if(which2buy.compare(mac[i])==0)
        {
            cout << which2buy << ":TWD " << price[i] << "." <<endl;
            int diff[5]={0};
            int j;
            for(j=0;j<5;j++)
            {
                diff[j]=price[i]>price[j]?price[i]-price[j]:price[j]-price[i];
            }
            
            int min=-1;
            for(j=0;j<5;j++)
            {
                if(diff[j]!=0)
                {
                    if(min==-1) min=j;
                    else if(diff[j]<diff[min])
                        min=j;
                }
            }
            
            cout << "You can also consider "<<mac[min]<<":TWD "<<price[min] <<"."<<endl;
            found=true;
            break;
        }
    }
    return found;
}