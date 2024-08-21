#ifndef __INTVECTOR_H__
#define __INTVECTOR_H__

using namespace std;

class IntVector
{
    unsigned _size;
    unsigned _capacity;
    int *_data;
    void expand();
    void expand(unsigned n);
    public:
        IntVector(unsigned cap, int val);
        IntVector(unsigned capacity);
        IntVector();
        ~IntVector();
        unsigned size() const;
        unsigned capacity() const;
        bool empty() const;
        const int & at(unsigned index) const;
        const int & front() const;
        const int & back() const;
        int & at(unsigned index);
        int & front();
        int & back();
        void assign(unsigned n, int value);
        void push_back(int value);
        void pop_back();
        void clear();
        void resize(unsigned n, int value);
        void resize(unsigned n);
        void reserve(unsigned n);
        void insert(unsigned n, int value);
        void erase(unsigned index);

};
#endif