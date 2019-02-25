#pragma once
#include "IClock.hpp"
#include "Pizza.hpp"
#include <chrono>
#include <ctime>
#include <string>
#include <tuple>
#include <vector>
#include <iostream>

enum class Status { New,
    Paid,
    Baked,
    Completed };

using Order = std::tuple<int, Pizzas, std::chrono::system_clock::time_point, Status>;

class Pizzeria {
public:
    Pizzeria(std::string const& name, IClock* clock);
    void showOrders();
    int makeOrder(Pizzas pizzas);
    double calculatePrice(int orderId);
    void bakePizzas(int orderId);
    //void completeOrder(int orderId);
private:
    std::string name_;
    std::vector<Order> orders_;
    IClock* clock_;
};

