#ifndef __HStack__
#define __HStack__

namespace Hayakel {
template <typename T> class Stack {
private:
  int topIdx, capacity;
  T *arr;
  void expand();

public:
  Stack(int size = 10);
  ~Stack();
  T top();
  int size();
  void pop();
  void push(T x);
  bool isEmpty();
};
} // namespace Hayakel
#endif
