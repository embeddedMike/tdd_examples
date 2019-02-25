#include <gtest/gtest.h>
#include <string>
#include "../inc/Clock.hpp"
#include "../inc/Funghi.hpp"
#include "../inc/Margherita.hpp"
#include "../inc/Pizzeria.hpp"
#include "mocks/DummyClock.hpp"

using namespace ::testing;

struct PizzeriaTest : public ::testing::Test {
 public:
  MockClock* mock = new StrictMock<MockClock>{};
  Pizzeria pizzeria = Pizzeria("dummyName", mock);

  // DummyClock() dziedziczy po IClock --> własna implementacja metody waitFor
  // ---> pusta implementacja, dlatego odcięcie czasu pieczenia od testu
  // new DummyClock() ---> ???
  // Pizzeria pizzeria = Pizzeria("Pizzeria Bravo", new DummyClock());

  // new Clock() ---> tutaj zadziała implementacja z std::chrono, nie będzie
  // odcięcia zależności od testu
  // Pizzeria pizzeria = Pizzeria("Pizzeria Bravo", new Clock());

  ~PizzeriaTest() { delete mock; }
};

TEST_F(PizzeriaTest, priceForMargherita25AndFunghi30ShouldBe55) {
  // Given
  Pizzas pizzas = {new Margherita{25.0}, new Funghi{30.0}};

  // When
  auto orderId = pizzeria.makeOrder(pizzas);
  auto price = pizzeria.calculatePrice(orderId);

  // Then
  ASSERT_EQ(55, price);
}

TEST_F(PizzeriaTest, bakeDummyPizza) {
  // Given
  // Pizzas pizzas = {new PizzaDummy{}};
  Pizzas pizzas = {new Margherita{25.0}, new Funghi{30.0}};

  EXPECT_CALL(*mock, waitFor(_));

  // When
  auto orderId = pizzeria.makeOrder(pizzas);
  pizzeria.bakePizzas(orderId);
}
