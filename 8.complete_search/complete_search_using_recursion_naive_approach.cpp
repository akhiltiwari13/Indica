// author: akhil
//  finds all the subsets  of a given set of elements using naive recursion.

#include <bits/stdc++.h>
#include <string.h>

using namespace std;

string given_set= "abc";
vector<string> power_set;
int size=given_set.size();

void gen_subset( int index , vector<string> subset)
{
	for(auto itr: power_set)
	{
		subset.push_back(itr+given_set[index]);
	}

	for(auto itr: subset)
	{
		power_set.push_back(itr);
	}

}

int main()
{
	cout<<"step 1"<<endl;
	vector<string> subset;
	for(int i=0; i<=2; i++)
	{
		int j=0;
		for(auto itr: power_set)
		{
			cout<<itr+given_set[0]<<endl;
			subset.push_back(itr+given_set[i]);
			cout<<subset[j];
		}

		for(auto itr: subset)
		{
			power_set.push_back(itr);
		}
	}
	cout<<"step 2"<<endl;
	for(auto itr1: power_set)
	{
		cout<<itr1<<endl;
	}
	cout<<"step 3"<<endl;
	return 0;
}
