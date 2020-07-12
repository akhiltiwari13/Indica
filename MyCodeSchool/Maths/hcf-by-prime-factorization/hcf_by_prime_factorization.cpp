// finds the highes common factor of two numbers by prime factorization method.
// the TIME COMPLEXITY of this algorithm is O(root(b)) where b is the number of digits in the larger number .
#include <bits/stdc++.h>

using namespace std;

int main (void)
{
	int num1, num2;
	vector<int> factors1;
	vector<int> factors2;


	cout<<"number 1: ";
	cin>>num1;

	cout<<"number 2: ";
	cin>>num2;


	for(int i=2; i<=sqrt(num1); i++)
	{
		if(num1%i==0)
		{
			while(!(num1%i))
			{
				num1/=i;
				factors1.push_back(i);
			}
		}
	}
	if(num1!=1)
	{
		factors1.push_back(num1);
	}


	// factors of number 2
	for(int i=2; i<=sqrt(num2); i++)
	{
		if(num2%i==0)
		{
			while(!(num2%i))
			{
				num2/=i;
				factors2.push_back(i);
			}
		}
	}
	if(num2!=1)
	{
		factors2.push_back(num2);
	}

	// getting the common elements to calculate the greatest common divisor.
	vector<int> result;
	set_intersection(begin(factors1), end(factors1), begin(factors2), end(factors2), back_inserter(result));

	auto hcf= accumulate(begin(result), end(result), 1, [](int element, int  total)->int{return total*=element;});
	cout<<"highest common factor is: "<<hcf<<endl;

	return 0;
}
