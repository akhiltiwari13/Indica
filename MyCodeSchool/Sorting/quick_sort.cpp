#include<bits/stdc++.h>
using namespace std;

// c++ has a built in swap function which could be used here instead.
// definition of the swap function.
// apparently this swap function was not working properly
void swap(int *a, int *b)
  {
 //*a = *a + *b; 
 //*b = *a - *b; 
 //*a = *a - *b; 
 
	  int temp= *a;
	  *a= *b;
	  *b=temp;
 }

// definition of the partition function.
int partition(int *arr, int start, int end)
{
	int pivot_index=start;
	for(int i=start; i<end; i++)
	{
		if(arr[i]<arr[end])
		{
			swap(arr[i], arr[pivot_index]);
			pivot_index++;
		}

	}
	swap(&arr[end], &arr[pivot_index]);
	return pivot_index;
}

// definition of the quick sort function.
void quick_sort(int *arr, int start, int end) // passing the reference of the vector.
{
	if(start<end)
	{
		int pivot_index=partition(arr, start, end);
		quick_sort(arr, start, pivot_index-1);
		quick_sort(arr, pivot_index+1, end);

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

	// sorting the vector using quick sort.
	quick_sort(arr, 0, size-1);

	// ranged for loop to show the sorted array.
	cout<<"sorted array: "<<endl;
	for(auto i:arr)
	{
		cout<<i<<" ";
	}
	cout<<endl;

	return 0;
}
