#include<bits/stdc++.h>
using namespace std;

void selection_sort(int *arr, int last)
{
	int min_index;
	for(int i= 0; i<last; i++)
	{
		min_index=i;
		for(int j=i+1; j<=last; j++)
		{
			if(arr[j]<arr[min_index]) 
				min_index=j;
		}
		swap(arr[i], arr[min_index]); // swapping the smaller element to bring it to the lowest index of the external loop.
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
	selection_sort(arr, size-1);

	// ranged for loop to show the sorted array.
	cout<<"sorted array: "<<endl;
	for(auto i:arr)
	{
		cout<<i<<" ";
	}
	cout<<endl;
	return 0;
}
