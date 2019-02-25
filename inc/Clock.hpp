#pragma once
#include "IClock.hpp"

struct Clock : public IClock {
  void waitFor(minutes m) override;
};
