#include "mLinkedList.h"
#include <assert.h>
#include <iostream>

using namespace std;

template <typename T>
mNode<T>::mNode() {
    this->next = nullptr;
}

template <typename T>
mNode<T>::~mNode() {
    delete this->next;
    this->next = nullptr;
}

template <typename T>
mNode<T>::mNode(T val) {
    this->value = val;
    this->next = nullptr;
}

template <typename T>
mLinkedList<T>::mLinkedList() {
    this->count = 0;
    this->head = nullptr;
    this->tail = nullptr;
}
template <typename T>

mLinkedList<T>::~mLinkedList() {
    mNode<T>* currentNode = this->head;
    mNode<T>* nextNode;

    while (currentNode != NULL) {
        nextNode = currentNode->next;
        delete currentNode;
        currentNode = nextNode;
    }
    currentNode = nullptr;
    nextNode = nullptr;
}

template <typename T>
T mLinkedList<T>::at(int pos) {
    assert(pos >= 0 && pos < count);
    mNode<T>* temp = this->head;
    for (int i = 0; i < pos; i++) {
        temp = temp->next;
    }
    return temp->value;
}

template <typename T>
int mLinkedList<T>::length() { return count; }

template <typename T>
void mLinkedList<T>::append(T val) {
    mNode<T>* temp = new mNode<T>(val);
    if (this->count == 0) // head = null
    {
        this->head = this->tail = temp;
    } else {
        this->tail->next = temp;
        this->tail = temp;
    }
    this->count++;
}

template <typename T>
void mLinkedList<T>::deleteAt(int pos) {
    assert(pos >= 0 && pos < count);
    mNode<T>* n = this->head;
    if (pos == 0) {
        this->head = this->head->next;
        delete n;
    } else {
        for (int i = 0; i < pos - 1; i++) {
            n = n->next;
        }
        mNode<T>* temp = n->next;
        n->next = temp->next;
        delete temp;
        if (pos == count - 1) {
            this->tail = n;
        }
    }
    count--;
}

template <typename T>
void mLinkedList<T>::insertAt(int pos, T val) {
    assert(pos <= this->count);

    mNode<T>* temp = this->head;
    mNode<T>* toInsert = new mNode<T>(val);

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

template class mNode<int32_t>;
template class mLinkedList<int32_t>;

template class mNode<int64_t>;
template class mLinkedList<int64_t>;

template class mNode<char>;
template class mLinkedList<char>;

template class mNode<string>;
template class mLinkedList<string>;

template class mNode<float>;
template class mLinkedList<float>;

template class mNode<double>;
template class mLinkedList<double>;