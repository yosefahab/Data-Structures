#include "mArrList.h"
#include "mBst.h"
#include "mLStack.h"
#include "mLinkedList.h"
#include "mQueue.h"
#include "mStack.h"

#include <iostream>
using namespace std;

inline void stack_demo() {
    cout << "--------------------------" << endl;
    cout << "Stack Demo\n";
    mStack<float>* s = new mStack<float>;
    for (float i = 0; i < 5; i += .5) {
        s->push(i);
    }
    while (!s->isEmpty()) {
        cout << "Size: " << s->length() << " Top: " << s->top() << endl;
        s->pop();
    }
    cout << endl;
}
inline void linked_list_demo() {
    cout << "--------------------------" << endl;
    cout << "Linked List Demo\n";
    mLinkedList<int>* ll = new mLinkedList<int>;
    ll->append(9);
    ll->append(10);
    ll->append(11);
    ll->append(12);
    ll->deleteAt(3);
    ll->append(22);
    for (int i = 0; i < ll->length(); i++) {
        printf("Element @%d: ", i);
        cout << ll->at(i) << endl;
    }
    cout << endl;
}
inline void array_list_demo() {
    cout << "--------------------------" << endl;
    cout << "Array List Demo\n";
    mArrList<int>* l = new mArrList<int>;
    for (int i = 0; i < 10; i++)
        l->append(i);
    cout << "Full Array:\n";
    l->display();

    cout << "\ndeleted element @ 3:\n";
    l->deleteAt(3);
    l->display();

    cout << "\ninserted 3 @ 2:\n";
    l->inserAt(3, 2);
    l->display();

    cout << "\nappended 1:\n";
    l->append(1);
    l->display();

    cout << endl;
}
inline void queue_demo() {
    cout << "--------------------------" << endl;
    cout << "Queue Demo\n";
    mQueue<char>* q = new mQueue<char>;
    q->enQeue('D');
    q->enQeue('c');
    q->enQeue('b');
    q->enQeue('a');
    for (int i = 0; !q->isEmpty(); i++) {
        cout << "Front: " << q->front() << "\n";
        q->deQeue();
    }
    cout << endl;
}
inline void binary_search_tree_demo() {
    cout << "--------------------------" << endl;
    cout << "Binary Tree Demo\n";
    mBst<int>* bst = new mBst<int>;
    bst->insert(1);
    bst->insert(2);
    bst->insert(3);
    bst->insert(4);
    bst->insert(5);
    bst->insert(6);
    bst->insert(7);
    cout << "Pre Order: \n";
    bst->traverse(-1);
    cout << "\n\n";
    cout << "Post Order: \n";
    bst->traverse(1);
    cout << "\n\n";
    cout << "In Order: \n";
    bst->traverse(0);

    cout << endl;
}
int main() {
    // Demos
    stack_demo();
    linked_list_demo();
    array_list_demo();
    queue_demo();
    binary_search_tree_demo();

    cout << endl;
    return 0;
}