#ifndef MERGE_H
#define MERGE_H

#include<vector>
#include <iostream>
using namespace std;
class merge
{
    public:
        /** Default constructor */
        merge();
        /** Default destructor */
        virtual ~merge();
        /** Copy constructor
         *  \param other Object to copy from
         */
        merge(const merge& other);
        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        merge& operator=(const merge& other);
        void Sort(vector<int> &vect,vector<int> &temp_vect, int start, int end);
        void merge_vect(vector<int> &vect, vector<int> &temp_vect, int start, int mid, int end);
    protected:

    private:
};

#endif // MERGE_H
