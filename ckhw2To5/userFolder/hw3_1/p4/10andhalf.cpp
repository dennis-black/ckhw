#include <iostream>
#include <string>

using namespace std;

int card[5]{0};

// Inputs
void getCards()
{
    for(int i = 0; i < 5; i++){
        cin >> card[i];
    }
}

double calculatePoint()
{
    double points = 0;
    for(int i = 0; i < 5; i++){

        if(card[i] == (-1))
        {
            continue;
        }

        if((card[i] % 13) < 10)
        {
            points += (card[i] % 13)+1;
        }else
        {
            points += 0.5;
        }
    }
    return points;
}



void showACard(int a)
{
    string c_sym[4] = {
        "\u2660","\u2665","\u2666","\u2663"
    };
    string p_sym[13] = {
        "A","2","3","4",
        "5","6","7","8",
        "9","10","J","Q",
        "K"
    };

    string initstr = "";

    initstr += c_sym[(a/13)];
    initstr += p_sym[(a%13)];
    
    cout << "[" << initstr << "]";
}

// Display & Outputs
void showCards()
{
    for(int i = 0; i < 5; i++)
    {
        if(card[i] == (-1))
        {
            continue;
        }else
        {
            showACard(card[i]);
        }
    }
}