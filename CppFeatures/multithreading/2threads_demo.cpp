#include <iostream>
#include <sstream>
#include <string>
#include <thread>

std::mutex mut{};

void funct1(std::string &str) {
  std::string tmp{};
  while (getline(std::cin, tmp)) {
    mut.lock();
    str.assign(tmp);
    std::cout << "releasing lock" << std::endl;
    mut.unlock();
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
}

void funct2(std::string &str) {
  while (true) {
    mut.lock();
    std::cout << "acquired lock for reading from: "<< std::this_thread::get_id() << str << std::endl;
    mut.unlock();
    std::this_thread::sleep_for(std::chrono::seconds(5));
  }
}

int main(int argc, char *agrv[]) {

  std::string sharedString{};

  std::thread t1(funct1, std::ref(sharedString));
  std::thread t2(funct2, std::ref(sharedString));
  std::thread t3(funct2, std::ref(sharedString));

  t1.join();
  t2.join();

  return 0;
}
