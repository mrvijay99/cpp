#include "insertion.h"

insertion::insertion()
{
    //ctor
}

insertion::~insertion()
{
    //dtor
}

insertion::insertion(const insertion& other)
{
    //copy ctor
}

insertion& insertion::operator=(const insertion& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

void insertion::Sort(vector<int> &vect)
{
    for(int i = 1; i < vect.size();i++)
    {
        for(int j = i;j > 0; j--)
        {
            if(vect[i] > vect[j -1])
                shift(vect, j, i);
                break;
        }
    }
}

void insertion::shift(vector<int> &vect, int source, int times)
{
    int element = vect[times];
    cout << __FUNCTION__ <<":"<<__LINE__<< " times " << times << "source "<< source <<endl;
    for(int i = times -1; i> source;i--)
    {
        cout << __FUNCTION__ <<":"<<__LINE__<< " times " << times << "source "<< source <<endl;
        vect[i +1] = vect[i];
    }
    cout << element << endl;
    vect[source] = element;
}
