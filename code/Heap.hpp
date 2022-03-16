#pragma once

#include <cmath>

#include "Vector.hpp"

template <typename T>
class Heap
{
    public:
        Heap();
        void insert(T value);
        Vector<T> sort();
    private:
        void heapify(int index);
        void swap(int lhs, int rhs);

        int parnet(int index) { return std::ceil(index / 2.f) - 1; }
        int left(int index) { return (2 * index) + 1; }
        int right(int index) { return (2 * index) + 2; }
    private:
        Vector<T> mTab;
        int mSize;
};

template <typename T>
Heap<T>::Heap()
: mTab()
, mSize(0)
{ }

template <typename T>
void Heap<T>::insert(T value)
{
    ++mSize;
    mTab.push(value);
    int i = mSize - 1;
    while ((i > 0) && (mTab[parnet(i)] < mTab[i]))
    {
        mTab.swap(i, parnet(i));
        i = parnet(i);
    }
}

template<typename T>
Vector<T> Heap<T>::sort()
{
    for (int i = (mSize - 1); i >= 1; --i)
    {
        mTab.swap(0, i);
        --mSize;
        heapify(0);
    }
    return mTab;
}

template <typename T>
void Heap<T>::heapify(int index)
{
    int l = left(index);
    int r = right(index);
    int largest = index;
    if ((l < mSize) && (mTab[l] > mTab[largest]))
    {
        largest = l;
    }
    if ((r < mSize) && (mTab[r] > mTab[largest]))
    {
        largest = r;
    }
    if (largest != index)
    {
        mTab.swap(index, largest);
        heapify(largest);
    }
}