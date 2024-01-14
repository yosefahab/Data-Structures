#include "Bst.h"
#include <iostream>

namespace Hayakel {
template <typename T> BstNode<T>::BstNode() {
  this->left = this->right = nullptr;
}

template <typename T> BstNode<T>::~BstNode() {
  delete this->left;
  delete this->right;
  this->left = this->right = nullptr;
}

template <typename T> BstNode<T>::BstNode(T val) {
  this->val = val;
  this->left = this->right = nullptr;
}

template <typename T> Bst<T>::Bst() { this->root = nullptr; }

template <typename T> Bst<T>::~Bst() { deleteNode(root); }

template <typename T> void Bst<T>::deleteNode(BstNode<T> *curr) {
  if (curr->left != nullptr)
    deleteNode(curr->left);
  if (curr->right != nullptr)
    deleteNode(curr->right);
  delete curr;
  curr = nullptr;
}

template <typename T> BstNode<T> *Bst<T>::findNode(T val) {
  BstNode<T> *temp = root;
  while (temp != nullptr && temp->val != val) {
    if (val < temp->val)
      temp = temp->left;
    else
      temp = temp->right;
  }
  return temp;
}

template <typename T> bool Bst<T>::contains(T val) {
  BstNode<T> *temp = findNode(val);
  return temp != nullptr;
}

template <typename T> void Bst<T>::insert(T val) {
  BstNode<T> *n = new BstNode<T>(val);
  if (root == nullptr)
    root = n;
  else {
    BstNode<T> *temp = root;
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

template <typename T> void Bst<T>::inOrder(BstNode<T> *start) {
  if (start != nullptr) {
    inOrder(start->left);
    std::cout << start->val << " ";
    inOrder(start->right);
  }
}

template <typename T> void Bst<T>::postOrder(BstNode<T> *start) {
  if (start != nullptr) {
    postOrder(start->left);
    postOrder(start->right);
    std::cout << start->val << " ";
  }
}

template <typename T> void Bst<T>::preOrder(BstNode<T> *start) {
  if (start != nullptr) {
    std::cout << start->val << " ";
    preOrder(start->left);
    preOrder(start->right);
  }
}

template <typename T> void Bst<T>::traverse(int order) {
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

template class Bst<int32_t>;
template class BstNode<int32_t>;

template class Bst<int64_t>;
template class BstNode<int64_t>;

template class Bst<char>;
template class BstNode<char>;

template class Bst<std::string>;
template class BstNode<std::string>;

template class Bst<float>;
template class BstNode<float>;

template class Bst<double>;
template class BstNode<double>;
} // namespace Hayakel
