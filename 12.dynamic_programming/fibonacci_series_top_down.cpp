/******************************************************************************
 * top down dynamic programming approach for finding the nth fibonacci series number.
 * author- akhil
 *******************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int get_fibonacci_num_td(vector<int> &lookup, int num)
{
	if(num<=0)
		return 0;
	if(lookup[num])
	{
		return lookup[num];
	}
	else
	{
		if(num <= 2)
			lookup[num]=1;
		else
		{
			lookup[num]= get_fibonacci_num_td(lookup, num-1)+ get_fibonacci_num_td(lookup, num-2);
		}
		return lookup[num];
	}
}
int main()
{
	int num;
	cout<<"number: "<<endl;
	cin>>num;
	vector<int> lookup(num,0);
	cout<<num<<"th term: "<<get_fibonacci_num_td(lookup, num)<<endl;
	return 0;
}

