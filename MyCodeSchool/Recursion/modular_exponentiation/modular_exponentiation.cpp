#include <bits/stdc++.h>
using namespace std;

int modular_exponentiation(int num, int power, int mod)
{
	if(power==0)
		return (1%mod);
	if(power%2==0)
	{
		int tmp= modular_exponentiation(num, power/2, mod);
		return (tmp*tmp)%mod;
	}
	else
	{
		return (num%mod* modular_exponentiation(num, power-1, mod))%mod;
	}
}
int main(void)
{


	int num, power, mod;
	cout<<"enter the number: ";
	cin>>num;
	cout<<"enter the power: ";
	cin>>power;
	cout<<"enter the modular: ";
	cin>>mod;
	cout<<"modular exponentiation result: "<<modular_exponentiation(num, power, mod)<<endl;
	return 0;
}
