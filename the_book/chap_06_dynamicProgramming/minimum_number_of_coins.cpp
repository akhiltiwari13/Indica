#include <iostream>
#include <vector>

#define INF 1000000; // defining INFINITY to be a very large value which can avoid any type of overflow.

using namespace std;

vector<int> coins= {1, 3, 4};
int sum= 6;

// important to note that the size of the vector will be sum + 1 and not sum as 0 needs to be included as well.
vector<int> look_up(sum+1, 0); 
vector<bool> looked_up(sum+1, false);

int get_coin_count(int sum)
{
	if(sum==0)
	{
		look_up[0]= 0;
		looked_up[0]=true; // this is an overhead which needs to be removed..
		return 0;
	}
	else if(sum<0)
	{
		return INF;
	}
	else if(looked_up[sum])
	{
		return look_up[sum];
	}
	else
	{
		int best= INF;
		for(auto itr: coins)
		{
			best= min(best, get_coin_count(sum-itr)+1);
		}
		look_up[sum]=best;
		looked_up[sum]= true;
		return best;
	}
}

int main(void)
{

	cout<<"calculating minimum number of coins required using dynamic programming.\n";
	cout<<get_coin_count(6)<<endl;
	return 0;
}
