#include "merge.h"

merge::merge()
{
    //ctor
}

merge::~merge()
{
    //dtor
}

merge::merge(const merge& other)
{
    //copy ctor
}

merge& merge::operator=(const merge& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

void merge::Sort(vector<int> &vect, vector <int> &temp_vect, int start, int end)
{
    int temp ;
    if(start < end)
    {
        int mid = start + (end-start)/2;
        Sort(vect, temp_vect, start, mid);
        Sort(vect, temp_vect,mid + 1, end);
        merge_vect(vect, temp_vect, start, mid, end);
    }

}

void merge::merge_vect(vector<int> &vect, vector<int> &temp_vect, int start, int mid, int end)
{
    int i = start;
    int j = mid + 1;
    while(i <= mid && j <= end)
    {
        if(vect[i] < vect[j])
        {
            temp_vect.push_back(vect[i]);
            i++;
        }

        if(vect[i] >= vect[j])
        {
            temp_vect.push_back(vect[j]);
            j++;
        }
    }
    if(i <= mid)
    {
        while(i <=mid)
        {
            temp_vect.push_back(vect[i++]);
        }
    }

    if(j <= end)
    {
        while(j <=end)
        {
            temp_vect.push_back(vect[j++]);
        }
    }
}

