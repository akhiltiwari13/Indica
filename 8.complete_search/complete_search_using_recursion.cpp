// author: akhil
//  finds all the subsets of elements of an array using recursion.

#include <bits/stdc++.h>
#define REP(a,b) for(int i=a; i<b; i++)

using namespace std;

vector<int> arr={0,1,2};
vector<int> power_set;
int set_size= arr.size();

void search(int k)
{
	if(k==set_size)
	{
		cout<<"{";
		for(int i=0; i<power_set.size(); i++)
		{
			cout<<power_set[i];
			if(i!=power_set.size()-1)
				cout<<", ";
		}
		cout<<"}"<<endl;
		return;
	}
	search(k+1);
	power_set.push_back(arr[k]);
	search(k+1);
	power_set.pop_back();
}

int main(void)
{
	cout<<"given set: "<<endl;
	for(auto itr: arr)
	{
		cout<<itr<<endl;
	}

	cout<<"power-set initially: "<<endl;
	for(auto itr: power_set)
	{
		/*for(auto itr_inner: itr)
		  {
		  cout<<itr_inner<<", ";
		  }*/
		cout<<itr;
		cout<<endl;
	}


	cout<<"generating power set: "<<endl;
	search(0);

	/*	cout<<"power-set after complete search algorithm: "<<endl;
		for(auto itr: power_set)
		{
		for(auto itr_inner: itr)
		{
		cout<<itr_inner<<", ";
		}
		cout<<itr;
		cout<<endl;
		}*/

	return 0;
}
