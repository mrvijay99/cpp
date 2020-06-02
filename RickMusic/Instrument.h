#ifndef INSTRUMENT_H
#define INSTRUMENT_H
#include <cstring>
#include "InstrumentSpec.h"

class Instrument
{
    public:
        /** Default constructor */
        Instrument();

        Instrument(std::string serial_num, double price , InstrumentSpec spec):m_serialNumber(serial_num), m_price(price), m_spec(spec){}
        /** Default destructor */
        virtual ~Instrument();

        double get_price()const{
            return m_price;
        }
        void set_price(double price)
        {
            m_price = price;
        }

        std::string get_serial() const{
            return m_serialNumber;
        }

        InstrumentSpec get_spec() const
        {
            return m_spec;
        }
    protected:

    private:
        std::string m_serialNumber;
        double m_price;
        InstrumentSpec m_spec;

};

#endif // INSTRUMENT_H
