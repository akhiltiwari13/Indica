#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

template <class T> class Queue {
public:
  T *arr;
  unsigned int count, size, head;
  int tail;
  Queue() : arr(new T[4]), count(0), size(4), head(0), tail(-1) {}

  // member functions for stack operations.
  void Copy(T *old, T *nw, unsigned int head) {
    unsigned int targetIndex = 0;
    for (unsigned int i = head; targetIndex <= count; targetIndex++) {
      nw[targetIndex] = old[i];
      i = (i + 1) % size;
    }
  }

  void Enqueue(T data) {
    if (count == size) // queue is full
    {
      T *tmp_arr = new T[size * 2];
      Copy(arr, tmp_arr, head);
      delete[] arr;
      arr = tmp_arr;
      size *= 2;
    }
    tail = (tail + 1) % size;
    arr[tail] = data;
    count++;
  }

  void Dequeue() {
    if (!count)
      cout << "Empty Queue" << endl;
    else {
      count--;
      head = (head + 1) % size;
    }
  }
  T Peek() {
    if (!count) {
      cout << "Empty Queue" << endl;
      return NULL;
    } else {
      return arr[head];
    }
  }
  void Print() {
    int i = head;
    unsigned int tmp = 0;
    while (tmp <= count) {
      cout << arr[i] << " ";
      i = (i + 1) % size;
      tmp++;
    }
    cout << endl;
  }

  auto Size() -> unsigned int { return count; }
};

int main() {
  Queue<string> queue;
  queue.Enqueue("random");
  queue.Enqueue("alok");
  queue.Enqueue("aishwarya");
  queue.Enqueue("pushpa");
  queue.Enqueue("akhil");
  cout << "queue.Peek(): " << queue.Peek() << endl;
  cout << "queue.Size(): " << queue.Size() << endl;
  queue.Print();
  queue.Dequeue();
  cout << "After Dequeue: ";
  queue.Print();
}
