#include "llStack.h"
#include <assert.h>
#include <string>

namespace Hayakel {
template <typename T> llSNode<T>::llSNode(T val) {
  this->val = val;
  this->next = nullptr;
}

template <typename T> llSNode<T>::~llSNode() {
  delete this->next;
  this->next = nullptr;
}

template <typename T> llStack<T>::llStack() {
  this->head = nullptr;
  this->_size = 0;
}

template <typename T> llStack<T>::~llStack() { clear(); }

template <typename T> bool llStack<T>::isEmpty() { return this->_size == 0; }

template <typename T> int llStack<T>::size() { return this->_size; }

template <typename T> void llStack<T>::push(T val) {
  llSNode<T> *temp = new llSNode<T>(val);
  temp->next = this->head;
  this->head = temp;
  this->_size++;
}

template <typename T> T llStack<T>::pop() {
  assert(!isEmpty());
  llSNode<T> *temp = this->head;
  this->head = this->head->next;
  T val = temp->val;
  delete temp;
  temp = nullptr;
  _size--;
  return val;
}

template <typename T> void llStack<T>::clear() {
  while (this->head != nullptr) {
    pop();
  }
}

template class llSNode<int32_t>;
template class llStack<int32_t>;

template class llSNode<int64_t>;
template class llStack<int64_t>;

template class llSNode<char>;
template class llStack<char>;

template class llSNode<std::string>;
template class llStack<std::string>;

template class llSNode<float>;
template class llStack<float>;

template class llSNode<double>;
template class llStack<double>;
} // namespace Hayakel
