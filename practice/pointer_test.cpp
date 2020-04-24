#include "pointer_test.h"
#include <iostream>
#include <memory>

using namespace std;
pointer_test::~pointer_test()
{
    //dtor
    std::cout << "dtor" << std::endl;
}

pointer_test::pointer_test(const pointer_test& other)
{
    //copy ctor
}

pointer_test& pointer_test::operator=(const pointer_test& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

std::unique_ptr<pointer_test, std::function<void(pointer_test *)>> pointer_test:: func()
{
    std::unique_ptr<pointer_test, std::function<void(pointer_test *)>> ptr(new pointer_test("Garg"), [](pointer_test *arr){ delete arr; cout << "deleteing from lambda" << endl;});
    return ptr;


}
