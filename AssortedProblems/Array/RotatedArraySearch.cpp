#include<bits/stdc++.h>

#define REP(a,n) for(int i=a; i<n; i++)

using namespace std;

template <typename T>
void print(T t)
{
    cout<<"print"<<endl;
    for(auto itr: t)
    {
        cout<<itr<<" ";
    }
    cout<<endl;
}

int bin_search(vector<int> &v, int begin, int end, int k)
{
    if(begin<=end)
    {
        int mid=(begin + end)/2;
        if(v[mid]==k) return mid;
        else if(v[mid]<k) return bin_search(v, mid+1, end, k);
        else return bin_search(v, begin, mid-1, k);
    }
    else
   return -1;
}


int fun(vector<int> &v, int k)
{
    int ind1=0, ind2=1, s=v.size();
    if(s==1) return bin_search(v, ind1, ind1, k);
    while(ind2<s){
        if(v[ind2]<v[ind1])
        {
            break;
        }
        ind2++; ind1++;
    }

    int r1=bin_search(v, 0, ind1, k);
    int r2=bin_search(v, ind2, s-1, k);


    if(r1==-1 && r2==-1) return -1;
    if(r1== -1) return r2;
    if(r2== -1) return r1;

    return -1;      //shouldn't come to this point.
}

int main()
 {
    int n_t, s_t, ele,k; // declaring variables for # of test cases and each test case size.
    vector<int> arr;

    cin>>n_t;
    REP(0,n_t){
        arr.clear();
        cin>>s_t; // taking in the test case size.
        REP(0,s_t)
        {
            cin>>ele;
            arr.push_back(ele);
        }
        cin>>k;
       cout<<fun(arr,k)<<endl;
    }
	return 0;
}
