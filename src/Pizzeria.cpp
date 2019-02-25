#include "../inc/Pizzeria.hpp"
#include <numeric>
#include <algorithm>
#include <thread>
#include <iostream>

std::ostream& operator<<(std::ostream& os, Status status) {
  return os << static_cast<int>(status);
}

Pizzeria::Pizzeria(std::string const& name, IClock* clock)
    : name_(name) , orders_() , clock_(clock) {}

int Pizzeria::makeOrder(Pizzas pizzas) {
  int orderId = rand() % 1000;  // 0-999
  orders_.push_back(std::make_tuple(
      orderId, pizzas, std::chrono::system_clock::now(), Status::New));
  return orderId;
}

double Pizzeria::calculatePrice(int orderId) {
  auto order = std::find_if(orders_.begin(),orders_.end(), [orderId](const auto & order)
          {
            //std::cout << "Argument przekazany do lambdy:" << orderId << std::endl;
            return std::get<0>(order) == orderId;
          });
  //std::cout << "Id zamowienia znalezionego:" << std::get<0>(*order) << std::endl;
  if (order != orders_.end()) {
    std::get<Status>(*order) = Status::Paid;
    auto pizzas = std::get<Pizzas>(*order);
    return std::accumulate(pizzas.begin(), pizzas.end(), 0.0,
                           [] (double previousSum, Pizza* pizza) {
      return previousSum + pizza->getPrice();
      });

  }
  return 0;
}

void Pizzeria::bakePizzas(int orderId) {
  auto order = std::find_if(orders_.begin(), orders_.end(), [orderId](const auto & order)
  {
      return std::get<0>(order) == orderId;
  });
  if(order != orders_.end())
  {
    auto pizzas = std::get<Pizzas>(*order);
    for(const auto & pizza : pizzas)
    {
      std::cout << "Baking" << pizza->getName() << std::endl;
      clock_->waitFor(pizza->getBakingTime());
    }
    std::get<Status>(*order) = Status::Baked;
  }
}

void Pizzeria::showOrders() {
  /*for (std::vector<Order>::iterator it = orders_.begin(); it != orders_.end(); ++it) {
    std::cout << std::get<0>(0) << std::endl;
    //std::cout << std::get<1>(*it) << std::endl;
    //std::cout << std::get<2>(*it) << std::endl;
    //std::cout << std::get<3>(*it) << std::endl;
  }*/
  std::chrono::time_point<std::chrono::system_clock> time_point;
  for(int i = 0; i < orders_.size(); i++) {
    auto setTemp = std::get<1>(orders_[i]);
    time_point = std::get<2>(orders_[i]);
    std::time_t ttp = std::chrono::system_clock::to_time_t(time_point);
    std::cout << "Id zamowienia " << i  << " to:" << std::get<0>(orders_[i]) << std::endl;
    for(Pizzas::iterator it = setTemp.begin(); it != setTemp.end(); it++) {
      std::cout << "cena pizzy " << (*it)->getName() << " to: " << (*it)->getPrice() << std::endl;
    }
    std::cout << "Godzina złożenia zamowienia " << i  << " to:" << std::ctime(&ttp);
    std::cout << "Status zamowienia " << i  << " to:" << std::get<3>(orders_[i]) << std::endl;
  }
}

