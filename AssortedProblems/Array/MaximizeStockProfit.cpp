#include<bits/stdc++.h>

#define REP(a,n) for(int i=a; i<n; i++)

using namespace std;

void fun(vector<int>  &vec)
{
    vec.push_back(INT_MIN);
    vector<int> v_min, v_max;
    int max_profit=0, i=0;

    while(i<vec.size()-1)
    {
        // for calculating the min.
        if(vec[i+1]>vec[i] && v_min.size()==v_max.size())
        {
            v_min.push_back(i);
            i++;
            continue;
        }
        //for calculating the max.
        if(vec[i+1]<vec[i]  && v_min.size()==1+v_max.size())
        {
            v_max.push_back(i);
            i++;
            continue;
        }
        i++;
    }
    for(int i=0; i<v_max.size(); i++)
    {
        cout<<"("<<v_min[i]<<" "<<v_max[i]<<")"<<" ";
    }
    if(v_min.empty())
        cout<<"No Profit";
    cout<<endl;
    return;
}

int main()
 {
    int n_t, s_t; // declaring variables for # of test cases and each test case size.
    int ele;
    vector<int> vec;
    cin>>n_t;
    REP(0,n_t){
        cin>>s_t; // taking in the test case size.
        vec.clear();
        REP(0,s_t)
        {
            cin>>ele;
            vec.push_back(ele);

        }
        fun(vec);
    }
	return 0;
}
