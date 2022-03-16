#include <iostream>

#include "Reciver.hpp"
#include <chrono>

void test(int n, int N)
{
    using namespace std::chrono;
    time_point<high_resolution_clock> start_point, end_point;
	start_point = high_resolution_clock::now();
	for (int i = 0; i < N; ++i)
    {
        Reciver rev;
        for (int j = n; j >= 0; --j)
            rev.getData({j, "abc"});
	    start_point = high_resolution_clock::now();
        
        rev.printMessage();
    }

    end_point = high_resolution_clock::now(); 
    auto start = time_point_cast<microseconds>(start_point).time_since_epoch().count(); 
    auto end = time_point_cast<microseconds>(end_point).time_since_epoch().count();
	std::cout<<"For n = " << n << " and N = " << N << ": time taken = " << (end-start) << " microseconds" << std::endl;
}

int main()
{
    Reciver rev;
    rev.getData({1, "Ala"});
    rev.getData({3, "kota"});
    rev.getData({2, " ma "});
    rev.printMessage();

    return 0;
}

