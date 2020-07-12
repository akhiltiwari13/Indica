#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	cout<<"enter a number: ";
	int num, flag=0;
	cin>>num;

	if(num<2)
		cout<<"enter a valid number greater than 2"<<endl;

	for(int i=2; i<=sqrt(num); i++)
	{
		if(num%i==0)
		{
			cout<<i<<" is a factor."<<endl;
			flag++;
		}

	}
	if(!flag)
		cout<<num<<" is a  prime number"<<endl;
	return 0;
}

