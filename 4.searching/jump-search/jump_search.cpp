#include<bits/stdc++.h>

using namespace std;

int jump_search(int *arr, int size, int element)
{
	int start=0;
	int prev=start;
	int jump;
	for(jump=(size-1)/2; jump>=1; jump/=2) // initializing the first jump to half of the array and decrement it to half it's size.
	{
		prev=start;
		while(start+ jump<= size-1 && arr[jump+start]<=element)
			start+=jump;

	}
	if(arr[start]== element)
		return start;
	// if the element is not yet found, search for it linearly.
	for(int i=start; i>=prev; i--)
	{
		if(arr[i]== element)
			return i;
	}
	return -1;
}

int main(void)
{
	int arr[]= {3,7,21,36,44,51,59,67, 70, 71};
	cout<<"array: "<<endl;
	for_each(begin(arr), end(arr), [](int ele)->void{
			cout<<ele<<" ";
			});
	cout<<endl;
	int search_ele=71;
	int search_index=jump_search(arr, end(arr)-begin(arr), search_ele);
	cout<<"search_index:  "<<search_index<<endl;
	return 0;
}
