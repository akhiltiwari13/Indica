// author- akhil.
// the program calculate the maximum sum of all the subarrays of a given array.
// the algorithm is called KADANE'S algorithm
 
#include<iostream>
using namespace std;

int main()
{
	// given array.
	int arr[]= {-1, 2, 4, -3, 5, 2, -5, 2};
	int best=0, sum=0, n=8;

	for(int i=0; i<n; i++)
	{
		sum=max(arr[i], sum+arr[i]); // this statement calculates the maximum sum of subarrays ending at a[i].
		best=max(best, sum); // this stores the maximum sum for all the subarrays so far.

	}
	cout<<" maximum sum of subarray is:"<<best<<endl;
	return 0;
}
