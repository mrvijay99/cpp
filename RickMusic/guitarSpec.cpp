#include "guitarSpec.h"

guitarSpec::guitarSpec()
{
    //ctor
}

guitarSpec::~guitarSpec()
{
    //dtor
}

bool guitarSpec::match(guitarSpec *spec){
    if(spec->get_backwood() != this->get_backwood())
    {
        return false;
    }
#if 0
    if(spec.get_topwood() != m_backwood)
    {
        return false;
    }

    if(spec.get_backwood() != m_topwood)
    {
        return false;
    }

    if(spec.get_type() != m_type)
    {
        return false;
    }
    if(spec.get_builder() != m_builder)
    {
        return false;
    }
    if(spec.getNumstrings() != m_numStrings)
    {
        return false;
    }
    #endif
    return true;
}
