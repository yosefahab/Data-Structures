#include "mBst.h"
#include <iostream>
using namespace std;

template <typename T>
mBNode<T>::mBNode() { this->left = this->right = nullptr; }

template <typename T>
mBNode<T>::~mBNode() {
    delete this->left;
    delete this->right;
    this->left = this->right = nullptr;
}

template <typename T>
mBNode<T>::mBNode(T val) {
    this->val = val;
    this->left = this->right = nullptr;
}

template <typename T>
mBst<T>::mBst() { this->root = nullptr; }

template <typename T>
mBst<T>::~mBst() {
    deleteNode(root);
}

template <typename T>
void mBst<T>::deleteNode(mBNode<T>* curr) {
    if (curr->left != nullptr)
        deleteNode(curr->left);
    if (curr->right != nullptr)
        deleteNode(curr->right);
    delete curr;
    curr = nullptr;
}

template <typename T>
mBNode<T>* mBst<T>::findNode(T val) {
    mBNode<T>* temp = root;
    while (temp != nullptr && temp->val != val) {
        if (val < temp->val)
            temp = temp->left;
        else
            temp = temp->right;
    }
    return temp;
}

template <typename T>
bool mBst<T>::contains(T val) {
    mBNode<T>* temp = findNode(val);
    return temp != nullptr;
}

template <typename T>
void mBst<T>::insert(T val) {
    mBNode<T>* n = new mBNode<T>(val);
    if (root == nullptr)
        root = n;
    else {
        mBNode<T>* temp = root;
        while (true) {
            if (val < temp->val) {
                if (temp->left == nullptr) {
                    temp->left = n;
                    break;
                } else {
                    temp = temp->left;
                }
            } else if (val > temp->val) {
                if (temp->right == nullptr) {
                    temp->right = n;
                    break;
                } else {
                    temp = temp->right;
                }
            } else {
                return; // already exists
            }
        }
    }
}

template <typename T>
void mBst<T>::inOrder(mBNode<T>* start) {
    if (start != nullptr) {
        inOrder(start->left);
        cout << start->val << " ";
        inOrder(start->right);
    }
}

template <typename T>
void mBst<T>::postOrder(mBNode<T>* start) {
    if (start != nullptr) {
        postOrder(start->left);
        postOrder(start->right);
        cout << start->val << " ";
    }
}

template <typename T>
void mBst<T>::preOrder(mBNode<T>* start) {
    if (start != nullptr) {
        cout << start->val << " ";
        preOrder(start->left);
        preOrder(start->right);
    }
}

template <typename T>
void mBst<T>::traverse(int order) {
    switch (order) {
    case 0:
        preOrder(this->root);
        break;
    case -1:
        postOrder(this->root);
        break;
    case 1:
        inOrder(this->root);
        break;
    }
}

template class mBst<int32_t>;
template class mBNode<int32_t>;

template class mBst<int64_t>;
template class mBNode<int64_t>;

template class mBst<char>;
template class mBNode<char>;

template class mBst<string>;
template class mBNode<string>;

template class mBst<float>;
template class mBNode<float>;

template class mBst<double>;
template class mBNode<double>;