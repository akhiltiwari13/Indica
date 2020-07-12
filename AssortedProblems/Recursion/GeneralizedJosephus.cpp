#include<bits/stdc++.h>

#define REP(a,n) for(int i=a; i<n; i++)

using namespace std;

// fun to get the surviving position
int fun(int num, int k)
{
	if(num==1)
		return 0;
		else{
		return (fun(num-1, k)+k)%num;
		}
}


int main()
 {
    int n_t, s_t, k; // declaring variables for # of test cases and each test case size.

    cin>>n_t;

    REP(0,n_t){
        cin>>s_t; // taking in the test case size.
        cin>>k;
        cout<<fun(s_t, k)<<endl;
    }
	return 0;
}
