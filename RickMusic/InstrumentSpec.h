#ifndef INSTRUMENTSPEC_H
#define INSTRUMENTSPEC_H
#include "helper.h"
#include <string>
class InstrumentSpec
{
    public:
        /** Default constructor */
        InstrumentSpec();
        InstrumentSpec(std::string model, Builder builder, Type type, Wood topwood, Wood backwood):m_model(model),m_builder(builder), m_type(type), m_topwood(topwood), m_backwood(backwood){}
        Builder get_builder()
        {
            return m_builder;
        }

        Type get_type()
        {
            return m_type;
        }

        Wood get_topwood(){
            return m_topwood;
        }
        Wood get_backwood()
        {
            return m_backwood;
        }
        /** Default destructor */
        virtual ~InstrumentSpec();
        virtual bool match(InstrumentSpec *spec){};
    protected:

    private:
        std::string m_model;
        Builder m_builder;
        Type m_type;
        Wood m_topwood;
        Wood m_backwood;
};

#endif // INSTRUMENTSPEC_H
