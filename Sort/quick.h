#ifndef QUICK_H
#define QUICK_H

#include<vector>
#include <iostream>
using namespace std;

class quick
{
    public:
        /** Default constructor */
        quick();
        /** Default destructor */
        virtual ~quick();
        /** Copy constructor
         *  \param other Object to copy from
         */
        quick(const quick& other);
        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        quick& operator=(const quick& other);
        void Sort(vector<int> &vect, int start, int end);
        int partition(vector<int> &vect, int start, int end);
        int selectPivot(vector<int> &vect, int start, int end);


    protected:

    private:
};

#endif // QUICK_H
