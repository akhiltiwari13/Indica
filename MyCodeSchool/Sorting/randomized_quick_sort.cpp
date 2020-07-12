// author-akhil
// implementation of randomized quick sort.
// the random function does not work as expected.... program encounters a core dump.
#include<iostream>
#include<random>
#include<algorithm> // this holds the declaration of the swap function.
#include<bits/stdc++.h>

using namespace std;

// to furthur the probability of not facing the worst case scenario for the quick sort.
// we can shuffle the array before we get it to sort.
// this is a modification of FISHER-YATES algorithm that shuffles an array in O(n).
void shuffle_array(int *arr, int begin , int last)
{
	int random=0;
	for(int i=begin; i<last; i++)
	{
		// generate a random number n such that i<=n<=last;
		 random=i+ rand()%(last-i+1);
		 swap(arr[i], arr[random]); // swap the current selected element with the element at the random index.
	}


}

int random_index(int begin, int end)

{
	int index;
	// initializing random seed.
	srand(time(NULL));

	// rand() function gives a random integer between 9 and RAND_MAX(defined in cstdlib)
	index=(begin+rand()%(end - begin +1)); // adding a begin+ is important.
	return index;
}

// definition of the partition function.
int partition(int *arr, int begin, int end)
{
	int pivot_index=random_index(begin, end);
	int partition_position=begin;
	// swapping the random pivot wiht the last element and letting the 
	// this swapping was essential in getting the sort to work.
	swap(arr[end], arr[pivot_index]); 

	for(int i=begin; i<end; i++)
	{
		if(arr[i]<arr[end])
		{
			swap(arr[i], arr[partition_position++]);
		}
	}
	swap(arr[partition_position], arr[end]);
	return partition_position;
}

// definition of the randomized quick sort function.
// definition is identical to quick sort function.
void randomized_quick_sort(int *arr, int begin, int end)
{
	if(begin<end)
	{
		int pivot_index=partition(arr, begin, end);
		randomized_quick_sort(arr, begin, pivot_index-1);
		randomized_quick_sort(arr, pivot_index+1, end);

	}
}

//---------------main-----------------
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

	// printing the shuffled array.
	shuffle_array(arr, 0, size-1);
	cout<<"shuffled array:"<<endl;
	// ranged for loop to show the original array.
	for(auto i:arr)
	{
		cout<<i<<" ";
	}
	cout<<endl;

	// sorting the array using selection sort.
	randomized_quick_sort(arr,0, size-1);

	// ranged for loop to show the sorted array.
	cout<<"sorted array: "<<endl;
	for(auto i:arr)
	{
		cout<<i<<" ";
	}
	cout<<endl;

	return 0;
}
