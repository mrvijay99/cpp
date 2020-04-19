#include "Bubble.h"
using namespace std;
Bubble::Bubble()
{
    //ctor
}

Bubble::~Bubble()
{
    //dtor
}

void Bubble::Sort(vector<int> &vect)
{
    int temp = 0;
    for(int j = 0; j < vect.size();j++)
    {
        for(int i =0;i < vect.size() -j;i++)
        if(vect[i] > vect[i+1])
        {
            temp = vect[i];
            vect[i] = vect[i+1];
            vect[i+1] = temp;
        }
    }
}
