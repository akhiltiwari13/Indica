#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	int len, num_ops;
	cin >> len;
	vector<int> arr(len, 1); // array of all 1's
	cin >>num_ops;
	vector<vector<int>> ops(num_ops, vector<int>(2,0) );

	int a, b;

	/*for(auto itr: ops)
	  {
	  for(auto iitr: itr)
	  {
	  cout<<iitr<<" ";
	  }
	  cout<<endl;

	  }*/

	for(int i=0; i<num_ops; i++)
	{
		cin>>a;
		cin>>b;
		if(a==0)
		{
			arr[b-1]=0; // convert the value to 1;
		}
		else
		{
			if(a==1)
			{
				int cnt= b;
				int x=arr.size();
				for(int t=0; t<x; t++)
				{
					if(arr[t])
					{
						cnt--;

					}

					if(!cnt)
					{
						cout<<t+1;
						cout<<endl;
						break;
					}
				}
				if(cnt)
				{
					cout<<-1;
					cout<<endl;
				}
			}

		}

	}
	/*for(auto itr: ops)
	  {
	  for(auto iitr: itr)
	  {
	  cout<<iitr<<" ";
	  }
	  cout<<endl;

	  }*/
} 
