#include <iostream>
#include <memory>

#include <vector>
#include <unordered_map>

template <typename T>
class BinaryTree{
    public:
        BinaryTree():data(),left(nullptr),right(nullptr){}
        BinaryTree(T d):data(d),left(nullptr),right(nullptr){}
        BinaryTree(T d, std::unique_ptr<T>& l, std::unique_ptr<T>& r):data(d),left(l),right(r){}

    private:
        T data;
        std::unique_ptr<T> left;
        std::unique_ptr<T> right;
};


// generic output operator for BinaryTree 
// print binary tree in all three formats.
    template <typename T>
std::ostream& operator << (std::ostream& strm,
        std::unique_ptr<BinaryTree<T>>& binTree)
{
    /* return strm << "[" << p.first << "," << p.second << "]"; */
}


bool doTestsPass(){
    std::vector<std::pair<std::unordered_map<int,int>,int>> testCases={
        /* sample test cases. */
    };
    bool passed = true;
    for(unsigned int ii =0 ; ii< testCases.size(); ++ii){
        /* int actual = largestTree(testCases[ii].first); */
        /* if(actual != testCases[ii].second){ */
        /*     passed = false; */
        /*     std::cout << "Failed for case" << ii << ", expected "<< testCases[ii].second<< ", actual "<< actual <<std::endl; */
        /* } */
    }
    return passed;
}

int main() {
    /* run the tests. */
    if(doTestsPass()){
        std::cout<< "ALL TESTS PASS." << std::endl;
    }
    else{
        std::cout<< "TESTS FAILED."<<std::endl;
    }
    return 0;
}
