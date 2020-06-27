#include <bits/stdc++.h>
#define REP(a,b) for(int i=a; i<b; i++)

using namespace std;

int main(void)
{
	const char *arr= "abcdefg";
	int size= 7;
	int power_set_size= pow(2,size);
	cout<<"given array: "<<endl;
	cout<<arr<<endl;

	cout<<"subsets: "<<endl;
	REP(0,power_set_size)
	{
		for(int j=0; j<size; j++)
		{
			if(i&1<<j)
			{
				printf("%c", arr[j]);

			}
		}
		printf("\n");

	}


	return 0;
}
