#pragma once
#include <chrono>

using minutes = std::chrono::seconds;

struct IClock
{
    virtual void waitFor(minutes m) = 0;
    virtual ~IClock() {};
};
