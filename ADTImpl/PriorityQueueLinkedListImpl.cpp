#include <iostream>
#include <list> //standard library's  implementation of singly linked list
#include <string>

using std::cout;
using std::endl;
using std::list;
using std::string;

template <class T> class PriorityQueue {
public:
  unsigned int count;
  list<T> _list;
  PriorityQueue() : count(0), _list(list<T>()) {}

  void Enqueue(T data) {
    if (!count) {
      _list.push_back(data);
    } else {
      auto itr = begin(_list);
      while (itr != end(_list) && *itr < data) {
        ++itr;
      }
      if (itr == end(_list)) {
        _list.push_back(data);
      } else {
        _list.insert(itr, data);
      }
    }
    count++;
  }

  void Dequeue() {
    if (!count)
      cout << "Empty PriorityQueue" << endl;
    _list.pop_front();
  }
  T Peek() {
    if (!count) {
      cout << "Empty PriorityQueue" << endl;
      return (T)NULL;
    } else {
      return _list.front();
    }
  }
  void Print() {
    for (auto itr : _list) {
      cout << itr << " ";
    }
    cout << endl;
  }

  auto Size() -> unsigned int { return count; }
};

/* main function for testing the functionality. */
int main() {
  PriorityQueue<int> priorityQueue;
  priorityQueue.Enqueue(13);
  priorityQueue.Enqueue(3);
  priorityQueue.Enqueue(32);
  priorityQueue.Enqueue(134);
  priorityQueue.Enqueue(56);
  cout << "priorityQueue.Peek(): " << priorityQueue.Peek() << endl;
  cout << "priorityQueue.Size(): " << priorityQueue.Size() << endl;
  priorityQueue.Print();
  priorityQueue.Dequeue();
  cout << "After Dequeue: ";
  priorityQueue.Print();
  return 0;
}
