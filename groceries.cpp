#include "groceries.hpp"
#include <sstream>
#include <string>

// class Vegetable

Vegetable::Vegetable()
{
  this->name = "";
}

Vegetable::Vegetable(std::string name)
{
  this->name = name;
}

Vegetable::~Vegetable()
{
  
}

std::string Vegetable::getDescription()
{
  return std::string { "A fresh " };
}


// class Carrot

Carrot::Carrot() : Vegetable("Carrot")
{
  this->baby = false;
}

Carrot::Carrot(bool baby) : Vegetable("Carrot")
{
  this->baby = baby;
}

Carrot::~Carrot()
{
  
}

std::string Carrot::getDescription()
{
  return Vegetable::getDescription() + (baby ? "baby " : "") + "carrot.";
}

// class Fruit

Fruit::Fruit()
{
  this->name = "";
}

Fruit::Fruit(std::string name)
{
  this->name = name;
}

Fruit::~Fruit()
{
  
}

std::string Fruit::getDescription()
{
  return "A ripe ";
}


// class Apple

Apple::Apple()
{
  this->appleType = NIL;
}

Apple::Apple(AppleCultivars appleType)
{
  this->appleType = appleType;
}

Apple::~Apple()
{
  
}

std::string Apple::getDescription()
{
  return Fruit::getDescription() + CULTIVAR_NAMES[(int)this->appleType] + " apple.";
}

