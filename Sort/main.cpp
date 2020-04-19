#include <iostream>
#include "Bubble.h"
#include "insertion.h"
#include "quick.h"
#include "merge.h"
#include "heap.h"
#include "PQueue.h"
#include <my_vector.h>
using namespace std;
void print_arry(my_vector<int> &vect);
void Bubble_Sort(int *arr, int N);
int bubble(int *Arr, int N);

int main()
{
    int n = 8;
    my_vector<int> vec(6, 9);
    //How to implement this behaviour
    my_vector<int>::Iterator itr = vec.begin();
    print_arry(vec);
    //my_vector<int> vec1(vec);
    //my_vector<int> vec2 = {2,3,4,5};
    //cout << vec[1] << endl;
    //print_arry(vec2);
    print_arry(vec);
    cout << "Size " <<vec.size() << "Capacity " << vec.capacity() << endl;
    vec.my_push_back(n);
    cout << "Size " <<vec.size() << "Capacity " << vec.capacity() << endl;
    vec.my_push_back(std::move(10));
    print_arry(vec);
    #if 0
    heap<int> algo;
    /*
    int Arr[] = {10, 9, 8, 7, 6, 5, 4,3, 2, 1};
    print_arry(Arr, sizeof(Arr)/sizeof(int));
    Bubble_Sort(Arr,sizeof(Arr)/sizeof(int));
    print_arry(Arr, sizeof(Arr)/sizeof(int));
*/
    vector<int> vect{10, 9, 8, 7, 6, 5, 4, 10000, 10001, 5441, 7666, 7666166, 78889};
    //Bubble bub;
    //insertion algo;
    //quick algo;


    print_arry(vect);
    //bub.Sort(vect);
    vector<int> temp_vect;
    algo.heapSort(vect,vect.size());
        print_arry(vect);


    PQueue Q;
    Q.insert(5, 1);
    Q.insert(10, 10);
    Q.insert(17, 3);
    Q.insert(1000, 2);
    Q.insert(1023232, 4);

    for(auto i = 0; i < Q.Queue.size();i++)
    {
        cout << Q.Queue[i].priority << endl;
    }
    cout << endl;
    cout << Q.pop()<< Q.pop()<<endl;
    for(auto i = 0; i < Q.Queue.size();i++)
    {
        cout << Q.Queue[i].priority << endl;
    }
    return 0;
    #endif
}
#if 1
void print_arry(my_vector<int> &vect)
{

   //for(auto itr = vect.begin(); itr != vect.end();itr++)
    for(auto itr:vect)
    {
        cout << itr  << " ";
    }
    cout << endl;
}
#endif // 0
#if 0
void Bubble_Sort(int *Arr, int N)
{
    int temp = 0;
    for(int i = 0; i < N -1;i++)
    {
        if(bubble(Arr, N-i) == 0)
            break;
    }
}
int bubble(int *Arr, int N)
{
    int count = 0;
    int temp = 0;
    for(int i = 0; i < N -1;i++)
    {
        if(Arr[i] > Arr[i+1])
        {
            temp = Arr[i +1];
            Arr[i+1] = Arr[i];
            Arr[i] = temp;
            count = 1;
        }
    }
    return count;
}
#endif
