#include<stdio.h>

int *returnlargest(int *begin, int *end)
{
	if(begin==end)
		return 0; // returns a null pointer in case an empty array is passed.

	int *largest=begin;

	for(;begin!=end;++begin)
	{
		if(*largest<*begin)
			largest=begin;
	}
	return largest;
	

}

int main()
{
	int arr[]={13,05, 11, 30, 26};
	int size=sizeof(arr)/sizeof(arr[0]);

	for(int i=0; i<size; i++){
		printf("value arr[i]=%d\t", arr[i]);
		printf("value *(arr +i)=%d\n", *(arr +i));

		// printing the address of each of the elements of the array.
		printf("address &arr[i]=%p\t", &arr[i]);
		printf("address (arr +i)=%p\n", (arr +i));
	}

	// declaring 2 pointers, one will point to the address of the first element of the array and the other will point to...
	// the memory address adjacent to the last element of the array.
	puts("");
	puts("---------*-------");
	puts("");
	
	int *first=arr;
	int *last=(arr+size);
	for(; first!= last; ++first)
	{
		printf("%d\n",*first);


	}
	puts("");
	puts("---------*-------");
	puts("");
	// calls the function to get the largest value of the array.
	int* largest= returnlargest(arr,last);
	if(largest)
		printf("largest=%d\n",*largest);

	return 0;

}
