#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1000000

using namespace std;

// given set of coins.
vector<int> coins= {1, 2, 5, 10, 20, 50, 100, 200}; //these are euro coins, i.e greedy approach would have worked with this set as well.

void full_on_bottom_up_dynamic_programming(int sum, vector<int> &look_up, vector<int> &first_coin, vector<int> &num_of_solution)
{
	// first populating the look_up table using the iterative (bottom up approach).
	look_up[0]=0;
	num_of_solution[0]=1;
	for(int i=1; i<=sum; i++)
	{
		look_up[i]=INF;
		for(auto c: coins)
		{
			if(i-c>=0)
			{
				look_up[i]=min(look_up[i], look_up[i-c]+1);
				if(look_up[i]>look_up[i-c])
				{
					first_coin[i]=c; // gets the first coin.
				}
				num_of_solution[i]=num_of_solution[i]+num_of_solution[i-c]; // gets the number of solutions.
			}
		}
	}

}

int main(void)
{
	int sum;
	cout<<"sum:";
	cin>>sum;

	// length of look up table, first coin table and the number of solutions table will be same i.e sum +1.
	vector<int> look_up(sum+1, INF); // initializing the look up table with maximum possible values.
	vector<int> first_coin(sum+1, 0);
	vector<int> num_of_solution(sum +1, 0);

	full_on_bottom_up_dynamic_programming(sum, look_up, first_coin, num_of_solution);
	cout<<"--------------"<<endl;
	cout<<"results"<<endl;
	cout<<"--------------"<<endl;
	cout<<"optimum solution: "<<look_up[sum]<<endl;
	cout<<"solution :"<<endl;
	int tmp=sum;
	while(first_coin[tmp])
	{
		cout<<first_coin[tmp]<<endl;
		tmp=tmp- first_coin[tmp];
	}
	cout<<"number of solutions: "<<num_of_solution[sum]<<endl;

	return 0;
}
