template <typename T>
class LSNode {
  public:
    LSNode();
    LSNode(T val);
    ~LSNode(); //TODO: implement
    T val;
    LSNode *next;
};
template <typename T>
class mLStack {
    int size;
    LSNode<T> *head;

  public:
    bool isEmpty();
    void push(T val);
    void clear();
    T pop();
    mLStack();
    ~mLStack();
};