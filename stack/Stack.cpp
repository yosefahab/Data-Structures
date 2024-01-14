#include "Stack.h"
#include <assert.h>
#include <string>

namespace Hayakel {
template <typename T> Stack<T>::Stack(int capacity) {
  this->capacity = capacity;
  arr = new T[capacity];
  topIdx = 0;
}

template <typename T> Stack<T>::~Stack() {
  delete[] arr;
  arr = nullptr;
}

template <typename T> void Stack<T>::push(T x) {
  if (topIdx == capacity) {
    expand();
  }
  arr[topIdx++] = x;
}

template <typename T> void Stack<T>::pop() {
  assert(!isEmpty());
  topIdx--;
}

template <typename T> void Stack<T>::expand() {
  T *temp = new T[capacity * 2];
  for (int i = 0; i < capacity; i++) {
    temp[i] = arr[i];
  }
  capacity *= 2;
  delete[] arr;
  arr = temp;
}

template <typename T> bool Stack<T>::isEmpty() { return topIdx == 0; }

template <typename T> T Stack<T>::top() { return arr[topIdx - 1]; }

template <typename T> int Stack<T>::size() { return topIdx; }

template class Stack<int32_t>;
template class Stack<int64_t>;
template class Stack<char>;
template class Stack<std::string>;
template class Stack<float>;
template class Stack<double>;
} // namespace Hayakel
