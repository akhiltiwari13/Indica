// finds out the prime factorization of a number, using the successive division method.
#include <bits/stdc++.h>

using namespace std;

int main (void)
{
	int num;
	int count=0;

	cout<<"number: ";
	cin>>num;

	for(int i=2; i<=sqrt(num); i++)
	{
		if(num%i==0)
		{
			count=0;

			while(!(num%i))
			{
				num/=i;
				count++;
			}
		cout<<i<<"^"<<count;
		cout<<" * ";
		}
	}

	if(num!=1)
	{
		cout<<num<<"^"<<1;
	}
	else{
		cout<<1;
	}
	cout<<endl;

	return 0;
}
