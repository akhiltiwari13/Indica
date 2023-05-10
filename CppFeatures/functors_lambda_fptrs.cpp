#include<iostream>
using namespace std;

class FunctorDemo{
    private:
        int _state{5};
    public:
        int operator()(int num){
            std::cout<<"*functor* ";
            return _state+num;
        }
};

int functPtr(int param1){
    std::cout<<"*function pointer* ";
    return 7+param1;
}


template<typename T>
void delegator(int param, T delegatee){
    std::cout<<"delegated to-> "<< delegatee(param)<<std::endl;
}

int main( int argc, char* argv[]){
    int (*fptr)(int);
    fptr=&functPtr;
    int local{55};
    FunctorDemo fobj{};

    auto lambda1 = [&](int param){std::cout<<"*lambda* "; return 7+param;};
    delegator(7, lambda1);
    delegator(7, fobj);
    delegator(7, fptr);

    return 0;
}