#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

template <class T> class Stack {
public:
  T *arr;
  unsigned int count, size;
  Stack() : arr(new T[4]), count(0), size(4) {}

  // member functions for stack operations.
  void Copy(T *old, T *nw) {
    for (unsigned int i = 0; i < count; i++) {
      nw[i] = old[i];
    }
  }
  void Push(T data) {
    if (count == size) {
      T *tmp_arr = new T[size * 2];
      Copy(arr, tmp_arr);
      delete[] arr;
      arr = tmp_arr;
    }
    arr[count++] = data;
  }

  void Pop() {
    if (!count)
      cout << "Empty Stack" << endl;
    else
      count--;
  }
  T Top() {
    if (!count) {
      cout << "Empty Stack" << endl;
      return NULL;
    } else {
      return arr[count - 1];
    }
  }
  void Print() {
    for (int i = (int)count - 1; i >= 0; i--) {
      cout << arr[i] << " ";
    }
    cout << endl;
  }

  auto Size() -> unsigned int { return count; }
};

/* main */
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
