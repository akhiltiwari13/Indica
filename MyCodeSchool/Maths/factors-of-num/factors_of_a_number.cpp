// program to calculate all the factors of a number.
// time complexity of this approach is O(sqrt(n)).
#include <bits/stdc++.h>

using namespace std;

int main (void)
{
	int num;
	vector<int> factors;
	factors.push_back(1);

	cout<<"number: ";
	cin>>num;

	for(int i=2; i<sqrt(num); i++)
	{
		if(num%i==0)
		{
			factors.push_back(i);
			if(num/i!=i)
			{
				factors.push_back(num/i);
			}
		}
	}

	// print the factors.
	cout<<"factors: "<<endl;
	for(auto itr: factors)
	{
		cout<<itr<<endl;
	}



	return 0;
}
