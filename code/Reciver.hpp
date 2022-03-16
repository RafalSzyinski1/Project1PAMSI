#pragma once

#include <iostream>

#include "Heap.hpp"
#include "Data.hpp"

class Reciver
{
    public:
        Reciver();
        void getData(Data data);
        void printMessage();
    private:
        Heap<Data> mData;
};

Reciver::Reciver()
: mData()
{ }

void Reciver::getData(Data data)
{
    mData.insert(data);
}

void Reciver::printMessage()
{
    auto vec = mData.sort();
    for (int i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i].data;
    }
    std::cout << std::endl;
}
