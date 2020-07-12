#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	vector<int> results;
	cout<<"enter a decimal number: ";
	int num;
	cin>>num;
	cout<<"it's binary equivalent is: ";
	while(num)
	{
		results.push_back(num%2);
		num/=2;
	}
	reverse(begin(results), end(results));
	for(auto itr: results)
	{
		cout<<itr;
	}
	cout<<endl;
}
