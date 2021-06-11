/**
 * File              : LowLevelThreadFeature.cpp
 * Author            : akhil <akhiltiwari.13@gmail.com>
 * Date              : 05.06.2021
 */

// concurrency/async1.cpp
#include <chrono>
#include <exception>
#include <iostream>
#include <random>
#include <thread>
#include <string>

using namespace std;

void doSomething(int num, char c) {
    try {
        // random-number generator (use c as seed to get different sequences)
        default_random_engine dre(42 * c);
        uniform_int_distribution<int> id(10, 1000);
        for (int i = 0; i < num; ++i) {
            this_thread::sleep_for(chrono::milliseconds(id(dre)));
            cout.put(c).flush();
        }
    }
    /* make sure no exception leaves the thread and terminates the program. */
    catch (const exception &e) {
        cerr << "THREAD-EXCEPTION (thread " << this_thread::get_id()
            << "): " << e.what() << endl;
    } catch (...) {
        cerr << "THREAD-EXCEPTION (thread " << this_thread::get_id() << ")" << endl;
    }
}

int main() {
    try {
        std::thread t1(doSomething,5,'*');
        std::cout << "fg thread started... id=" << t1.get_id()<<std::endl;

        /* start doSomething in background threads. */
        for(int i=0; i<5; i++){
            std::thread t(doSomething,10,'a'+i);
            std::cout << "bg thread started... id=" << t.get_id()<<std::endl;
            t.detach();
        }

        cin.get();
        //wait for input.

        std::cout << "join fg thread id=" << t1.get_id()<<std::endl;
        t1.join();
        /* t1 needs to be joined. */
    } catch (std::exception &e) {
        std::cout << "exception in main thread: " << std::this_thread::get_id()
            << " " << e.what() << std::endl;
    }
}
