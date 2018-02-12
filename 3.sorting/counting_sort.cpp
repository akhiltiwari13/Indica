//author-akhil
//counting sort: sorts an array in O(n) as it not a comparison based sort.
//useful when the data to be stored is comparable to the range of the data getting stored.
#include<iostream>
#include<cstring> // has the declaration of the memset function.
#define RANGE 9 // indicates that the range of all the elements to be sorted 
#define REP(a,b) for(int i=a; i<b; i++) // to save me the trouble of writing loops.
using namespace std;



int main()
{
	int arr[]={1,4,1,2,7,5,2};
	int size=6;
	int result[7];
	// initializing the book_keeping array to o initially.
	int book_keeping[RANGE+1];
	//memset(book_keeping, 0, RANGE+1);
	//initializing book_keeping array with all 0s
	REP(0,RANGE+1)
	{
		book_keeping[i]=0;
	}
	cout<<endl;

	cout<<"original array:"<<endl;
	REP(0,size+1)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	for(int i=0; i<=size; i++)
	{
		book_keeping[arr[i]]++; // increments the book_keeping elements to note the times and index occurs in arr.
	}

	cout<<"initial book_keeping array:"<<endl;
	REP(0,RANGE+1)
	{
		cout<<book_keeping[i]<<" ";
	}
	cout<<endl;

	// modify the book_keeping array to find the positon of and element in the result array.
	for(int i=0; i<RANGE; i++)
	{
		book_keeping[i+1]+=book_keeping[i];
	}

	cout<<"modified book_keeping array:"<<endl;
	REP(0,RANGE+1)
	{
		cout<<book_keeping[i]<<" ";
	}
	cout<<endl;

	// traverse throug the original array and populate the result array.
	for(int i=0; i<=size; i++)
	{
		result[book_keeping[arr[i]]-1]=arr[i];
		book_keeping[arr[i]]--;
	}

	cout<<"sorted array:"<<endl;
	REP(0,size+1)
	{
		cout<<result[i]<<" ";
	}
	cout<<endl;
	return 0;
}
