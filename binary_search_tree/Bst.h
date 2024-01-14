#ifndef __HBST__
#define __HBST__
namespace Hayakel {
template <typename T> class BstNode {
public:
  T val;
  BstNode<T> *left, *right;
  BstNode();
  BstNode(T val);
  ~BstNode();
};

template <typename T> class Bst {
private:
  BstNode<T> *root;

public:
  Bst();
  ~Bst(); // TODO: implement

  BstNode<T> *findNode(T val);
  void deleteNode(BstNode<T> *curr);
  bool contains(T val);
  void insert(T val);
  void traverse(int order);
  void remove(T val); // TODO: implement
  void preOrder(BstNode<T> *start);
  void postOrder(BstNode<T> *start);
  void inOrder(BstNode<T> *start);
};
} // namespace Hayakel
#endif
