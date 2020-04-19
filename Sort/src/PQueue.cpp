#include "PQueue.h"
#include "heap.h"
PQueue::PQueue()
{
    //ctor
}

PQueue::~PQueue()
{
    //dtor
}

PQueue::PQueue(const PQueue& other)
{
    //copy ctor
}

PQueue& PQueue::operator=(const PQueue& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

bool PQueue::comp(const Node &obj1, const Node &obj2)
{
    if(obj1.priority > obj2.priority)
        return true;
    else
        return false;
}

bool PQueue::is_empty(){
    if(Queue.size() == 0)
            return true;
    else
        return false;
}
int PQueue::pop(){
    if(Queue.size() != 0){
        int element = Queue[Queue.size() -1].element;
        Queue.pop_back();
        buildMaxheap(Queue, Queue.size());
        swap(Queue[0], Queue[Queue.size() -1]);
        return element;
    }
    return -1;
}





int PQueue::peek()
{
    return Queue[Queue.size() -1].element;
}

void PQueue::insert(int element, int priorty)
{
    cout << "Test 1 " << __LINE__ << endl;
    Queue.push_back(Node(element,priorty));
    cout << "Test 1 " << __LINE__ << endl;
    buildMaxheap(Queue, Queue.size());
    cout << "Test 1 " << __LINE__ << endl;
    swap(Queue[0], Queue[Queue.size() -1]);
}
