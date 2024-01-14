#include "binary_search_tree/Bst.h"
#include "linked_list/LinkedList.h"
#include "list/List.h"
#include "queue/Queue.h"
#include "stack/Stack.h"
#include "stack/llStack.h"

#include <iostream>

void stack_demo() {
  std::cout << "--------------------------" << std::endl;
  std::cout << "Stack Demo\n";
  Hayakel::Stack<float> *s = new Hayakel::Stack<float>;
  for (float i = 0; i < 5; i += 0.5) {
    s->push(i);
  }
  while (!s->isEmpty()) {
    std::cout << "Size: " << s->size() << " Top: " << s->top() << std::endl;
    s->pop();
  }
  std::cout << std::endl;
}

void linked_list_demo() {
  std::cout << "--------------------------" << std::endl;
  std::cout << "Linked List Demo\n";
  Hayakel::LinkedList<int> *ll = new Hayakel::LinkedList<int>;
  for (int i = 1; i <= 4; i++) {
    ll->append(i);
  }
  ll->deleteAt(3);
  ll->append(5);
  for (int i = 0; i < ll->length(); i++) {
    std::cout << "Element @%d: ";
    std::cout << ll->at(i) << std::endl;
  }
  std::cout << std::endl;
}

void list_demo() {
  std::cout << "--------------------------" << std::endl;
  std::cout << "Array List Demo\n";
  Hayakel::List<int> *l = new Hayakel::List<int>;
  for (int i = 0; i < 10; i++)
    l->append(i);
  std::cout << "Full Array:\n";
  l->display();

  std::cout << "\ndeleted element @ 3:\n";
  l->deleteAt(3);
  l->display();

  std::cout << "\ninserted 3 @ 2:\n";
  l->inserAt(3, 2);
  l->display();

  std::cout << "\nappended 1:\n";
  l->append(1);
  l->display();

  std::cout << std::endl;
}
void queue_demo() {

  std::cout << "--------------------------" << std::endl;
  std::cout << "Queue Demo\n";
  Hayakel::Queue<char> *q = new Hayakel::Queue<char>;
  q->enQeue('D');
  q->enQeue('c');
  q->enQeue('b');
  q->enQeue('a');
  while (!q->isEmpty()) {
    std::cout << "Front: " << q->front() << "\n";
    q->deQeue();
  }
  std::cout << std::endl;
}

void binary_search_tree_demo() {
  std::cout << "--------------------------" << std::endl;
  std::cout << "Binary Tree Demo\n";
  Hayakel::Bst<int> *bst = new Hayakel::Bst<int>;
  for (int i = 1; i <= 5; i++) {
    bst->insert(i);
  }
  std::cout << "Pre Order: \n";
  bst->traverse(-1);
  std::cout << "\n\n";
  std::cout << "Post Order: \n";
  bst->traverse(1);
  std::cout << "\n\n";
  std::cout << "In Order: \n";
  bst->traverse(0);

  std::cout << std::endl;
}

int main() {
  // Demos
  stack_demo();
  linked_list_demo();
  list_demo();
  queue_demo();
  binary_search_tree_demo();

  std::cout << std::endl;
  return 0;
}
