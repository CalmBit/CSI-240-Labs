#include <stack>

class MyQueue
{
 private:
  bool stack;
  std::stack<int> stackOne;
  std::stack<int> stackTwo;
 public:
  void m_enqueue(int val);
  int m_dequeue();
  int m_peek();
  bool m_isEmpty();
};
