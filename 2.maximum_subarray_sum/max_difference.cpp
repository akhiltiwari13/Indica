#include <iostream>
#include <vector>

using namespace std;

void printv(vector<int>& v)
{
	for(auto itr:v)
	{
		cout<<itr<<endl;
	}
}

int max_diff(vector<int>& v_int)
{
	int diff=0, highest_diff=0, smallest_element=v_int[0];

	for(auto& itr: v_int)
	{

		diff= itr-smallest_element;
		highest_diff=max(highest_diff, diff);
		smallest_element=min(smallest_element,itr);

	}
	return highest_diff;
}

int main(void)
{
	vector<int> v_int={-1,3,-4,-1};
	printv(v_int);

	auto result=max_diff(v_int);
	cout<<"result: "<<result<<endl;

	return 0;
}
