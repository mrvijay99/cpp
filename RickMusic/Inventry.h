#ifndef INVENTRY_H
#define INVENTRY_H
#include<string>
#include "InstrumentSpec.h"
#include <list>
#include "guitar.h"
class Inventry
{
    public:
        /** Default constructor */
        Inventry();
        /** Default destructor */
        virtual ~Inventry();
        void add_instrument(std::string serial_num, double price, InstrumentSpec *spec)
        {
           guitarSpec *local_guitar = dynamic_cast<guitarSpec *>(spec);
           if(local_guitar)
             List.push_back(guitar(serial_num,price, *local_guitar));

        }

    protected:

    private:
        std::list<Instrument> List;
};

#endif // INVENTRY_H
