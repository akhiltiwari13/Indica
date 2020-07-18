#include<bits/stdc++.h>

using namespace std;

// definiton of the merge function.
void merge(int *arr, int begin, int mid, int end)
{
	int i, j, k;
	int arr1_size=mid-begin+1;
	int arr2_size=end-mid;
	int arr1[arr1_size];
	int arr2[arr2_size];
	// copying the elements from the main array to the 2 local arrays.
	for( j=0; j<arr1_size; j++)
		arr1[j]=arr[begin+j];

	for( k=0; k<arr2_size; k++)
		arr2[k]=arr[k+mid+1];

	// merging the 2 local array to the main subarray.
	for(i=begin, j=0, k=0; j<arr1_size && k<arr2_size ; )
	{
		if(arr1[j]<=arr2[k]) // the equality operator is very important.
		{
			arr[i]=arr1[j];
			j++;
		}
		else
		{
			arr[i]=arr2[k];
			k++;
		}
		i++;

	}
	// insert all the elements if either of the auxilary array has been completely copied.
	if(j==arr1_size)
	{
		while(k<arr2_size)
			arr[i++]=arr2[k++];
	}
	else
		if(k==arr2_size)
		{
			while(j<arr1_size)
			{
				arr[i++]=arr1[j++];

			}

		}




}



// definition of the merge_sort function.
void merge_sort(int *arr, int begin, int end)
{
	if(begin<end)
	{
		int mid= (begin+end)/2;
		merge_sort(arr, begin, mid);
		merge_sort(arr, mid+1, end);
		merge(arr, begin, mid, end);

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

	// sorting the array using merge sort.
	merge_sort(arr, 0,  size-1);

	// ranged for loop to show the sorted array.
	cout<<"sorted array: "<<endl;
	for(int i=0; i<size; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}
