#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

void printThreadId(){
    cout<<"thread id: "<<this_thread::get_id()<<endl;
}

void printThreadIdAndMsg(const std::string& msg){
    cout<<"message: "<<msg<<endl;
    cout<<"thread id: "<<this_thread::get_id()<<endl;
}


void printThreadIdAndMsgSynchronized(const std::string& msg, std::mutex& mu){
    std::lock_guard<std::mutex> guard(mu);
    cout<<"synchronized message: "<<msg<<endl;
    cout<<"synchronized thread id: "<<this_thread::get_id()<<endl;
}

auto lfunct = [](const std::string& msg){std::cout<<"msg from lambda funct: "<<msg<<std::endl;};

int main(int argc, char* argv[]){
    
    // Get the current time point
    auto now = std::chrono::system_clock::now();
    // Calculate the time point 2 seconds from now
    auto wakeUpTime = now + std::chrono::seconds(2);

    thread t1(printThreadId);
    thread t2(printThreadId);
    thread t3(printThreadId);
    thread t4(printThreadId);
    thread t5(printThreadIdAndMsg, std::move("Some message to be printed"));
    thread t6(lfunct, std::move("*lfunct msg*"));

    //synchronized using lock guard
    std::mutex mut{};
    thread t7(printThreadIdAndMsgSynchronized, std::move("thread 7"), std::ref(mut));
    thread t8(printThreadIdAndMsgSynchronized, std::move("thread 8"), std::ref(mut));
    thread t9(printThreadIdAndMsgSynchronized, std::move("thread 9"), std::ref(mut));

    this_thread::sleep_until(wakeUpTime);
    printThreadId();

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    
    t7.join();
    t8.join();
    t9.join();

    std::cout<<"max concurrent thread count for the hardware: "<<std::thread::hardware_concurrency()<<std::endl;
    return 0;
}
