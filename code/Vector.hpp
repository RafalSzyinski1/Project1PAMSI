#pragma once

#include <cassert>
#include <cstring>

template <typename T>
class Vector
{
    public:
        Vector();
        Vector(const Vector& vec);
        ~Vector();
        void push(T value);
        T pop();
        T& operator[](int index);
        const T& operator[](int index) const;
        int size();
        void swap(int lhs, int rhs);
    private:
        T* mTab;
        int mSize;
        int mCapacity;
};

template<typename T>
Vector<T>::Vector()
: mCapacity(1)
, mSize(0)
{
    mTab = new T[1];
}

template<typename T>
Vector<T>::Vector(const Vector& vec)
{
    mSize = vec.mSize;
    mCapacity = vec.mCapacity;
    mTab = new T[mCapacity];
    memcpy(mTab, vec.mTab, sizeof(T) * mCapacity);
}

template<typename T>
Vector<T>::~Vector()
{
    delete[] mTab;
}

template<typename T>
void Vector<T>::push(T value)
{
    if (mSize == mCapacity)
    {
        T* temp = new T[2 * mCapacity];
        memcpy(temp, mTab, sizeof(T) * mCapacity);
        delete[] mTab;
        mCapacity *= 2;
        mTab = temp;
    }

    mTab[mSize] = value;
    ++mSize;
}

template<typename T>
T Vector<T>::pop()
{
    return mTab[mSize--];
}

template<typename T>
T& Vector<T>::operator[](int index)
{
    assert(index < mSize);
    return mTab[index];
}

template<typename T>
const T& Vector<T>::operator[](int index) const
{
    assert(index < mSize);
    return mTab[index];
}

template<typename T>
int Vector<T>::size()
{
    return mSize;
}

template<typename T>
void Vector<T>::swap(int lhs, int rhs)
{
    T value = mTab[lhs];
    mTab[lhs] = mTab[rhs];
    mTab[rhs] = value;
}

/*

Strasznie wczoraj zakodowałem. Pisałem PAMSI do piątej nad ranem.
Film mi się urwał jak kończyłem linie. Teraz mi kompilator wywliło.
Trochę się przespałem, ale musiałem wstać rano bo mam obowiązki. Mam wykład.
Niektórczy mówią, że nie można kodować do rana jak się ma o 7 wykład, ale to nieprawda.
Można, tylko trzeba wstawać wcześnie. Na tym polega odpowiedzialność.

*/