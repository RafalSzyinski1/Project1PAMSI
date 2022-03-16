#include <iostream>

#include "Reciver.hpp"

int main()
{
    Reciver rev;
    Data d1 = {0, "Ala"};
    Data d2 = {1, " ma "};
    Data d3 = {2, "kota"};

    rev.getData(d3);
    rev.getData(d1);
    rev.getData(d2);

    rev.printMessage();

    return 0;
}