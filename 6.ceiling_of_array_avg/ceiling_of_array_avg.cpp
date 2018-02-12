#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int size;
	int num;
	vector<int> arr;

	cin>>size;
	for(int i=0; i<size; i++)
	{
		cin>>num;
		arr.push_back(num);
	}

	auto sum= accumulate(begin(arr), end(arr), 0);


	auto avg= sum/size;



	if(size*avg<=sum)
	{
		avg++;
	}
	cout<<avg;

	return 0;
}

