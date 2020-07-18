// this is still incomplete.
#include <iostream>
#include <vector>
using namespace std;

vector<int> arr={6,2,5,1,7,4,8,3};
int len= arr.size();
vector<int> lookup(len,0);
vector<bool> looked(len,false);

int solve(int n)
{
	if(looked[n])
	{
		return lookup[n];
	}
	if(n==0)
	{
		lookup[n]=1;
		looked[n]=true;
		return lookup[n];
	}
	else
	{
		for(int i=n-1; i<=0; i--)
		{
		if(arr[n]>arr[i])
		{
			lookup[n]=max(lookup[n], solve(n-1)+1);
		}

		}

		looked[n]=true;
		return lookup[n];
	}

}

int main()
{
	for(auto itr: lookup)
	{cout<<itr<<" ";
	}
	cout<<endl;
	cout<<"longest increasing subsequence: "<<solve(len-1)<<endl;
	for(auto itr: lookup)
	{cout<<itr<<" ";
	}
	cout<<endl;
	return 0;
}
