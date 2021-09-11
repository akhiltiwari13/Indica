#include <chrono>
#include <complex>
#include <cstdio>
#include <iomanip> //for stream manipulators.
#include <iostream>

int main() {
  int a, b;
  // as long as input of a and b is successful
  /* while (std::cin >> a >> b) { */
  /*     // output a and b */
  /*     std::cout << "a: " << a << " b: " << b << std::endl; */
  /* } */
  double x, y;
  // operands
  // print header string
  std::cout << "Multiplication of two floating point values" << std::endl;
  // read ﬁrst operand
  std::cout << "first operand: ";
  if (!(std::cin >> x)) {
    // input error
    // => error message and exit program with error status
    std::cerr << "error while reading the first floating value" << std::endl;
    return EXIT_FAILURE;
  }
  // read second operand
  std::cout << "second operand: ";
  if (!(std::cin >> y)) {
    // input error
    // => error message and exit program with error status
    std::cerr << "error while reading the second floating value" << std::endl;
    return EXIT_FAILURE;
  }
  // print operands and result
  std::cout << x << " times " << y << " equals " << x * y << std::endl;

  // overloaded << operator for complex class.
  std::complex<float> c(3.1, 7.4);
  std::cout << "complex c:" << c << std::endl; // manipulator
  std::cout << "enter complex:" << std::endl;
  std::cin >> c;
  std::cout << "read complex c:" << c << std::endl; // manipulator

  // process and print current date and time:
  auto now = std::chrono::system_clock::now();
  time_t t = std::chrono::system_clock::to_time_t(now);
  tm *nowTM = localtime(&t);
  std::cout << std::put_time(nowTM, "date: %x\ntime: %X\n") << std::endl;
  // read date:
  tm *date;
  /* std::cout << "new date: "; */
  /* std::cin >> std::get_time(date, "%x"); // read date @what should be the output? */
  /* if (!std::cin) { */
  /*   std::cerr << "invalid format read" << std::endl; */
  /* } */

  /* demonstrating sync for C and C++'s streams. */
 int a1,a2;
 scanf("%d", &a1);
 std::cin>>a2;
 std::cout<<"a1: "<<a1<<std::endl;
 printf("a2: %d",a2);
  return 0;
}
