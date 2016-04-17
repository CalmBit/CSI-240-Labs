#ifndef GROCERIES_H
#define GROCERIES_H

#include <string>

#define APPLE_TYPE_COUNT 6
class Grocery
{
public:
  virtual std::string getDescription() = 0;
};

class Vegetable : public Grocery
{
protected:
  std::string name;
public:
  Vegetable();
  Vegetable(std::string name);
  ~Vegetable();
  virtual std::string getDescription();
};

class Carrot : public Vegetable
{
protected:
  bool baby;
public:
  Carrot();
  Carrot(bool baby);
  ~Carrot();
  virtual std::string getDescription();
};

class Fruit : public Grocery
{
protected:
  std::string name;
public:
  Fruit();
  Fruit(std::string name);
  ~Fruit();
  virtual std::string getDescription();
};

class Apple : public Fruit
{
public:
  enum AppleCultivars
  {
    NIL,
    MCINTOSH,
    GOLDEN_DELICIOUS,
    GALA,
    GRANNY_SMITH,
    HONEYCRISP
  };
  Apple();
  Apple(AppleCultivars appleType);
  ~Apple();
  virtual std::string getDescription();
private:
  const std::string CULTIVAR_NAMES[APPLE_TYPE_COUNT] =
  {
    "Unidentified",
    "McIntosh",
    "Golden Delicious",
    "Gala",
    "Granny Smith",
    "Honeycrisp"
  };
  AppleCultivars appleType;
};
  
#endif
