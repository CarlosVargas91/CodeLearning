#include <memory>
#include <map>
#include <string>
#include <iostream>
#include "HotDrink.hpp"
using namespace std;

//Family of factories
struct HotDrinkFactory
{
  virtual unique_ptr<HotDrink> make() const = 0;
};

struct CoffeeFactory : HotDrinkFactory
{
  unique_ptr<HotDrink> make() const override
  {
    return make_unique<Coffee>();
  }
};

struct TeaFactory : HotDrinkFactory
{
  unique_ptr<HotDrink> make() const override {
    return make_unique<Tea>();
  }
};