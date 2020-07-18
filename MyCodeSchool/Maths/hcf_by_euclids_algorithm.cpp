// iterative and recursive implementation of euclid's algorithm to compute HCF, the TIME COMPLEXITY of this algorithm is O(log(b)); where b is the number of digits in the larger number to compute hcf. 
#include <bits/stdc++.h>

using namespace std;

// iterative implementation of euclids algorithm.
int iterative_hcf_euclid(int divisor, int divident)
{
	int remainder;
	while(divisor) // in euclid's algorithm we keep dividing untill the divisor becomes 0.
	{ 
		remainder=divident%divisor;
		divident=divisor;
		divisor=remainder;

	}
	return divident;
}

// recursive implementation of euclid's algorithm.
int recursive_hcf_euclid(int divisor, int divident)
{
	if(!divisor)
	{
		return divident;
	}
	else
	{
		return recursive_hcf_euclid(divident%divisor, divisor);

	}
}

int main (void)
{
	int num1, num2;
	cout<<"number 1: ";
	cin>>num1;

	cout<<"number 2: ";
	cin>>num2;

	cout<<"highest common factor: ";
	cout<<iterative_hcf_euclid(num1, num2)<<endl;
	cout<<"using recursive implementation of euclid's algorithm: "<<recursive_hcf_euclid(num2, num1)<<endl;
	return 0;
};
