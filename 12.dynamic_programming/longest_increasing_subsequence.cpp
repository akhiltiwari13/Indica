#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr= {6, 2, 5, 1, 7, 4, 8, 3};
const int arr_size=8;
vector<int> look_up_arr(arr_size, 1); // the length of the look up table should is equal to the lenght of the specified array. 

void dynamic_programming()
{
	for(int i= 0; i< arr_size; i++)
	{
		for(int j=0; j<i; j++)
		{
			if(arr[j]<arr[i])
			{
				look_up_arr[i]= max(look_up_arr[i], look_up_arr[j]+1);
			}
		}
	}
}

int main(void)
{
	// the function to generate the look up table
	dynamic_programming();
	for(auto itr: look_up_arr)
	{
		cout<<itr<<endl;
	}
	return 0;
}
