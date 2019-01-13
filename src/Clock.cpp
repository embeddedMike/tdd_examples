#include "../inc/Clock.hpp"
#include <thread>

void Clock::waitFor(minutes m)
{
    std::this_thread::sleep_for(m);
}
