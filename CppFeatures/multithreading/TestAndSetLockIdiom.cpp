/* The test-and-set lock is a synchronization primitive used in concurrent programming to provide mutual exclusion. It is based on a hardware instruction called "test-and-set" or "atomic exchange". The test-and-set operation atomically tests the lock state and sets it to a new value in a single uninterruptible step. */

  

#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

class TestAndSetLock{
    private:
        std::atomic<bool> lock{false};

    public:
        TestAndSetLock():lock(false){}

        void acquire(){
            std::cout<<"acquiring lock"<<std::endl;
            while(lock.exchange(true)){
            }
        }

        void release(){
            lock.store(false);
            std::cout<<"released lock"<<std::endl;
        }

};

void incrementCriticalRes(int& i, TestAndSetLock& tns){
    tns.acquire();
    this_thread::sleep_for(std::chrono::milliseconds(500));
    ++i;
    tns.release();
}

int main(int argc, char* argv[]){
    int critical_resource{0};
    std::vector<std::thread> vt{};
    TestAndSetLock tnsl{};

    for(int i=0; i<5; ++i){
        // all arguments are passed by value by default to a std::thread.
        vt.push_back(std::thread(incrementCriticalRes, std::ref(critical_resource), std::ref(tnsl)));
    }

    for(int i=0; i<5; ++i){
        vt[i].join();
    }

    cout<<"critical_resource: "<<critical_resource<<std::endl;

    return 0;
}
