
#include <vector>
#include <iostream>
#include "groceries.hpp"

int main(int argc, char* argv[])
{
  std::vector<Grocery*> groceryBasket;
  groceryBasket.push_back(new Carrot {true});
  groceryBasket.push_back(new Apple {Apple::GRANNY_SMITH});

  std::cout << "The groceries in my basket are:" << std::endl;
  for(size_t i = 0; i < groceryBasket.size();i++)
  {
    std::cout << groceryBasket[i]->getDescription() << std::endl;
  }
  std::cin.get();
  return 0;
}
