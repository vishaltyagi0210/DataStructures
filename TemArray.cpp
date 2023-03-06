
#include<iostream>
using namespace std;
template<typename X>
class Array
{
    private:
        X* array;
        int capacity;
        int lastIndex;
    public:
        Array(int);
        void append(X);
        void insert(int , X);
        void edit(int , X);
        X getElement(int);
        bool isfull();
        bool isEmpty();
        int count();
        ~Array();
        int find(X);
        void del(int);
};

template<typename X>Array<X>::Array(int cap)
{
    array = new X[cap];
    capacity = cap;
    lastIndex = -1;
}

template<typename X>int Array<X>::find(X data)
{
    for(int i = 0; i < capacity; i++)
    {
        if(array[i] == data)
            return i;
    }
    return -1;
}

template<typename X>Array<X>::~Array()
{
    delete[] array;
}

template<typename X>void Array<X>::append(X data)
{
    if(lastIndex != capacity-1)
    {
        array[++lastIndex] = data;
    }
    else
    {
        cout<<"array is full\n";
    }
}

template<typename X>void Array<X>::insert(int index , X data)
{
    if(!isfull())
    {
        if(index <= lastIndex+1)
        {
            for(int i = lastIndex; i>=index; i--)
            {
                array[i+1] = array[i];
            }
            array[index] = data;
            lastIndex++;
        }
    }
}

template<typename X>void Array<X>::edit(int index , X data)
{
    if(!isEmpty())
    {
        if(index <= lastIndex)
            array[index] = data;
    }
}

template<typename X>X Array<X>::getElement(int index)
{
    if(!isEmpty())
    {
        if(index <= lastIndex)
            return array[index];
        else
            return -1;
    }
}

template<typename X>void Array<X>::del(int index)
{
    if(!isEmpty())
    {
        if(index <= lastIndex)
        {
            for(int i = index; i<lastIndex; i++)
                array[i] = array[i+1];
            lastIndex--;
        }
    }
}

template<typename X> int Array<X>::count()
{
    return lastIndex+1;
}

template<typename X>bool Array<X>::isfull()
{
    return (lastIndex==capacity-1);
}
template<typename X>bool Array<X>::isEmpty()
{
    return lastIndex == -1;
}