#ifndef INSERTION_H
#define INSERTION_H
#include <iostream>
#include <vector>
using namespace std;
class insertion
{
    public:
        /** Default constructor */
        insertion();
        /** Default destructor */
        virtual ~insertion();
        /** Copy constructor
         *  \param other Object to copy from
         */
        insertion(const insertion& other);
        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        insertion& operator=(const insertion& other);
        void Sort(vector <int> &vect);

    protected:

    private:
        void shift(vector<int> &vect, int source, int desr);
};

#endif // INSERTION_H
