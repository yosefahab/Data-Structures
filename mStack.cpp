#include "mStack.h"
#include <assert.h>
#include <iostream>
using namespace std;

template <typename T>
mStack<T>::mStack(int capacity) {
    this->capacity = capacity;
    arr = new T[capacity];
    topIdx = 0;
}

template <typename T>
mStack<T>::~mStack() {
    delete[] arr;
    arr = nullptr;
}

template <typename T>
void mStack<T>::push(T x) {
    if (topIdx == capacity) {
        expand();
    }
    arr[topIdx++] = x;
}

template <typename T>
void mStack<T>::pop() {
    assert(!isEmpty());
    topIdx--;
}

template <typename T>
void mStack<T>::expand() {
    T* temp = new T[capacity * 2];
    for (int i = 0; i < capacity; i++) {
        temp[i] = arr[i];
    }
    capacity *= 2;
    delete[] arr;
    arr = temp;
}

template <typename T>
bool mStack<T>::isEmpty() { return topIdx == 0; }

template <typename T>
T mStack<T>::top() { return arr[topIdx - 1]; }

template <typename T>
int mStack<T>::length() { return topIdx; }

template class mStack<int32_t>;

template class mStack<int64_t>;

template class mStack<char>;

template class mStack<string>;

template class mStack<float>;

template class mStack<double>;