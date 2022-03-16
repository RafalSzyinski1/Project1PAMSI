#include <iostream>

#include "CicleList.hpp"

int main()
{
    auto cList = CicleList::createCicleList<int>(5);
    CicleList::addCicleNode(cList, 6);
    CicleList::addCicleNode(cList, 7);
    CicleList::addCicleNode(cList, 8);
    CicleList::printCicleList(cList);
    CicleList::deleteCicleList(cList);
    return 0;
}