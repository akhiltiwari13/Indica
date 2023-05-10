#include <chrono>
#include <functional>
#include <iostream>
#include <map>
#include <thread>
#include <unordered_set>
#include <regex>

class A {
public:
  virtual void foo() { std::cout << "A's foo" << std::endl; }
};

class B : public A {
public:
  void foo() { std::cout << "B's foo" << std::endl; }
};

auto getId() {
  auto id = 123456;
  return id;
}

int main(int argc, char *argv[]) {
  std::map<int, int> m = {{1, 10}, {2, 20}, {3, 30}};
  std::vector<int> v = {23,3,4,5, 34, 2};
  // std::cout<<"out:"<<m[1]+m[4]+m.size()<<std::endl;
  // for(auto itr: m){
  //     std::cout<<itr.first<<"\t"<<itr.second<<std::endl;
  // }
  auto id = getId();
  for (int i = 0; i < 10; ++i) {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << id << std::endl;
  }

  std::sort(v.begin(), v.end(), std::greater());
  return 0;
}

// what happens on returing reference to a local variable
