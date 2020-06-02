#ifndef GUITAR_H
#define GUITAR_H
#include "Instrument.h"
#include "guitarSpec.h"
class guitar : public Instrument
{
    public:
        /** Default constructor */
        guitar();
        guitar(std::string serial_num, double price, guitarSpec spec):Instrument(serial_num, price, spec){}
        /** Default destructor */
        virtual ~guitar();

    protected:

    private:
};

#endif // GUITAR_H
