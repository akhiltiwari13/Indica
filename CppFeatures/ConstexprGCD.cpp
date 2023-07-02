/* A `constexpr` function is a function that can be evaluated at compile time when all its arguments are constant expressions. This means that the function can be used in other constant expressions, such as initializing a `constexpr` variable or providing a non-type template argument. A `constexpr` function must satisfy certain requirements, such as having a return type that is a literal type, and each of its parameters must also be of a literal type. In C++11, a `constexpr` function could only contain a single return statement, but this restriction was relaxed in C++14, allowing for more complex `constexpr` functions. */
/* The main advantage of using `constexpr` functions is that they can improve the performance of programs by doing computations at compile time rather than run time. */

#include <iostream>
using namespace std;


constexpr int gcdCalc(int a, int b){
    return b==0? a: gcdCalc(b,a%b);
}

int main(int argc, char* argv[]){
    constexpr int a = 100;
    constexpr int b = 75;

    constexpr auto result = gcdCalc(a,b);

    std::cout<<"gcdCalc( "<<a << ", "<< b<< " )="<<result<<std::endl;
    std::cout<<"gcdCalc( "<<a << ", "<< b<< " )="<<gcdCalc(a,b)<<std::endl;
    return 0;
}
