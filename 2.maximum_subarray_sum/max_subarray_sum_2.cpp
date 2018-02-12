// author: akhil
// finds the subarray with the maximum sum using 2 nested loops.
#include<iostream>
using namespace std;

int main()
{
	int arr[]={-1,2,4,-3,5,2,-5,2};
	int best=0, sum=0, n=8;

	// finding the maximum sum of the subarray.
	// by calculating the sum of each subarray as we move the right end for the subarrays.
	
	// this loop goes to each starting element of all the subarrays.
        for(int i=0; i<n; i++)
	{
		sum=0; // reset the sum to 0.
		for(int j=i; j<n; j++)
		{
			// this moves the right end of the subarray.
			sum+=arr[j];
			best=max(sum, best); // stores the maximum so found so far.
		}
	}


	cout<<"the maximum sum is:"<<best<<endl;

	return 0;
}
