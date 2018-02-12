/******************************************************************************
 * bottom up dynamic programming approach for finding the nth fibonacci series number.
 * author- akhil
 *******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

// bottom-up approach can beat topdown approach in performance as it does not involve function calls which have overhead :-)
int get_fibonacci_num_bu(vector<int> &lookup, int num)
{
	if(num<=0)
		return 0;
	lookup[0]=lookup[1]=1;
	for(int i=2; i<num ; i++)
	{
		lookup[i]=lookup[i-1]+lookup[i-2];
	}
	return lookup[num-1];
}
int main()
{
	int num;
	cout<<"number: "<<endl;
	cin>>num;
	vector<int> lookup(num,0);
	cout<<num<<"th term: "<<get_fibonacci_num_bu(lookup, num)<<endl;
	return 0;
}

