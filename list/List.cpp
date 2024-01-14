#include "List.h"
#include <assert.h>
#include <iostream>

namespace Hayakel {
template <typename T> List<T>::List() {
  count = 0;
  size = 5;
  arr = new T[5];
}

template <typename T> List<T>::~List() {
  delete[] arr;
  arr = nullptr;
}

template <typename T> int List<T>::length() { return this->count; }

template <typename T> int List<T>::capacity() { return this->size; }

template <typename T> void List<T>::expand() {
  size *= 2;
  T *temp = new T[size];
  for (int i = 0; i < count; i++) {
    temp[i] = arr[i];
  }
  delete[] arr;
  arr = temp;
}

template <typename T> void List<T>::append(T x) {
  if (count == size) {
    expand();
  }
  arr[count++] = x;
}

template <typename T> T List<T>::at(int pos) {
  assert(pos >= 0 && pos < count);
  return arr[pos];
}

template <typename T> void List<T>::display() {
  for (int i = 0; i < count; i++) {
    std::cout << arr[i] << ' ';
  }
  std::cout << '\n';
}

template <typename T> void List<T>::deleteAt(int pos) {
  for (int i = pos; i < count - 1; i++) {
    arr[i] = arr[i + 1];
  }
  count--;
}

template <typename T> void List<T>::inserAt(int pos, T x) {
  assert(pos >= 0 && pos < count);
  if (count == size) {
    expand();
  }

  for (int i = count; i > pos; i--) {
    arr[i] = arr[i - 1];
  }
  arr[pos] = x;
  count++;
}

template class List<int32_t>;

template class List<int64_t>;

template class List<char>;

template class List<std::string>;

template class List<float>;

template class List<double>;
} // namespace Hayakel
