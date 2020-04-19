#ifndef PQUEUE_H
#define PQUEUE_H
#include <vector>
#include <iostream>
#include "heap.h"
using namespace std;

class Node{
    public:
        int element;
        unsigned int priority;
        #if 1
        friend bool operator<(const Node & obj1, const Node &obj2){
            return obj1.priority < obj2.priority;
            }

        friend bool operator>(const Node & obj1, const Node &obj2){
            return obj1.priority > obj2.priority;
            }
        #endif
        Node (int ele = 0, int pri = 0){
            element = ele;
            priority = pri;
            cout <<"Default Construct " << __FUNCTION__ <<endl;
        }

        Node (const Node &obj)
        {
            cout <<"Copy Construct  " << __FUNCTION__ <<endl;
            element = obj.element;
            priority = obj.priority;

        }
        Node (Node &&obj){
            cout <<"Move Construct  " << __FUNCTION__ <<endl;
            element = std::move(obj.element);
            priority = std::move(obj.priority);
        }
        Node& operator=(const Node& other)
        {
            cout <<"In function Copy Assignment" << __FUNCTION__ <<endl;
            element = other.element;
            priority = other.priority;
        }
};

class PQueue: public heap<Node>{
    public:
        PQueue();
        virtual ~PQueue();
        PQueue(const PQueue& other);
        PQueue& operator=(const PQueue& other);
        void insert(int element, int priorty);
        int pop();
        bool is_empty();
        bool comp(const Node &obj1, const Node &obj2);
        int peek();//returns the highest-priority element but does not modify the queue
        vector<Node> Queue;
        //TODO :: Do it using move constructor
        void swap(Node &obj1, Node &obj2){
            cout << "In function" << __FUNCTION__<< endl;
            int temp_element = std::move(obj1.element);
            int temp_priority = std::move(obj1.priority);
            obj1.element = std::move(obj2.element);
            obj1.priority = std::move(obj2.priority);
            obj2.element = std::move(temp_element);
            obj2.priority = std::move(temp_priority);
        }
    protected:

    private:

};
#endif // PQUEUE_H
