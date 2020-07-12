#include<bits/stdc++.h>

#define REP(a,n) for(int i=a; i<n; i++)


using namespace std;

//function to get maximum pieces.
int fun(int len, vector<int> &sizes,vector<int> &lookup, int min)
{
	if(len==0)	return 0;
	if(len<0) return INT_MIN;
	if(lookup[len]) return lookup[len];
	else{
		int best=INT_MIN;
		for(auto itr: sizes)
	best= max(best, fun(len-itr, sizes,lookup, min)+1);

		lookup[len]=best;
		return lookup[len];
	}
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
    	lookup.assign(len+1, 0);
        REP(0,3)
        {
            cin>>part;
            vec.push_back(part);
        }
       min= *min_element(begin(vec), end(vec));
       lookup[0]=0;
       for(int i=1; i<min; i++)
       {
       	lookup[i]=INT_MIN;
       }
       cout<<fun(len, vec,lookup, min)<<endl;
    }
	return 0;
}
