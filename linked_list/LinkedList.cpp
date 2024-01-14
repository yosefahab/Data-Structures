#include "LinkedList.h"
#include <assert.h>
#include <string>

namespace Hayakel {
template <typename T> llNode<T>::llNode() { this->next = nullptr; }

template <typename T> llNode<T>::~llNode() {
  delete this->next;
  this->next = nullptr;
}

template <typename T> llNode<T>::llNode(T val) {
  this->value = val;
  this->next = nullptr;
}

template <typename T> LinkedList<T>::LinkedList() {
  this->count = 0;
  this->head = nullptr;
  this->tail = nullptr;
}
template <typename T>

LinkedList<T>::~LinkedList() {
  llNode<T> *currentNode = this->head;
  llNode<T> *nextNode;

  while (currentNode != NULL) {
    nextNode = currentNode->next;
    delete currentNode;
    currentNode = nextNode;
  }
  currentNode = nullptr;
  nextNode = nullptr;
}

template <typename T> T LinkedList<T>::at(int pos) {
  assert(pos >= 0 && pos < count);
  llNode<T> *temp = this->head;
  for (int i = 0; i < pos; i++) {
    temp = temp->next;
  }
  return temp->value;
}

template <typename T> int LinkedList<T>::length() { return count; }

template <typename T> void LinkedList<T>::append(T val) {
  llNode<T> *temp = new llNode<T>(val);
  if (this->count == 0) // head = null
  {
    this->head = this->tail = temp;
  } else {
    this->tail->next = temp;
    this->tail = temp;
  }
  this->count++;
}

template <typename T> void LinkedList<T>::deleteAt(int pos) {
  assert(pos >= 0 && pos < count);
  llNode<T> *n = this->head;
  if (pos == 0) {
    this->head = this->head->next;
    delete n;
  } else {
    for (int i = 0; i < pos - 1; i++) {
      n = n->next;
    }
    llNode<T> *temp = n->next;
    n->next = temp->next;
    delete temp;
    if (pos == count - 1) {
      this->tail = n;
    }
  }
  count--;
}

template <typename T> void LinkedList<T>::insertAt(int pos, T val) {
  assert(pos <= this->count);

  llNode<T> *temp = this->head;
  llNode<T> *toInsert = new llNode<T>(val);

  if (pos == 0) {
    toInsert->next = this->head;
    this->head = toInsert;
  } else {
    for (int i = 0; i < pos - 1; i++) {
      temp = temp->next;
    }
    toInsert->next = temp->next;
    temp->next = toInsert;
  }
  this->count++;
}

template class llNode<int32_t>;
template class LinkedList<int32_t>;

template class llNode<int64_t>;
template class LinkedList<int64_t>;

template class llNode<char>;
template class LinkedList<char>;

template class llNode<std::string>;
template class LinkedList<std::string>;

template class llNode<float>;
template class LinkedList<float>;

template class llNode<double>;
template class LinkedList<double>;
} // namespace Hayakel
