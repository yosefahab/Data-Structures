namespace Hayakel {
template <typename T> class llSNode {
public:
  llSNode();
  llSNode(T val);
  ~llSNode();
  T val;
  llSNode *next;
};
template <typename T> class llStack {
private:
  int _size;
  llSNode<T> *head;

public:
  llStack();
  ~llStack();
  bool isEmpty();
  int size();
  void push(T val);
  void clear();
  T pop();
};
} // namespace Hayakel
