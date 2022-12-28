#include "mArrList.h"
#include <assert.h>
#include <iostream>
using namespace std;

template <typename T>
mArrList<T>::mArrList() {
    count = 0;
    size = 5;
    arr = new T[5];
}

template <typename T>
mArrList<T>::~mArrList() {
    delete[] arr;
    arr = nullptr;
}

template <typename T>
int mArrList<T>::length() {
    return this->count;
}

template <typename T>
int mArrList<T>::capacity() {
    return this->size;
}

template <typename T>
void mArrList<T>::expand() {
    size *= 2;
    T* temp = new T[size];
    for (int i = 0; i < count; i++) {
        temp[i] = arr[i];
    }
    delete[] arr;
    arr = temp;
}

template <typename T>
void mArrList<T>::append(T x) {
    if (count == size) {
        expand();
    }
    arr[count++] = x;
}

template <typename T>
T mArrList<T>::at(int pos) {
    assert(pos >= 0 && pos < count);
    return arr[pos];
}

template <typename T>
void mArrList<T>::display() {
    for (int i = 0; i < count; i++) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

template <typename T>
void mArrList<T>::deleteAt(int pos) {
    for (int i = pos; i < count - 1; i++) {
        arr[i] = arr[i + 1];
    }
    count--;
}

template <typename T>
void mArrList<T>::inserAt(int pos, T x) {
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

template class mArrList<int32_t>;

template class mArrList<int64_t>;

template class mArrList<char>;

template class mArrList<string>;

template class mArrList<float>;

template class mArrList<double>;