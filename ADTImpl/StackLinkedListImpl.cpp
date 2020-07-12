#include <forward_list>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::forward_list;
using std::string;

/* Linked-list implementation of a stack. */
template <class T> class Stack {
public:
  unsigned int count;
  forward_list<T> _list;
  Stack() : count(0), _list(forward_list<T>()) {}

  void Push(T data) {
    _list.push_front(data);
    count++;
  }

  void Pop() {
    if (!count)
      cout << "Empty Stack" << endl;
    _list.pop_front();
  }
  T Top() {
    if (!count) {
      cout << "Empty Stack" << endl;
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
  Stack<string> stack;
  stack.Push("akhil");
  stack.Push("alok");
  stack.Push("aishwarya");
  stack.Push("pushpa");
  cout << "stack.Top(): " << stack.Top() << endl;
  cout << "stack.Size(): " << stack.Size() << endl;

  stack.Print();
}
