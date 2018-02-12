/******************************************************************************
 * bottom up dynamic programming approach for finding the nth fibonacci series number with constant space complexity.
 * author- akhil
 *******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

// bottom-up approach can beat topdown approach in performance as it does not involve function calls which have overhead :-)
int get_fibonacci_num_bu_constspace(int num)
{
	if(num<=0)
		return 0;
	int prev, curr;
	prev=curr=1;
	for(int i=2; i<num ; i++)
	{
		curr = prev+curr;
		prev = curr-prev;	
	}
	return curr;
}
int main()
{
	int num;
	cout<<"number: "<<endl;
	cin>>num;
	cout<<num<<"th term: "<<get_fibonacci_num_bu_constspace(num)<<endl;
	return 0;
}

