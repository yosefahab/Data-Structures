#ifndef __MQUEUE__
#define __MQUEUE__

template <typename T>
class mQueue {
  private:
    int frontIdx, backIdx, capacity;
    T* arr;
    int elementCount;

  public:
    mQueue(int size = 10);
    ~mQueue();
    T front();
    int length();
    bool isEmpty();
    void enQeue(T x);
    void deQeue();
    bool isFull();
};
#endif
