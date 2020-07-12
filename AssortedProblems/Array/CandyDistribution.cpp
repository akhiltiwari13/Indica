#include <bits/stdc++.h>
#define REP(a,n) for(int i=a; i<n; i++)
using namespace std;


// net bonus calculator.
long calc_net_bonus(vector <int> &emp_rating) //using the return type as test #12 was failing due to integer overflow.
{
	auto size= emp_rating.size();
	vector<int> emp_bonus(size, 1); //initialize all the elements to 1 (minimum possible bonus)
	long result=0; // to hold the accumulated sum.

	// comparing the bonus value wrt previous element.
	for(unsigned int i=1; i<size; i++)
	{
		if(emp_rating[i]>emp_rating[i-1])
			emp_bonus[i]=emp_bonus[i-1]+1;
	}

	// comparing the bonus value wrt succeeding element.
	for(int j= size-2; j>=0; --j)
	{
		if(emp_rating[j]>emp_rating[j+1])
			emp_bonus[j]=max(emp_bonus[j], (emp_bonus[j+1]+1));
	}

	return accumulate(begin(emp_bonus), end(emp_bonus), result);

}

// main program.
int main()
{
	int  arr_size, ele; 
	vector<int> emp_rating;

	cin>>arr_size; // taking the length of the array as input.
	REP(0,arr_size)
	{
		cin>>ele;
		emp_rating.push_back(ele);

	}
	cout<<calc_net_bonus(emp_rating)<<endl;
	return 0;
}
