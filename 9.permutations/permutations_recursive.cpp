#include <bits/stdc++.h>

using namespace std;

string given = { 'a', 'b', 'c', 'd', 'e'};

string permutation;
vector < bool > chosen(4, false);

void get_all_permutations ()
{
	if (permutation.size () == 5)
	{
		/*for (auto itr:permutation)
		  {
		  cout << itr;
		  }
		  cout << endl;*/
		cout<<permutation<<endl;
	}
	else
	{
		for (int i = 0; i < 5; i++)
		{
			/*			if (chosen[i])
						{
						continue;
						}
						else
						{
						chosen[i] = true; */
			permutation.push_back (given[i]);
			get_all_permutations ();
//			chosen[i] = false;
			permutation.pop_back ();
			//}
		}
	}

}

int main (void)
{
	get_all_permutations ();
	return 0;

}

