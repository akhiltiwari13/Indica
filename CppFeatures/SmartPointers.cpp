/**
 * File              : SmartPointers.cpp
 * Author            : akhil <akhiltiwari.13@gmail.com>
 * Date              : 12.06.2021
 */

#include <iostream>
#include <memory> //for shared_ptr && unique_ptr

class A{
    public:
        A(int x):x(x){
            std::cout<< "A's constructor"<<std::endl;
        }

    private:
        int x;
};

class B{
    public:
        B(int x, int y):pA1(new A(x)), pA2(new A(y)){
            std::cout<< "B's constructor"<<std::endl;
        }

        B(const B& obj):pA1(new A(*obj.pA1)), pA2(new A(*obj.pA2)){
            std::cout<< "B's copy constructor"<<std::endl;
            
        }
         
        /* unique_ptrs copy constructor is deleted. */
        const B& operator =( const B& obj ){
            std::cout<< "B's copy assignment operator"<<std::endl;
            *this->pA1 = *obj.pA1; 
            *this->pA2 = *obj.pA2; 
            return *this;
        }

        ~B(){
            std::cout<< "B's destructor called."<<std::endl;
        }
    private:
        std::unique_ptr<A> pA1;
        std::unique_ptr<A> pA2;
};

int main()
{
    B b1(4, 5);
    B b2(7, 8);

    B b4(7, 8);
    b4.~B(); //explicit destructor call.

    B b3=b1;
    b2 = b1; 
}
