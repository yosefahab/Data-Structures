#include "Queue.h"
#include <assert.h>
#include <string>

namespace Hayakel {
template <typename T> Queue<T>::Queue(int size) {
  capacity = size;
  arr = new T[size];
  frontIdx = backIdx = -1;
  elementCount = 0;
}

template <typename T> Queue<T>::~Queue() {
  delete[] arr;
  arr = nullptr;
}

template <typename T> T Queue<T>::front() {
  assert(!isEmpty());
  return arr[frontIdx];
}

template <typename T> void Queue<T>::deQeue() {
  assert(!isEmpty());
  frontIdx = (++frontIdx) % capacity;
  if (isEmpty()) {
    frontIdx = backIdx = -1;
  }
  elementCount--;
}

template <typename T> void Queue<T>::enQeue(T x) {
  assert(!isFull());
  backIdx = (++backIdx % capacity);
  arr[backIdx] = x;
  if (frontIdx == -1) {
    frontIdx = 0;
  }

  elementCount++;
}

template <typename T> bool Queue<T>::isEmpty() { return elementCount == 0; }

template <typename T> bool Queue<T>::isFull() {
  return elementCount == capacity;
}

template <typename T> int Queue<T>::length() { return elementCount; }

template class Queue<int32_t>;

template class Queue<int64_t>;

template class Queue<char>;

template class Queue<std::string>;

template class Queue<float>;

template class Queue<double>;
} // namespace Hayakel
