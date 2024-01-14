#ifndef __HLINKEDLIST__
#define __HLINKEDLIST__

namespace Hayakel {
template <typename T> class llNode {
public:
  llNode();
  llNode(T val);
  ~llNode();
  T value;
  llNode<T> *next;
};

template <typename T> class LinkedList {
private:
  int count;
  llNode<T> *head;
  llNode<T> *tail;

public:
  LinkedList();
  ~LinkedList();
  T at(int pos);
  int length();
  void append(T val);
  void deleteAt(int pos);
  void insertAt(int pos, T val);
};
} // namespace Hayakel
#endif
