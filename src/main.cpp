#include "../inc/Clock.hpp"
#include "../inc/Funghi.hpp"
#include "../inc/Margherita.hpp"
#include "../inc/Pizzeria.hpp"
#include <iostream>
#include <tuple>
#include <ctime>

enum GameStates { Main_Menu = 7, Exit, Playing, Options };
//enum class GameStates2 { Main_Menu = 7, Exit, Playing, Options }; //Conflict???
enum class GameStates2 { Exit = 1, Main_Menu };

std::ostream& operator<<(std::ostream& os, GameStates2 gs2)
{
    return os << static_cast<int>(gs2);
}

using PizzasTest = std::set<Pizza*>;
using OrderTest = std::tuple<PizzasTest>;
std::vector<OrderTest> orders_test;

int main() {
  
  //******************rozmiar std::set w vectorze tupli******
  /*
  PizzasTest pizzasTest = {new Margherita{25.0}, new Funghi{35.0}, new Funghi{21.0}};
  orders_test.push_back(std::make_tuple(pizzasTest));
  std::vector<OrderTest>::iterator it = orders_test.begin();
  auto tmp = std::get<0>(*it);
  std::cout << tmp.size() << std::endl;
  */
  
  
  //******************std::chrono********************
  /*
  minutes backingTime(2);
  IClock *time = new Clock();
  time->waitFor(backingTime);
  std::cout << "hello" << std::endl;
  */
  
  //******************std::set********************
  /*
  Pizzas pizzas = {new Margherita{25.0}, new Funghi{35.0}};
  Pizzas pizzas2 = {new Margherita{35.0}, new Funghi{45.0}};
  for (Pizzas::iterator it = pizzas.begin(); it != pizzas.end(); ++it) {
    std::cout << *it << std::endl;
    std::cout << (*it)->getPrice() << std::endl;
  }
  */

  //******************enum and enum class********************
  /*
  GameStates gameState = Exit;
  std::cout << gameState << std::endl;
  GameStates2 gameState2 = GameStates2::Exit;
  std::cout << gameState2 << std::endl;
  */

  //******************std::tuple********************
  /*
  std::tuple<int, std::string, char> t(32, "rychu", 'a');
  std::cout << std::get<0>(t) << std::endl;
  std::cout << std::get<1>(t) << std::endl;
  */

  //*****************std::chrono a std::cout*********************
  /*
  std::chrono::time_point<std::chrono::system_clock> time_point;
  time_point = std::chrono::system_clock::now();
  std::time_t ttp = std::chrono::system_clock::to_time_t(time_point);
  std::cout << "time: " << std::ctime(&ttp);
  */

  
  //kolejnosc wywolania konstruktorow do sprawdzenia w gdb//
  Margherita marg1(25.0);
  /*
  Pizzas pizzas = {new Margherita{25.0}, new Funghi{35.0}};
  Pizzas pizzas2 = {new Margherita{35.0}, new Funghi{45.0}};

  Pizzeria bravo("Pizzeria Bravo", new Clock());

  auto orderId = bravo.makeOrder(pizzas);
  std::cout << orderId << std::endl;

  orderId = bravo.makeOrder(pizzas2);
  std::cout << orderId << std::endl;

  std::cout << "zamowienie o id: " << orderId <<" całkowita cena to: " << bravo.calculatePrice(orderId) << std::endl;
  std::cout << "teraz bedzie wywolanie bakePizzas" << std::endl;
  bravo.bakePizzas(orderId);
  bravo.showOrders();
  */
}
