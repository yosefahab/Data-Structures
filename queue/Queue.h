#ifndef __HQUEUE__
#define __HQUEUE__

namespace Hayakel {
template <typename T> class Queue {
private:
  int frontIdx, backIdx, capacity;
  T *arr;
  int elementCount;

public:
  Queue(int size = 10);
  ~Queue();
  T front();
  int length();
  bool isEmpty();
  void enQeue(T x);
  void deQeue();
  bool isFull();
};
} // namespace Hayakel
#endif
