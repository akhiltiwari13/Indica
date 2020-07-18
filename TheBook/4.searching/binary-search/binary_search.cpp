#include<iostream>

using namespace std;

int binary_search_recursive(int search_term, int *arr, int begin, int end)
{
	if(begin<end)
	{
		int mid=(begin+end)/2;
		if(arr[mid]==search_term)
		{
			return mid;
		}
		else if(arr[mid]<search_term)
		{
			return binary_search_recursive(search_term, arr, begin, mid-1);
		}
		else if(arr[mid]>search_term)
		{
			return binary_search_recursive(search_term, arr, mid+1, end);
		}

	}
	return -1;

};

int binary_search_iterative(int search_term, int *arr, int begin, int end)
{
	int mid;
	while (begin<end)
	{
		mid=(begin+end)/2;
		if(arr[mid]==search_term)
		{
			return mid;
		}
		else if(arr[mid]<search_term)
		{
			begin=mid+1;
		}
		else if(arr[mid]>search_term)
		{
			end= mid-1;
		}

	}
	return -1;
}

int main(void)
{
	int arr[]= {1, 3, 5, 6, 7, 9, 14, 25, 33, 44, 55, 67, 78, 89, 99};
	int size= sizeof(arr)/sizeof(arr[0]);
	int search_term=25;
	int recursive_searched_index= binary_search_recursive(search_term, arr, 0, size-1);
	int iterative_searched_index= binary_search_iterative(search_term, arr, 0, size-1);
	cout<<"recursive_searched_index: "<<recursive_searched_index<<endl;
	cout<<"recursive_searched_index: "<<iterative_searched_index<<endl;
	return 0;
}

