#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

namespace LinkedList {
/* structure to represent the linked list's node. */
template <typename T> struct LinkedListNode {
  /* self referential structure. */
  T data;
  LinkedListNode<T> *next;
  LinkedListNode(T value) : data(value), next(nullptr){};
};

/* class to represent linked list ADT, it encapsulates the data and functions
 * for the linked list. */
template <class T> class LinkedList {
public:
  int count;
  LinkedListNode<T> *head;
  LinkedListNode<T> *tail;
  LinkedList() : count(0), head(nullptr), tail(nullptr){};

  /* member function to add element at the first position. */
  void AddFirst(T data) {
    LinkedListNode<T> *ptr = new LinkedListNode<T>(data);
    LinkedListNode<T> *tmp = head;
    head = ptr;
    ptr->next = tmp;
    count++;

    if (!tail) // empty linked list
    {
      tail = head;
    }
  }

  /* member function to insert a node at the last position. */
  void AddLast(T data) {
    LinkedListNode<T> *ptr = new LinkedListNode<T>(data);
    LinkedListNode<T> *tmp = tail;
    tail = ptr;
    ptr->next = tmp;
    count++;

    if (!head) // empty linked list
    {
      head = tail;
    }
  }

  /* member function to add an element, by default at first positon */
  void Add(T data) { AddLast(data); }

  void CopyTo(vector<int> arr, int index) {
    LinkedListNode<T> *tmp = head;
    while (tmp) {
      arr[index++] = tmp->data;
    }
  }

  /* member function to print out all the elements of the linked list */
  void Print() {
    LinkedListNode<T> *tmp = head;
    while (tmp) {
      cout << tmp->data << " ";
      tmp = tmp->next;
    }
    cout << endl;
  }

  /* member function to delete all the elements of the linked list */
  void Clear() {
    LinkedListNode<T> *tmp = head;
    LinkedListNode<T> *ptr = tmp;

    while (tmp) {
      tmp = tmp->next;
      delete ptr;
      ptr = tmp;
    }
    count = 0;
  }

  /* member function to get the size of the list */
  int size() { return count; }

  /* member function to check if the linked list contains a certain value */
  bool Contains(T data) {
    LinkedListNode<T> *tmp = head;
    while (tmp) {
      if (tmp->data == data) {
        return true;
      }
      tmp = tmp->next;
    }
    return false;
  }

  /* member function to remove the first element of the list */
  bool RemoveFirst() {
    LinkedListNode<T> *tmp = head;
    if (tmp) {
      head = tmp->next;
      count--;
      delete tmp;
      return true;
    }
    return false;
  }

  /* member function to remove the last element */
  bool RemoveLast() {
    LinkedListNode<T> *tmp = head;
    LinkedListNode<T> *prev = nullptr;
    if (!tmp) {
      return false;
    }
    while (tmp) {
      if (!prev) {
        return RemoveFirst();
      } else {
        prev->next = tmp->next;
        tail = prev;
        delete tmp;
        count--;
        return true;
      }
    }
    return false;
  }

  /* member function to remove a particular data of the list. */
  bool Remove(T item) {
    LinkedListNode<T> *tmp = head;
    if (!tmp) {
      return false;
    }
    LinkedListNode<T> *prev = nullptr;
    while (tmp) {
      if (tmp->data == item) {
        if (!prev) {
          return RemoveFirst();
        } else {
          prev->next = tmp->next;
          delete tmp;
          count--;
          return true;
        }
      }
      prev = tmp;
      tmp = tmp->next;
    }
    return false;
  }
};

} // namespace LinkedList

int main() {
  LinkedList::LinkedList<int> linked_list;
  linked_list.AddFirst(16);
  linked_list.AddFirst(13);
  linked_list.AddFirst(25);
  linked_list.AddFirst(5);
  linked_list.AddFirst(4);
  linked_list.AddFirst(11);
  linked_list.Print();
  linked_list.Remove(13);
  linked_list.Print();
  linked_list.RemoveFirst();
  linked_list.Print();
  cout << linked_list.size() << endl;
  linked_list.Clear();
  cout << linked_list.size() << endl;
}
