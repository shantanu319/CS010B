#include "IntVector.h"
#include <stdexcept>

IntVector::IntVector(unsigned cap, int val)
{
    _size = cap;
    _capacity = cap;
    _data = new int[cap]; // or arr[cap]
    for (unsigned i = 0; i < cap; ++i)
    {
        _data[i] = val;
    }
}

IntVector::IntVector(unsigned capacity)
{
    _size = capacity;
    _capacity = capacity;
    _data = new int[capacity];
    for (unsigned i = 0; i < capacity; ++i)
    {
        _data[i] = 0;
    }
}


IntVector::IntVector()
{
    _size = 0;
    _capacity = 0;
    _data = nullptr;
}

IntVector::~IntVector()
{
    delete[] _data;
    _data = nullptr;
}

unsigned IntVector::size() const {return _size;}
unsigned IntVector::capacity() const {return _capacity;}

bool IntVector::empty() const
{
    if (_size == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

const int & IntVector::at(unsigned index) const
{
    if (index >= _size || index < 0 || empty())
    {
        throw out_of_range("IntVector::at_range_check");
    }
    else
    {
        return _data[index];
    }
}

const int & IntVector::front() const
{
    return _data[0];
}

const int & IntVector::back() const
{
    return _data[_size - 1];
}

void IntVector::expand(unsigned n)
{
    int* newArr = new int[_capacity + n];
    for (unsigned i = 0; i < _capacity; ++i)
    {
        newArr[i] = _data[i];
    }
    _capacity += n;
    delete[] _data;
    _data = newArr;
}

void IntVector::expand()
{
    if (_capacity == 0)
    {
        expand(1);
    }
    else
    {
        expand(_capacity);
    }
    
}

int & IntVector::at(unsigned index)
{
    if (index >= _size || index < 0 || empty())
    {
        throw out_of_range("IntVector::at_range_check");
    }
    else
    {
        return _data[index];
    }
}

int & IntVector::front()
{
    return _data[0];
}

int & IntVector::back()
{
    return _data[_capacity - 1];
}

void IntVector::insert(unsigned index, int value)
{
    if (_capacity == 0)
    {
        expand(1);
    }
    if (_size == _capacity)
    {
        expand();
    }
    
    if (index > _size)
    {
        throw out_of_range("IntVector::insert_range_check");
    }
    else
    {
        for (unsigned i = _size; i > index; --i)
        {
            _data[i] = _data[i - 1];
        }
    }
    

    _data[index] = value;
    _size++;
    
}

void IntVector::push_back(int value)
{
    if (_size == _capacity)
    {
        expand();
    }

    _size++;
    _data[_size - 1] = value;
    

}

void IntVector::pop_back()
{
    _size--;
}

void IntVector::clear()
{
    _size = 0;
}

void IntVector::resize(unsigned n, int value)
{
    if (n < _size)
    {
        _size = n;
    }

    else if (n > _size)
    {
        if (n > _capacity * 2)
        {
            expand(n - _capacity);
        }
        else if (n > _capacity)
        {
            expand();
        }

        
        for (unsigned int i = _size; i < n; ++i)
        {
            _data[i] = value;
        
        }

        _size = n;
    }   
    
}

void IntVector::resize(unsigned n)
{
    resize(n,0);
}

void IntVector::assign(unsigned n, int value)
{
    if (n > _capacity * 2)
    {
        expand(n - _capacity);
    }
    else if (n > _capacity)
    {
        expand();
    }

    for (unsigned i = 0; i < n; ++i)
    {
        _data[i] = value;
    }
    _size = n;
}

void IntVector::reserve(unsigned n)
{
    if (n > _capacity)
    {
        expand(n - _capacity);
    }
}

void IntVector::erase(unsigned index)
{
    if (index >= _size)
    {
        throw out_of_range("IntVector::erase_range_check");
    }
    for (unsigned i = index; i < _size; ++i)
    {
        _data[i] = _data[i + 1];
    }
    _size--;
}