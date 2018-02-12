#include <iostream>
#include <vector>
using namespace std;

vector<int> arr={6,2,5,1,6,7,4,8,3};
//vector<int> arr={1,2,3,4};
int len= arr.size();
vector<int> c(len,0);
vector<bool> b(len,false);

int fun(int n)
{
	if(!n)
	{
		c[n]=1;
		return c[n];
	}
	else
	{
		int m=1;
		for(int i=n-1; i>=0; i--)
		{
			if(arr[i] <= arr[n])
			{
				m= max(m, fun(i)+1);

			}
			/* this else block could be used to not miss the element i where a[i]>=a[n]*/
			else
				fun(i);
		}
				c[n]=m;
		return m;
	}

}

int main(void)
{

	cout<<"lis: "<<fun(len-1)<<endl;
	for(auto itr: c)
	{
		cout<<itr<<" ";
	}
	cout<<endl;
	return 0;
}
