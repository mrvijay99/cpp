#ifndef HEAP_H
#define HEAP_H
#include <vector>
#include <iostream>

using namespace std;
template <typename T>
class heap
{
    public:
        //heap();
        //virtual ~heap();
       // heap(const heap& other);
        //heap& operator=(const heap& other);
        void heapify(vector<T> &vect, int size, int index){
            cout << "In function " << __LINE__ <<endl;
            int largest = index;
            int left = 2 *index +1;
            int right = 2 *index +2;

            if(left < size && vect[left] > vect[largest]/*comp(vect[left], vect[largest])*/)
            {
                largest = left;
            }

            if(right < size && vect[right] > vect[largest])
            {
                largest = right;
            }
            if(index != largest)
            {
                swap(vect[index], vect[largest]);
                heapify(vect, size, largest);
            }
                }
        void buildMaxheap(vector<T> &vect, int size){
            for(int i = size/2-1;i >=0;i--)
            {
                cout << "In function " << __LINE__ <<endl;
                heapify(vect, size, i);
                cout << "In function " << __LINE__ <<endl;
            }
        }
        //void heapSort(vector<T> &vect, int n)
        void heapSort(vector<T> &vect, int n)  {
            buildMaxheap(vect, n);
            for (int i=n-1; i>=0; i--)  {
            swap(vect[0], vect[i]);
            heapify(vect, i, 0);
        }
}
    protected:

    private:
};

#endif // HEAP_H
