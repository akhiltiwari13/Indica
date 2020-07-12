#include<bits/stdc++.h>

#define REP(a,n) for(int i=a; i<n; i++)


using namespace std;

// iterative function to get the maximum cuts
int fun(int len, vector<int> &sizes, vector<int> &lookup, int min)
{
	for(int i=min; i<=len; i++)
	{
		for(auto itr: sizes)
		{
			if((i-itr) >=0)
			lookup[i]=max(lookup[i], 1+ lookup[i-itr]);
		}
	}
	return lookup[len];
}



int main()
 {
    int n_t, len, part, min; // declaring variables for # of test cases and each test case size.
    vector<int> vec;
    vector<int> lookup;

    cin>>n_t;
    REP(0,n_t){
        vec.clear();
        cin>>len; // taking in the test case size.
    	lookup.assign(len+1, INT_MIN);
        REP(0,3)
        {
            cin>>part;
            vec.push_back(part);
        }
       sort(begin(vec), end(vec));
       lookup[0]=0;
       cout<<fun(len, vec,lookup, min)<<endl;
    }
	return 0;
}
