#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include <memory>
#include <iterator>
#include <iostream>
#include <initializer_list>
using namespace std;


template<typename type>
class Myallocator : allocator<type>{

    public:
    type *allocate (size_t size) const
    {
        return new type[size] ;
    }

    void deallocate(type *ptr, size_t size)
    {
        delete[] ptr;
    }

};

template <typename T>
class my_vector
{
    public:
        //my_vector(T element = 0, allocator_<T>);

        explicit my_vector(const Myallocator<T> &allocator_type = Myallocator<T>()):m_alloc_type(allocator_type){
            cout << "ctor" << endl;
            my_vector_size = 0;
            my_vector_capacity = 0;
        }

        explicit my_vector(int size, const Myallocator<T> &allocator_type = Myallocator<T>()):m_alloc_type(allocator_type){
            cout << "ctor with size" << endl;
            my_vector_size = size;
            my_vector_capacity = size;
        }

        explicit my_vector(size_t size, const T &value, const Myallocator<T> &allocator_type = Myallocator<T>()):m_alloc_type(allocator_type){

			cout << "ctor with size & value " << size << " & Value " << value << endl;
            buffer = allocator_type.allocate(size);
            my_vector_size = size;
            my_vector_capacity = size;
            for(auto i =0; i < size;i++)
				buffer[i] = value;
        }

        my_vector(std::initializer_list<T> init_list, const Myallocator<T> &allocator_type = Myallocator<T>()):m_alloc_type(allocator_type){
            buffer = allocator_type.allocate(init_list.size());
            my_vector_size = init_list.size();
            my_vector_capacity = init_list.size();
            auto index = 0;
            for(auto i:init_list)
            {
                buffer[index++] = i;
            }
        }


        //Copy Constructor
        my_vector(const my_vector &obj, const Myallocator<T> &allocator_type = Myallocator<T>())
        {
            my_vector_capacity = obj.my_vector_capacity;
            my_vector_size  = obj.my_vector_size;
            buffer = allocator_type.allocate(obj.my_vector_capacity);
            for(auto i = 0; i < my_vector_size;i++)
                buffer[i] = obj.buffer[i];

        }
        //Move Constructor
        my_vector(my_vector &&obj)
        {
            buffer = std::move(obj.buffer);
            my_vector_capacity = obj.my_vector_capacity;
            my_vector_size = obj.my_vector_size;
            obj.buffer = nullptr;
        }

		//Iterator Class
        class Iterator{
        public:
            Iterator(T *ele = 0){
            current = ele;
            }

            Iterator & operator=(const Iterator &rhs)
            {
                return rhs;
            }

            T& operator *()
            {
              return *current;
            }

            bool operator !=(Iterator &rhs)
            {
                return current != rhs.current;
            }
            //Postfix
            Iterator & operator ++(int unused)
            {
                current++;
                return *this;
            }
            //Prefix
            Iterator & operator ++()
            {
                current++;
                return *this;
            }

        private:
            T *current;
        };

        //End Iterator class


        T & operator[](int i)
        {
            return *(buffer +i);
        }
#if 0
        my_vector& operator[](int i)
        {
            buffer = buffer[i];
            return *this;

        }
#endif // 0

        void my_push_back(const T &element)
        {
            cout << "Push-back" << endl;
            if(my_vector_capacity <= my_vector_size)
            {
                T *temp_buffer;
                temp_buffer = m_alloc_type.allocate(my_vector_size *2);
                for(auto i = 0;i < my_vector_size;i++)
                    temp_buffer[i] = buffer[i];
              //  m_alloc_type.deallocate(buffer, my_vector_size);
              //This is supposed to be implemented in a diffrent way, but for now doint this way only
                delete[]buffer;
                buffer = nullptr;
                buffer = temp_buffer;
                my_vector_capacity = my_vector_capacity*2;
                buffer[my_vector_size++] = element;
            }
            else
            {
                buffer[my_vector_size++] = element;

            }
        }

        void push_back(T &&element)
        {
            cout << "R  value Push-back" << endl;
            if(my_vector_capacity <= my_vector_size)
            {
                T *temp_buffer;
                temp_buffer = m_alloc_type.allocate(my_vector_size *2);
                temp_buffer = std::move(buffer);
                buffer = nullptr;
                buffer = temp_buffer;

            }
        }
        int capacity() const

        {
            return my_vector_capacity;
        }

        int size() const
        {
            return my_vector_size;
        }

        Iterator begin()
        {
            return Iterator(buffer);
        }

        Iterator end()
        {
            return Iterator(buffer + my_vector_size);
        }

        virtual ~my_vector(){
        }

    protected:

    private:
        T * buffer;
        int my_vector_size;
        int my_vector_capacity;
        const Myallocator<T> m_alloc_type;

};

#endif // MY_VECTOR_H
