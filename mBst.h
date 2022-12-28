#ifndef __MBST__
#define __MBST__
template <typename T>
class mBNode {
  public:
    T val;
    mBNode<T>*left, *right;
    mBNode();
    mBNode(T val);
    ~mBNode(); // TODO: implement
};

template <typename T>
class mBst {
  private:
    mBNode<T>* root;

  public:
    mBst();
    ~mBst(); // TODO: implement

    mBNode<T>* findNode(T val);
    void deleteNode(mBNode<T>* curr);
    bool contains(T val);
    void insert(T val);
    void traverse(int order);
    void remove(T val); // TODO: implement
    void preOrder(mBNode<T>* start);
    void postOrder(mBNode<T>* start);
    void inOrder(mBNode<T>* start);
};
#endif