#include <iostream>
#include <vector>

using namespace std;


int maxSubArray(vector<int>& nums) {
    if(nums.empty()) return INT_MIN;
    int l_max= nums[0];
    int g_max= nums[0];

    for(int i=1; i<=nums.size(); ++i){
        l_max = std::max((l_max + nums[i]), nums[i]);
        g_max = std::max(g_max, l_max);
    }     
    
    return g_max;
    }


int main( int argc, char* argv[]) {
}
