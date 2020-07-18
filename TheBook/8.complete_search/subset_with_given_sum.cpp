/******************************************************************************
 * author: akhil
 * program to find the subsets of a set that which equals a specified sum.
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

const int sum= 15;
const vector<int> given= {2, 4, 5, 8, 10, 9};
int size= given.size();
vector<int> subset;

void find_subsets(int index)
{
	if(index<=size)
	{
		int s= accumulate(begin(subset), end(subset) , 0);
		if(s==sum)
		{
			// print all the element in the subset vector.
			for(auto itr: subset)
			{
				cout<<itr<<" ";
			}
			cout<<endl;
		}
		else
		{

			subset.push_back(given[index]);
			find_subsets(index+1);
			subset.pop_back();
			find_subsets(index+1);
		}
	}
}

int main()
{
	find_subsets(0);
	return 0;
}
