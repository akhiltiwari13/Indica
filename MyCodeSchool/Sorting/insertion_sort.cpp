#include<iostream>

using namespace std;

void insertion_sort(int *arr, int last)
{
	int j=0;
	for(int i=0; i<=last; i++)
	{
		int key=arr[i];
		for( j=i-1; j>= 0 && arr[j]> key; j--)
		{
			arr[j+1]=arr[j];
		}
		arr[j+1]=key;
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

	// sorting the array using insertion sort.
	insertion_sort(arr, size-1);

	// ranged for loop to show the sorted array.
	cout<<"sorted array: "<<endl;
	for(auto i:arr)
	{
		cout<<i<<" ";
	}
	cout<<endl;
	return 0;
}
