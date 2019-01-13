#include <iostream>
#include "../inc/Clock.hpp"

int main() 
{
    minutes backingTime(2);
    IClock* time = new Clock();
    time->waitFor(backingTime);
    std::cout << "hello" << std::endl;
}
