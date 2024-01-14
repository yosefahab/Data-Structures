#ifndef __HLIST__
#define __HLIST__

namespace Hayakel {
template <typename T> class List {
private:
  T *arr;
  int size, count;
  void expand();

public:
  List();
  ~List();
  int length();
  int capacity();
  void display();
  T at(int pos);
  void append(T x);
  void inserAt(int pos, T x);
  void deleteAt(int pos);
};
} // namespace Hayakel
#endif
