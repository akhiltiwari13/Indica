#include <bits/stdc++.h>
using namespace std;

int factorial_recursive(int num)
{
	if(num==1)
	{
		return num;
	}
	else{
		return num*factorial_recursive(num-1);
	}
}

int main(void)
{
	cout<<"number: "<<endl;
	int num;
	cin>>num;
	cout<<"factorial: "<<factorial_recursive(num);
	return 0;
}
