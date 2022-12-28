#ifndef __MLINKEDLIST__
#define __MLINKEDLIST__
template <typename T>
class mNode {
  public:
    mNode<T>* next;
    T value;

    mNode();
    ~mNode();
    mNode(T val);
};

template <typename T>
class mLinkedList {
  private:
    int count;
    mNode<T>* head;
    mNode<T>* tail;

  public:
    mLinkedList();
    T at(int pos);
    int length();
    void append(T val);
    void deleteAt(int pos);
    void insertAt(int pos, T val);
    ~mLinkedList();
};
#endif