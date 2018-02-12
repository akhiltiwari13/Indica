#include<iostream>
using namespace std;

int main()
{
	int arr[]={-1,2,4,-3,5,2,-5,2};
	int best=0, sum=0, n=8;

	// finding the maximum sum of the subarray.
	// by iterating through all the subarrays of the given array, calculating the sum and storing the maximum result.

	// this loop iterates through all the starting element of every subarray.
	for(int i=0; i<n; i++)
	{
		// this loop iterates through the end element of all the subarrays with the starting element arr[i].
		for(int j=i; j<n; j++)
		{
			// reset the sum to 0 initially.
			sum=0;
			// this loop iterates through all the elements of of the subarray formed by arr[i] and arr[j] and calculates the sum.
			for(int k=i; k<=j; k++)
			{
				// calculates the sum of the subarray.
				sum+=arr[k];
			}
			// decides if the calculated sum is the best sum or not.
			best=max(best, sum);
		}
	}
	cout<<"the maximum sum is:"<<best<<endl;
	
	return 0;
}
