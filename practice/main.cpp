#include <iostream>
#include "pointer_test.h"
#include <memory>
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
   // int i = 10;
    int j = 9;
    char *var = "Kumar";
    char *var2 = "Garg";
    pointer_test obj("Vijay");
    //unique_ptr<pointer_test, std::function<void(pointer_test *)>>  ptr(new pointer_test("Vijay"), [=](pointer_test *ptr_del){delete ptr_del;});
    auto ptr = obj.func();
    shared_ptr<pointer_test> ptr1  = std::move(ptr);
    cout << "from shared pointer "<<(*ptr1).m_name << endl;
    cout << "Test " << endl;
    return 0;
}
