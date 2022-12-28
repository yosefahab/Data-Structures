#include "mQueue.h"
#include <assert.h>
#include <iostream>
using namespace std;

template <typename T>
mQueue<T>::mQueue(int size) {
    capacity = size;
    arr = new T[size];
    frontIdx = backIdx = -1;
    elementCount = 0;
}

template <typename T>
mQueue<T>::~mQueue() {
    delete[] arr;
    arr = nullptr;
}

template <typename T>
T mQueue<T>::front() {
    assert(!isEmpty());
    return arr[frontIdx];
}

template <typename T>
void mQueue<T>::deQeue() {
    assert(!isEmpty());
    frontIdx = (++frontIdx) % capacity;
    if (isEmpty()) {
        frontIdx = backIdx = -1;
    }
    elementCount--;
}

template <typename T>
void mQueue<T>::enQeue(T x) {
    assert(!isFull());
    backIdx = (++backIdx % capacity);
    arr[backIdx] = x;
    if (frontIdx == -1) {
        frontIdx = 0;
    }

    elementCount++;
}

template <typename T>
bool mQueue<T>::isEmpty() { return elementCount == 0; }

template <typename T>
bool mQueue<T>::isFull() { return elementCount == capacity; }

template <typename T>
int mQueue<T>::length() { return elementCount; }

template class mQueue<int32_t>;

template class mQueue<int64_t>;

template class mQueue<char>;

template class mQueue<string>;

template class mQueue<float>;

template class mQueue<double>;