#ifndef __MSTACK__
#define __MSTACK__

template <typename T>
class mStack {
  private:
    int topIdx, capacity;
    T *arr;

  public:
    mStack(int size = 10);
    ~mStack();
    T top();
    int length();
    void pop();
    void push(T x);
    void expand();
    bool isEmpty();
};
#endif