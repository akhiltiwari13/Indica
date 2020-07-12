#include <iostream>
#include <list>
#include <string>

using std::cout;
using std::endl;
using std::list;
using std::string;

template <class T> class Queue {
public:
  unsigned int count;
  list<T> _list;
  Queue() : count(0), _list(list<T>()) {}

  void Enqueue(T data) {
    _list.push_back(data);
    count++;
  }

  void Dequeue() {
    if (!count)
      cout << "Empty Queue" << endl;
    _list.pop_front();
  }
  T Peek() {
    if (!count) {
      cout << "Empty Queue" << endl;
      return NULL;
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
  Queue<string> queue;
  queue.Enqueue("random");
  queue.Enqueue("alok");
  queue.Enqueue("aishwarya");
  queue.Enqueue("pushpa");
  queue.Enqueue("akhil");
  cout << "queue.Top(): " << queue.Peek() << endl;
  cout << "queue.Size(): " << queue.Size() << endl;
  queue.Print();
  queue.Dequeue();
  cout << "After Dequeue: ";
  queue.Print();
}
