#include<stdio.h>

int sum_arr_elements(int arr[], int size)
{
	int i=0;
	int sum=0;
	for(i=0; i<size; i++)
	{
		sum += arr[i];
	}
	return sum;
}

int main()
{
	int arr[]= {13,5, 11, 30, 26};
	int size = sizeof(arr)/sizeof(arr[0]);

	// calculate and print the sum of all elements of the array.
	printf("sum=%d\n", sum_arr_elements(arr,size));

	return 0;
}
