#include "mLStack.h"
#include <assert.h>
#include <iostream>
using namespace std;

template <typename T>
LSNode<T>::LSNode(T val) {
    this->val = val;
    this->next = nullptr;
}

template <typename T>
LSNode<T>::~LSNode() {
    delete this->next;
    this->next = nullptr;
}

template <typename T>
mLStack<T>::mLStack() {
    this->head = nullptr;
    this->size = 0;
}

template <typename T>
mLStack<T>::~mLStack() {
    clear();
}

template <typename T>
bool mLStack<T>::isEmpty() {
    return this->size == 0;
}

template <typename T>
void mLStack<T>::push(T val) {
    LSNode<T>* temp = new LSNode<T>(val);
    temp->next = this->head;
    this->head = temp;
    this->size++;
}

template <typename T>
T mLStack<T>::pop() {
    assert(!isEmpty());
    LSNode<T>* temp = this->head;
    this->head = this->head->next;
    T val = temp->val;
    delete temp;
    temp = nullptr;
    size--;
    return val;
}

template <typename T>
void mLStack<T>::clear() {
    while (this->head != nullptr) {
        pop();
    }
}

template class LSNode<int32_t>;
template class mLStack<int32_t>;

template class LSNode<int64_t>;
template class mLStack<int64_t>;

template class LSNode<char>;
template class mLStack<char>;

template class LSNode<string>;
template class mLStack<string>;

template class LSNode<float>;
template class mLStack<float>;

template class LSNode<double>;
template class mLStack<double>;