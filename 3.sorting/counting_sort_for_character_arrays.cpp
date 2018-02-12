//author-akhil
//counting sort
#include<iostream>
#include<cstring> // has the declaration of the memset function.
#define RANGE 255 // indicates that the range of all the elements to be sorted 
/* The ranges has been selected so, because the input is an array of characters and the ASCII range of characters is from 0-254. Hence, the range of our book_keeping array*/
#define REP(a,b) for(int i=a; i<b; i++) // to save me the trouble of writing loops.
using namespace std;

void counting_sort(char *arr)
{
	int size=strlen(arr);

	char result[size+1];
	result[size]='\0';

	int book_keeping[RANGE+1];
	memset(book_keeping, 0, sizeof(book_keeping));

	REP(0,size)
	{
		book_keeping[arr[i]]++;
	}

	REP(0,RANGE-1)
	{
		book_keeping[i+1]+=book_keeping[i];
	}
	  
	REP(0,size)
	{
	result[book_keeping[arr[i]]-1]=arr[i];
	book_keeping[arr[i]]--;
	}

	// copying the result to arr again.
	REP(0,size+1)
	{
		arr[i]=result[i];
	}

}

int main()
{
	char arr[]="akhil";
	counting_sort(arr);
	cout<<"sorted array:"<<endl;
	REP(0,5)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}


