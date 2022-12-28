#ifndef __MARRLIST__
#define __MARRLIST__

template <typename T>
class mArrList {
  private:
    T* arr;
    int size, count;

  public:
    mArrList();
    ~mArrList();
    int length();
    int capacity();
    void expand();
    void display();
    T at(int pos);
    void append(T x);
    void inserAt(int pos, T x);
    void deleteAt(int pos);
};
#endif
