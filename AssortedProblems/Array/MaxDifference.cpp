#include<bits/stdc++.h>

#define REP(a,n) for(int i=a; i<n; i++)

using namespace std;


int fun(vector<int> &v)
{
    int max_diff=0, min_ind=0;
    auto s= v.size();

    // for each element find the maximum possible dif for it.
    for(int i=0; i<s; i++)
    {
        max_diff= max(max_diff, v[i]-v[min_ind]);
        min_ind = min(v[i], v[min_ind] )==v[i]?i:min_ind;
    }
    return max_diff;
}
int main()
 {
    int n_t, s_t; // declaring variables for # of test cases and each test case size.
    vector<int> v;
    int ele{};
    cin>>n_t;
    REP(0,n_t){
        cin>>s_t; // taking in the test case size.
        v.clear();

        REP(0,s_t)
        {
            cin>>ele;
            v.push_back(ele);
        }
        cout<<fun(v)<<endl;
    }
	return 0;
}
