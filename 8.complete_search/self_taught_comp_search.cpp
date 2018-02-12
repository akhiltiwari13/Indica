// author: akhil
// prints all the subsets of a given set.
/* ALGORITHM: goto each of the element of the array and the approach is that you will either accept the element is the subset or reject it, so each element would have a binary fate!!!!*/

#include <iostream>
#include <vector>

using namespace std;


void generate(int index, const char *arr, int arr_size,  vector<char> buffer)
{
	if(index<arr_size)
	{
		buffer.push_back(arr[index]);
		generate(index+1, arr,  arr_size, buffer);
		buffer.pop_back();
		generate(index+1, arr,  arr_size, buffer);
	}
	else{
		for(auto itr: buffer  )
		{
			cout<<itr;
		}
		cout<<endl;

	}
}

int main(void)
{
	vector<char> buffer;
	const	char *arr= "akhil";
	generate(0, arr, 5,  buffer);
	return 0;
}
