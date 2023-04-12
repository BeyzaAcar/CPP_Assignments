#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iostream>
#include<algorithm>
#include <memory>
#include<unistd.h>
#include<exception>

using namespace std;

template<class T>
class Iterator
{
    private :
        T* row_ptr; 

    public :
        Iterator(); /*no parameter constructor*/
        Iterator(shared_ptr<T>);
        Iterator(const Iterator&); /*copy constructor*/
        ~Iterator();

        T* get_row_ptr() const {return row_ptr;}; /*returns row_ptr*/
        T& operator *() const; /*returns *row_ptr*/
        T* operator ->() const; /*returns row_ptr*/
        Iterator<T> operator++(); /*increments row_ptr by one*/
        Iterator<T> operator++(int); /*increments row_ptr by one*/
        Iterator<T> operator--(); /*decrements row_ptr by one*/
        Iterator<T> operator--(int); /*decrements row_ptr by one*/
        Iterator<T> operator+(const int); /*increments row_ptr by one temporarily*/
        Iterator<T> operator-(const int);/*decrements row_ptr by one temporarily*/
        ptrdiff_t operator-(const Iterator&); /*Subtracts 2 iterators from each other*/
        Iterator<T>& operator=(const Iterator<T>&); /*Equalizes 2 iterators*/
        bool operator==(const Iterator<T>&) const; /*checks if two iterators are the same or not*/
        bool operator!=(const Iterator<T>&) const;/*checks if two iterators are the same or not*/
        bool operator<(const Iterator<T>&) const; /*checks if first iterator is smaller than other or not*/
        bool operator>(const Iterator<T>&) const;/*checks if first iterator is greater than other or not*/
        bool operator<=(const Iterator<T>&) const; /*checks if first iterator is equal or smaller than other or not*/
        bool operator>=(const Iterator<T>&) const ;/*checks if first iterator is equal or greater than other or not*/
        template <class A> friend Iterator<A> operator+(const int&, const Iterator<A>&); /*this enlarges the iterator by the given number.*/
        template <class A> friend Iterator<A> operator+(const Iterator<A>&, const int&); /*this enlarges the iterator by the given number.*/
        
        using	value_type = T;
			using	pointer = T*;
			using	reference = T&;
			using	difference_type = ptrdiff_t;
			using	iterator_category = random_access_iterator_tag;
};


template<class T>
Iterator<T>::Iterator() /*no parameter constructor*/
{
    row_ptr = nullptr;
}
template<class T>
Iterator<T>::Iterator(shared_ptr<T> shared)
{
    row_ptr = shared.get();
}
template<class T>
Iterator<T>::Iterator(const Iterator& copy_obj) :row_ptr(copy_obj.row_ptr) /*copy constructor*/
{
}
template<class T>
Iterator<T>::~Iterator()
{
}


template<class T>
T& Iterator<T>::operator *() const
{
    return *row_ptr;
}
template<class T>
T* Iterator<T>::operator->() const
{
    return row_ptr;
}
template<class T>
Iterator<T> Iterator<T>::operator++() /*increments row_ptr by one*/
{
    row_ptr++;
    return *this;
}
template<class T>
Iterator<T> Iterator<T>::operator++(int) /*increments row_ptr by one*/
{
    Iterator<T> temp_iterator;
    temp_iterator = *this;
    row_ptr++;
    printf("row_ptr = %d\n", row_ptr);
    return temp_iterator;
}
template<class T>
Iterator<T> Iterator<T>::operator--() /*decrements row_ptr by one*/
{
    row_ptr--;
    return *this;
}
template<class T>
Iterator<T> Iterator<T>::operator--(int) /*decrements row_ptr by one with dumb int*/
{
    Iterator<T> temp_iterator;
    temp_iterator = *this;
    this->row_ptr--;
    return temp_iterator;
}
template<class T>
Iterator<T>& Iterator<T>::operator=(const Iterator<T>& equal) /*Equalizes 2 iterators*/
{
    this->row_ptr = equal.row_ptr;
    return *this;
}
template<class T>
bool Iterator<T>::operator==(const Iterator<T>& control_obj) const /*checks if two iterators are the same or not*/
{
    return (control_obj.row_ptr == row_ptr);
}
template<class T>
bool Iterator<T>::operator!=(const Iterator<T>& control_obj) const /*checks if two iterators are the same or not*/
{
    return (control_obj.row_ptr != row_ptr);
}
template<class T>
bool Iterator<T>::operator<(const Iterator<T>& control_obj) const /*checks if first iterator is smaller than other or not*/
{
    return (row_ptr<control_obj.row_ptr);
}
template<class T>
bool Iterator<T>::operator>(const Iterator<T>& control_obj) const /*checks if first iterator is greater than other or not*/
{
    return (row_ptr>control_obj.row_ptr);
}
template<class T>
bool Iterator<T>::operator<=(const Iterator<T>& control_obj) const /*checks if first iterator is smaller than or equal to other or not*/
{
    return (row_ptr<=control_obj.row_ptr);
}
template<class T>
bool Iterator<T>::operator>=(const Iterator<T>& control_obj) const /*checks if first iterator is greater than or equal to other or not*/
{
    return (row_ptr>=control_obj.row_ptr);
}
template<class T>
Iterator<T> Iterator<T>::operator+(const int add)  /*this enlarges the iterator by the given number.*/
{
    Iterator<T>temp = *this;
    temp.row_ptr += add;
    return temp;
}
template<class T>
Iterator<T> Iterator<T>::operator-(const int remove)  /*this shrinks the iterator by the given number.*/
{
    Iterator<T>temp = *this;
    temp.row_ptr -= remove;
    return temp;
}
template<class T>
ptrdiff_t Iterator<T>::operator-(const Iterator<T>& obj) /*this shrinks the iterator by the given number.*/
{
    return this->row_ptr - obj.row_ptr;
}
template <class A> 
Iterator<A> operator+(const int& num , const Iterator<A>& obj) /*this enlarges the iterator by the given number.*/
{
	Iterator<A> temp= obj;
	temp.row_ptr = obj->get_row_ptr();
	temp.row_ptr +=num;
	return temp;
}
template <class A> 
Iterator<A> operator+(const Iterator<A>& obj, const int& num ) /*this enlarges the iterator by the given number.*/
{
	Iterator<A> temp= obj;
	temp.row_ptr = obj->get_row_ptr();
	temp.row_ptr +=num;
	return temp;
}


 #endif
