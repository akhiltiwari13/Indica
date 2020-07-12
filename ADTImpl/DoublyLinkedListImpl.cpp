#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

namespace DoublyLinkedList {
/* structure to represent the doubly linked list's node. */
template <typename T> struct DoublyLinkedListNode {
  /* self referential structure. */
  T data;
  DoublyLinkedListNode<T> *next;
  DoublyLinkedListNode<T> *prev;
  DoublyLinkedListNode(T value) : data(value), next(nullptr), prev(nullptr){};
};

/* class to represent doubly linked list ADT, it encapsulates the data and
 * functions for the doubly linked list. */
template <class T> class DoublyLinkedList {
public:
  unsigned int count;
  DoublyLinkedListNode<T> *head;
  DoublyLinkedListNode<T> *tail;
  DoublyLinkedList() : count(0), head(nullptr), tail(nullptr){};

  /* member function to add element at the first position. */
  void AddFirst(T data) {
    DoublyLinkedListNode<T> *ptr = new DoublyLinkedListNode<T>(data);
    DoublyLinkedListNode<T> *tmp = head;
    head = ptr;
    ptr->next = tmp;
    if (tmp) {
      tmp->prev = ptr;
    }
    count++;

    if (!tail) // empty linked list
    {
      tail = head;
    }
  }

  /* member function to insert a node at the last position. */
  void AddLast(T data) {
    DoublyLinkedListNode<T> *ptr = new DoublyLinkedListNode<T>(data);
    DoublyLinkedListNode<T> *tmp = tail;
    tail = ptr;
    ptr->prev = tmp;
    tmp->next = ptr;
    count++;

    if (!head) // empty doubly linked list
    {
      head = tail;
    }
  }

  /* member function to add an element, by default at first positon */
  void Add(T data) { AddLast(data); }

  void CopyTo(vector<int> arr, int index) {
    DoublyLinkedListNode<T> *tmp = head;
    while (tmp) {
      arr[index++] = tmp->data;
    }
  }

  /* member function to print out all the elements of the doubly linked list */
  void Print() {
    DoublyLinkedListNode<T> *tmp = head;
    while (tmp) {
      cout << tmp->data << " ";
      tmp = tmp->next;
    }
    cout << endl;
  }

  /* member function to print the doubly linked list in the reverse order. */
  void PrintReverse() {
    DoublyLinkedListNode<T> *tmp = tail;
    while (tmp) {
      cout << tmp->data << " ";
      tmp = tmp->prev;
    }
    cout << endl;
  }

  /* member function to delete all the elements of the doubly linked list */
  void Clear() {
    DoublyLinkedListNode<T> *tmp = head;
    DoublyLinkedListNode<T> *ptr = tmp;

    while (tmp) {
      tmp = tmp->next;
      delete ptr;
      ptr = tmp;
    }
    count = 0;
  }

  /* member function to get the size of the  doubly linked list */
  int size() { return count; }

  /* member function to check if the doubly linked list contains a certain value
   */
  bool Contains(T data) {
    DoublyLinkedListNode<T> *tmp = head;
    while (tmp) {
      if (tmp->data == data) {
        return true;
      }
      tmp = tmp->next;
    }
    return false;
  }

  /* member function to remove the first element of the doubly linked list */
  bool RemoveFirst() {
    DoublyLinkedListNode<T> *tmp = head;
    if (tmp) {
      head = tmp->next;
      if (tmp->next) {
        tmp->next->prev = nullptr;
      }
      count--;
      delete tmp;
      return true;
    }
    return false;
  }
  /* member function to remove the last element */
  bool RemoveLast() {
    DoublyLinkedListNode<T> *tmp = tail;
    if (!tmp) {
      return false;
    }
    while (tmp) {
      if (!tmp->prev) {
        return RemoveFirst();
      } else {
        tmp->prev->next = tmp->next;
        tail = tmp->prev;
        delete tmp;
        count--;
        return true;
      }
    }
    return false;
  }

  /* member function to remove a particular data of the doubly linked list. */
  bool Remove(T item) {
    DoublyLinkedListNode<T> *tmp = head;
    if (!tmp) {
      return false;
    }
    while (tmp) {
      if (tmp->data == item) {
        if (!tmp->prev) {
          return RemoveFirst();
        } else if (!tmp->next) {
          return RemoveLast();
        } else {
          tmp->prev->next = tmp->next;
          tmp->next->prev = tmp->prev;
          delete tmp;
          count--;
          return true;
        }
      }
      tmp = tmp->next;
    }
    return false;
  }
};

} // namespace DoublyLinkedList

int main() {
  DoublyLinkedList::DoublyLinkedList<int> doublylinked_list;
  doublylinked_list.AddFirst(16);
  doublylinked_list.AddFirst(13);
  doublylinked_list.AddFirst(25);
  doublylinked_list.AddFirst(5);
  doublylinked_list.AddFirst(4);
  doublylinked_list.AddFirst(11);
  doublylinked_list.Print();
  doublylinked_list.Remove(13);
  doublylinked_list.Print();
  doublylinked_list.RemoveFirst();
  doublylinked_list.Print();
  cout << doublylinked_list.size() << endl;
  doublylinked_list.Clear();
  cout << doublylinked_list.size() << endl;
}
