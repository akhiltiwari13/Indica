#include <bits/stdc++.h>
using namespace std;

vector<int> memoization_arr(51, -1);

int fib_using_rec_and_mem(int num)
{
	if(num<=1)
		return num;

	if(memoization_arr[num]!=-1)
	{
		return memoization_arr[num];
	}
	else
	{
		memoization_arr[num]= (fib_using_rec_and_mem(num-1)+ fib_using_rec_and_mem(num-2));
		return memoization_arr[num];
	}

}

void print_v(vector<int>& v_int)
{
	for(auto itr: v_int)
	{
		cout<<itr<<endl;
	}
	cout<<endl;
}

int main(void)
{


	cout<<"enter the number: ";
	int num;
	cin>>num;
	cout<<"recursive fibonacci with memoization result: "<<fib_using_rec_and_mem(num)<<endl;
	cout<<"memoization vector: "<<endl;
	print_v(memoization_arr);
	return 0;
}
