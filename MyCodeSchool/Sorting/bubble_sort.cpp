#include<iostream>
using namespace std;

void bubble_sort(int *arr, int last)
{
	for(int i=0; i<last; i++)
	{
		int flag=0; // this flag can be used to increase the efficiency of this algorithm.
		for(int j=0; j<=(last-1)-i; j++)
		{
			// for every iteration of this loop, the maximum element of the subarray is moved to the last possible index.
			if(arr[j]>arr[j+1])
			{

				swap(arr[j], arr[j+1]);
				flag++;
			}

		}
		if(!flag)
		{
			// this indicates that no swapping has taken place and so we can break out of the loop.
			break;
		}
	}
}

int main()
{
	int size;
	cout<<"number of elements"<<endl;
	cin>>size;
	int arr[size];

	cout<<"enter elements"<<endl;
	for(int i=0; i<size; i++)
	{
		cin>>arr[i];
	}

	cout<<"unsorted array:"<<endl;
	// ranged for loop to show the original array.
	for(auto i:arr)
	{
		cout<<i<<" ";
	}
	cout<<endl;

	// sorting the array using selection sort.
	bubble_sort(arr, size-1);

	// ranged for loop to show the sorted array.
	cout<<"sorted array: "<<endl;
	for(auto i:arr)
	{
		cout<<i<<" ";
	}
	cout<<endl;
	return 0;
}
