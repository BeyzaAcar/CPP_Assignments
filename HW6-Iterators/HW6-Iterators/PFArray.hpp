#ifndef PFARRAY_HPP
#define PFARRAY_HPP

#include "Iterator.hpp"

using namespace std;

namespace GTU
{
    template<class T>
    class PFArray
    {
        public:
            PFArray();
            PFArray(int capacityValue);
            PFArray(const PFArray<T>& pfa_object); /*copy constructor*/
            virtual ~PFArray( );

            void add(const T& element); /*adds an element to the data*/
            bool full( ) const; /*Test whether container is full size*/
            bool empty( ) const; /*Test whether container is empty size */
            int size( ) const; /*Return container size*/
            int getNumberUsed( ) const; /*returns used number of the container*/
            void emptyArray( ); /*empties the container*/
            void erase(Iterator<T>); /*erase an element by the given iterator*/
            void erase(Iterator<T>, Iterator<T>); /*erase element by the given iterators*/
            void erase(const int); /*erase an element from the container by the given value*/
            void resize(const int); /*changes the size of the container by the given number*/
            Iterator<T> begin() const; /*Return a  iterator to beginning*/
            Iterator<T> end() const; /*Return a iterator to end*/
            const Iterator<T> cbegin() const; /*Return a constant iterator to beginning*/
            const Iterator<T> cend() const; /*Return a constant iterator to end*/
            void print() const; /*prints the elements of the container*/
            void clear(); /*clears the container*/
            T& operator[](int);

            PFArray<T>& operator =(const PFArray<T>& rightSide);

        private:
            shared_ptr<T> T_ptr;
            int capacity;
            int used;
    };
}

/* Initializes with a capacity of 50. */
template <class T>
GTU::PFArray<T>::PFArray() :capacity(50), used(0)
{
    T_ptr = shared_ptr<T>(new T[capacity]);
}

template<class T>
GTU::PFArray<T>::PFArray(int size) :capacity(size), used(0)
{
    T_ptr = shared_ptr<T>(new T[capacity]);
}

template<class T>
GTU::PFArray<T>::PFArray(const PFArray<T>& pfaObject)
{
    T_ptr = shared_ptr<T>(new T[capacity]);

    for(int i = 0; i < used; i++)
        T_ptr.get()[i] = pfaObject.T_ptr.get()[i];
}

template<class T>
GTU::PFArray<T>::~PFArray()
{
    used = 0;
}


template<class T>
bool GTU::PFArray<T>::empty() const /* Returns true if the array is empty; false, otherwise. */
{
    return (used == 0);
}


template<class T>
bool GTU::PFArray<T>::full() const /* Returns true if the array is full; false, otherwise. */
{
    return (capacity == used);
}

template<class T>
int GTU::PFArray<T>::size() const /*Return container size*/
{
    return capacity;
}

template<class T>
int GTU::PFArray<T>::getNumberUsed() const
{
    return used;
}

/* Resets the number used to zero, effectively emptying the array. */
template<class T>
void GTU::PFArray<T>::emptyArray() /*empties the container*/
{
    used = 0;
}

template<class T>
GTU::PFArray<T>& GTU::PFArray<T>::operator =(const GTU::PFArray<T>& rightSide)
{
    if(capacity != rightSide.capacity)
    {
        this->resize(rightSide.capacity);
    }
    used = rightSide.used;

    for(int i = 0; i < used; i++)
        T_ptr.get()[i] = rightSide.T_ptr.get()[i];

    return *this;
}
template<class T>
Iterator<T> GTU::PFArray<T>::begin() const /*Return iterator to beginning*/
{
	return Iterator<T>(T_ptr);
}
template<class T>
const Iterator<T> GTU::PFArray<T>::cbegin() const /*Return a constant iterator to beginning*/
{
	return Iterator<T>(T_ptr);
}
template<class T>
Iterator<T> GTU::PFArray<T>::end() const /*Return iterator to end*/
{
	return Iterator<T>(T_ptr)+used;
}
template<class T>
const Iterator<T> GTU::PFArray<T>::cend() const /*Return constant iterator to end*/
{
	return Iterator<T>(T_ptr)+used;
}


template<class T>
void GTU::PFArray<T>::add(const T& element)
{
    if(used >= capacity)
    {
        this->resize(capacity*2);
    }
    T_ptr.get()[used] = element;
    used++;
}

template<class T>
void GTU::PFArray<T>::resize(const int new_capacity) /*changes the size of the container by the given number*/
{
    shared_ptr<T> temp (new T[new_capacity]);
    for(int i = 0;i<used;i++)
    {
        temp.get()[i] = T_ptr.get()[i];
    }
    T_ptr = nullptr;
    T_ptr = temp;
    capacity = new_capacity;
}
template<class T>
void GTU::PFArray<T>::erase(Iterator<T> remove_iter)
{
    int shift=0;
    for(auto i = this->begin(); i!= this->end(); ++i)
    {
        if(i == remove_iter) shift = 1;
        *i = *(i+shift);
    }
    if (shift == 1)used--;
}
template<class T>
void GTU::PFArray<T>::erase(Iterator<T> start, Iterator<T> end)
{
    int shift = 0;
    for(auto i = this->begin(); i!= this->end();++i)
    {
        if(i==start)
        {
            shift = end - start;
        }
        *i = *(i+shift);
    }
    if (shift == 1)used--;
}
template<class T>
void GTU::PFArray<T>::erase(const int val_to_remove) /*erase an element by the given value*/
{
    int shift = 0;
    for(auto i = this->begin();i!=this->end();++i)    
    {        
        if(*i == val_to_remove) shift = 1;
        *i = *(i+shift);
    }
    if (shift == 1)used--;
}
template<class T>
void GTU::PFArray<T>::print() const /*prints the elements of the container*/
{
    cout<<"elements in the container : \n";
    for(auto i = this->begin();i!=this->end();++i)
    {
        cout<<*i<<" ";
    }
    cout<<endl;
}
template<class T>
void GTU::PFArray<T>::clear()
{
    used = 0;
}
template<class T>
T& GTU::PFArray<T>::operator[](int index)
{
    try
    {
        if(index<used) 
        {
            Iterator<T> it(this->T_ptr);
            return it.get_row_ptr()[index];
        }
        else throw (index);
    }
    catch (int index)
    {
        cout<<"Acess denied, you are trying to access a memory space that you dont have"<<endl;
        exit(0);
        cout<<"nasi ya"<<endl;
    }
}


#endif
