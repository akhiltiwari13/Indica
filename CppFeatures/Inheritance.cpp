#include <iostream>

class A {
public:
  virtual void foo() { std::cout << "A's foo" << std::endl; }
};

class B : public A {
public:
  void foo() override { std::cout << "B's foo" << std::endl; }
};

class base {
public:
  static int i;
  int j;
  void func() {
   int funci;
   std::cout<<"func"<<std::endl;
  }
};

class derived : public base {
public:
  int k;
  void func1() {
   int func1i;
   std::cout<<"func1"<<std::endl;
  }
};
int main(int argc, char *argv[]) {
  //  A *a = new A();
  //  B *b = dynamic_cast<B*>(a);
  //  b->foo();
  std::cout<<sizeof(base)<<std::endl;
  std::cout<<sizeof(derived)<<std::endl;
  return 0;
}