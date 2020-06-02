#include <iostream>
#include "Inventry.h"
#include "guitarSpec.h"
using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    Inventry invent;
    InstrumentSpec *pointer = new guitarSpec("VIJAY",MARTIN,ELECTRIC,MAPLE,ROSEWOOD,5);
    invent.add_instrument("123456", 14.65, pointer);
    return 0;
}
