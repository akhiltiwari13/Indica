#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

class Semaphore {
public:
  void Acquire() {
    unique_lock<mutex> lock(mtx);
    while (taken == count) {
      cond.wait(lock);
    }
    ++taken;
  }

  void Release() {
    lock_guard<mutex> lock(mtx); // lock_guard is locked only once on creation
                                 // and unlocked on destruction.
    --taken;
    cond.notify_all();
  }

private:
  unsigned short count;
  unsigned short taken;

  mutex mtx;
  condition_variable cond;
};

int main() {}
