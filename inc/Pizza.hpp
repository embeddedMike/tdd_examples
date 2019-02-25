#pragma once
#include <chrono>
#include <list>
#include <set>
#include <string>
#include <iostream>
#include "IClock.hpp" // zeby znał minutes(typedef/using w IClock.hpp)

class Pizza {
 public:
  Pizza(std::string const &name, double price, minutes bakingTime);
  virtual ~Pizza(){std::cout << "zniszczono Pizze" << std::endl;};
  virtual std::string getName() const;
  virtual double getPrice() const;
  virtual minutes getBakingTime() const;

 private:
  std::string name_;
  double price_;
  minutes bakingTime_;
};

using Pizzas = std::set<Pizza *>;
