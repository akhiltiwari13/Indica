#include <iostream>
#include <vector>
#include <algorithm>
#define  INF 100000


using namespace std;

const int coins[]= {1, 5, 10, 50, 100};

void create_look_up(int sum, vector<int> &look_up)
{
	// the look up table/array will contain "sum + 1" elements.
	look_up[0]=0;
	for(int i=1; i<=sum; i++)
	{
		look_up[i]=INF;
		for(auto itr: coins)
		{
			if(i-itr>=0)
			{
				look_up[i]= min(look_up[i], look_up[i-itr]+1);
			}
		}

	}
}

int main(void)
{
	int sum=0;
	cout<<"enter the sum"<<endl;
	cin>>sum;
	vector<int> look_up(sum, 0);
	// create the look up table
	create_look_up(sum,look_up);

	// print all the values in the look up table
	for(auto itr: look_up)
	{
		cout<<itr<<endl;
	}


	return 0;
}
