#include <iostream>
#include <random>

#include "Functions.h"

int main(int argc, char* argv[])
{
  size_t size = 0;
  size = promptSize();
  int *arr = new int[size];
  populate(size, arr);
  selection_sort(size, arr);
  display(size, arr);
  delete[] arr;
  return 0;
}

size_t promptSize()
{
  int arraySize = 0;
  do
  {
    std::cout << "Enter a size for the array: ";
    std::cin >> arraySize;
    if(arraySize <= -1) std::cout << "Hey! That's not a valid size!" << std::endl;
  } while(arraySize <= 1);
  return arraySize;
}

void populate(size_t size, int *ptr)
{
  std::cout << "Setting up randomness...";
  std::default_random_engine engine{std::random_device{}()};
  std::uniform_int_distribution<int> distr{1,50};
  std::cout << "done!" << std::endl << "Populating array with " << size << " random entries...";
  for(size_t i = 0;i < size;i++)
  {
    ptr[i] = distr(engine);
  }
  std::cout << "done!" << std::endl;
}

void display(size_t size, int *ptr)
{
  std::cout << "Here's the array requested!" << std::endl;
  for(size_t i = 0;i < size;i++)
  {
    std::cout << "At Offset " << i << " - " << ptr[i] << std::endl;
  }
  std::cout << "Finished!" << std::endl;
}

void bubble_sort(size_t size, int *ptr)
{
  int comps = 0;
  size_t compSize = 0;
  std::cout << "Sorting the array via bubble sort...";
  do
  {
    for(size_t i = 0;i < size-compSize;i++)
    {
      if(ptr[i] > ptr[i+1])
      {
	int temp = ptr[i];
	ptr[i] = ptr[i+1];
	ptr[i+1] = temp;
      }
      comps++;
    }
    compSize++;
  } while(compSize < size);
  std::cout << "done!" << std::endl << "Total comparisons: " << comps << std::endl;
}

void selection_sort(size_t size, int *ptr)
{
  int comps = 0;
  std::cout << "Sorting the array via selection sort...";
  for(size_t i = 0;i < size-1;i++)
  {
    for(size_t j = i;j < size;j++)
    {
      if(ptr[i] > ptr[j])
      {
	int temp = ptr[i];
	ptr[i] = ptr[j];
	ptr[j] = temp;
      }
    }
  }
  std::cout << "done!" << std::endl;
}
