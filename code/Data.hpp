#pragma once

struct Data
{
    int index;
    const char* data;
};  

bool operator<(const Data& lhs, const Data& rhs)
{
    return lhs.index < rhs.index;
}

bool operator>(const Data& lhs, const Data& rhs)
{
    return lhs.index > rhs.index;
}

