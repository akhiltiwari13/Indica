#include <deque>
#include <iostream>
#include <array>
#include <list>
#include <forward_list>
#include <algorithm>

template <typename T>
void printElements (const T& coll)
{
    for (const auto& elem : coll) {
        std::cout << elem << " ";
    }
    std::cout<<std::endl;
}

int main(int argc, char* argv[]){

    //deque
    std::deque<float> dq1{4.0, 5.0, 6.0};
    dq1.push_front(13.0);
    dq1.push_front(16.0);
    dq1.push_back(16.0);
    printElements(dq1);
    /* dq1.resize(1); */
    /* printElements(dq1); */

    //array
    std::array<int,5> ar1{5,-23,1,-34, 56};
    std::array<int,5> ar2{5,-23,1};
    printElements(ar1);
    printElements(ar2);
    

    //list
    std::list<char> ls1;
    for(auto c='a'; c<='z'; ++c){
        ls1.push_back(c);
    }

    printElements(ls1);
    std::cout<<"ls1.empty():"<< (ls1.empty()?"true":"false")<<std::endl;
    std::cout<<"ls1.front():"<< ls1.front()<<std::endl;
    std::cout<<"ls1.back():"<< ls1.back()<<std::endl;

    //forward_list
    std::forward_list<int> fls1{1,2,3};

    //associative containers

    //unordered containers


    return 0;
}
