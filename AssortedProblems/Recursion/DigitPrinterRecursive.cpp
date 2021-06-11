#include <bits/stdc++.h>

using namespace std;

long solve(long num){
    if(num ==0){
        return 0;
    }
    else{
        auto dig= num%10;
        auto sum= dig + solve(num/10);
        std::cout<<dig;
        return sum;
    }
}

int main(){
    long n=34587653229;
    std::cout<<"num:"<<n<<std::endl;
    auto result=solve(n);
    std::cout<<std::endl<<"sum of digits= "<<result<<std::endl;
    return 0;
}
