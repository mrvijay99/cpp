#ifndef POINTER_TEST_H
#define POINTER_TEST_H
#include <string>
#include <iostream>
#include <memory>
class pointer_test
{
    public:
        /** Default constructor */
        pointer_test();
        pointer_test(std::string var):m_name(var){
        std::cout << "ctor " << var << std::endl;
        };
        /** Default destructor */
        virtual ~pointer_test();
        /** Copy constructor
         *  \param other Object to copy from
         */
        pointer_test(const pointer_test& other);
        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        pointer_test& operator=(const pointer_test& other);
        std::unique_ptr<pointer_test, std::function<void(pointer_test *)>> func();
        std::string m_name;
    protected:

    private:

};

#endif // POINTER_TEST_H
