#ifndef GUITARSPEC_H
#define GUITARSPEC_H
#include "InstrumentSpec.h"

class guitarSpec : public InstrumentSpec
{
    public:
        /** Default constructor */
        guitarSpec();
        guitarSpec(std::string model, Builder builder, Type type, Wood topwood, Wood backwood, int num_string):InstrumentSpec(model, builder, type, topwood, backwood),m_numStrings(num_string){}
        /** Default destructor */
        virtual ~guitarSpec();

        int getNumstrings()
        {
            return m_numStrings;
        }

        bool match(guitarSpec *spec);
    protected:

    private:
        int m_numStrings;
};

#endif // GUITARSPEC_H
