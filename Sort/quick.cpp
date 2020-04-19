#include "quick.h"
#include <typeinfo>
quick::quick()
{
    //ctor
}

quick::~quick()
{
    //dtor
}

quick::quick(const quick& other)
{
    //copy ctor
}

quick& quick::operator=(const quick& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

void quick::Sort(vector<int> &vect, int start, int high)
{
    if(start < high){
        int index = partition(vect, start, high);
        this->Sort(vect, start, index-1);
        this->Sort(vect, index + 1, high);
    }
}

int quick::partition(vector<int> &vect, int start, int high)
{
    int pivot = selectPivot(vect, start, high);
    int temp = 0;
    int i = start;
    int j = start;
    for(j = start; j < high; j++)
    {
        if(vect[j] < pivot)
        {
            temp = vect[j];
            vect[j] = vect[i];
            vect[i] = temp;
            i+=1;
        }
    }
    temp = vect[high];
    vect[high] = vect[i];
    vect[i] = temp;
    return i;
}

int quick::selectPivot(vector<int> &vect, int low, int high)
{
    int pivot = -1;
    int temp;
    int mid = low + (high - low)/2;
    if(vect[mid] < vect[low])
    {
        temp =  vect[mid];
        vect[mid] = vect[low];
        vect[low] = temp;
    }
    if(vect[high] < vect[low])
    {
        temp =  vect[high];
        vect[high] = vect[low];
        vect[low] = temp;

    }
    if(vect[mid] < vect[high])
    {
        temp =  vect[mid];
        vect[mid] = vect[high];
        vect[high] = temp;
    }
    pivot = vect[high];
    return pivot;
}
