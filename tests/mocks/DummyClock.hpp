#pragma once
#include <gmock/gmock.h>
#include "../../inc/IClock.hpp"
struct DummyClock : public IClock {
  void waitFor(minutes) {}
};

struct MockClock : public IClock {
  // MOCK_METHODx(nazwa_metody,typ_zwracany(argumenty));
  // x - liczba argumentów
  MOCK_METHOD1(waitFor, void(minutes));
};
