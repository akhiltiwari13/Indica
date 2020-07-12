#include <bits/stdc++.h>
using namespace std;

int recursive_fib(int num)
{
	if(num==0)
	{
		return num;
	}

	if(num==1)
	{
		return num;
	}
	else
	{
		return recursive_fib(num-1) + recursive_fib(num-2);
	}
}

int iterative_fib(int num)
{
	if(num<=1)
	{
		return 1;
	}
	int prev1=1;
	int prev2=0;
	int result=0;
	for(int i=0; i<num-1; i++ )
	{
		result=prev1+prev2;
		prev2=prev1;
		prev1=result;
	}
	return result;
}



int main (void)
{
	cout<<"enter the number: ";
	int num;
	cin>>num;
	cout<<"iterative fibonacci result: "<<iterative_fib(num)<<endl;
	cout<<"recursive fibonacci result: "<<recursive_fib(num)<<endl;
	return 0;
}
