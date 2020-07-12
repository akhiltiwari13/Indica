// takes in an input and prints all the prime numbers less than and equal to the input.
//  the TIME COMPLEXITY of sieve of eratosthenes is O(nlog(log(n))).
#include <bits/stdc++.h>

using namespace std;

int main (void)
{
	cout<<"number: ";
	int num;
	cin>>num;
	vector<int> arr(num+1,1);
	arr[0]=arr[1]=0;
	int n=arr.size();

	//sieve of eratosthenes.
	for(int i=2; i<sqrt(n); i++) //loops through the entire array.
		/* since all the multiples of n can be found by looping till root(n) and root of all the other elements is less that root(n) we can reduce our loop till root(n)*/
	{
		if(arr[i]) // if the value @ the index is not 0
		{
			for(int j=2; j*i<n; j++) // make all the multiples of i as 0 since they will not be prime.
			{
				arr[i*j]=0;

			}

		}

	}

	// prints the prime indices.
	for(int i=0; i<n; i++)
	{
		if(arr[i])
			cout<<i<<endl;
	}
	//-----------------
	return 0;
}
