#include "MyQueue.h"
#include <iostream>

int main(int argc, char* argv[])
{
  MyQueue queue{};
  for(int i = 0;i < 10;i++)
  {
    queue.m_enqueue(i);
  }
  std::cout << "First item (peek):" << queue.m_peek() << std::endl;
  std::cout << "First item (dequeue):" << queue.m_dequeue() << std::endl;
  std::cout << "Second item (peek):" << queue.m_peek() << std::endl;
  std::cout << "Second item (dequeue):" << queue.m_dequeue() << std::endl;
  while(!queue.m_isEmpty())
  {
    std::cout << queue.m_dequeue() << std::endl;
  }
  std::cin.get();
  return 0;
}
