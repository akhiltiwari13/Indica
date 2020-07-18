#include <bits/stdc++.h>
using namespace std;

int slower_exponentiation(int num, int power)
{
	if(power==0)
		return 1;
	return (num* slower_exponentiation(num, power-1));
}


int faster_exponentiation(int num, int power)
{
	if(power==0)
		return 1;
	if(power%2==0)
	{
		int tmp= faster_exponentiation(num, power/2);
		return tmp*tmp;
	}
	else
	{
		return (num* faster_exponentiation(num, power-1));
	}
}

int main(void)
{


	int num, power;
	cout<<"enter the number: ";
	cin>>num;
	cout<<"enter the power: ";
	cin>>power;
	cout<<"slower num^power: "<<slower_exponentiation(num, power)<<endl;
	cout<<"faster num^power: "<<faster_exponentiation(num, power)<<endl;
	return 0;
}
