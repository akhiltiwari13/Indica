#include <iostream>
#include <string>
#include <vector>

using namespace std;


int fun(vector<vector<int>>& lookup, vector<vector<bool>> &has_result, string str_a , string str_b, unsigned int len_a, unsigned int len_b)
{

	if(len_a==0 || len_b==0)
		return 0;
	if(has_result[len_a-1][len_b-1])
		return lookup[len_a-1][len_b-1];
	else{
		if(str_a[len_a-1]== str_b[len_b-1])
		{
			lookup[len_a-1][len_b-1]= fun(lookup, has_result, str_a, str_b, len_a-1, len_b-1)+1;
			has_result[len_a-1][len_b-1]=true;
			return lookup[len_a-1][len_b-1];
		}
		else{
			lookup[len_a-1][len_b-1]= max(fun(lookup,  has_result, str_a, str_b, len_a, len_b-1),
					fun(lookup, has_result, str_a, str_b, len_a-1, len_b)
					);
			has_result[len_a-1][len_b-1]=true;
			return lookup[len_a-1][len_b-1];
		}
	}
}

int main(int argc, char **argv)
{
	string str_a, str_b;

	cout<<"string 1:";
	cin>>str_a;
	cout<<"string 2:";
	cin>>str_b;

	int len_a=str_a.size();
	int len_b=str_b.size();

	// lookup vector
	vector<vector<int>> lookup(len_a, vector<int>(len_b,0));
	// boolean has result vector -- this vector is not needed, lookup cells with 0 values can be used instead.
	vector<vector<bool>> has_result(len_a, vector<bool>(len_b,false));

	cout<<"longest common subsequence="<<fun(lookup,has_result, str_a, str_b, len_a, len_b)<<endl;

	cout<<"lookup table:"<<endl;
	for(auto itr: lookup)
	{
		for(auto iitr: itr)
		{
			cout<<iitr;
		}
		cout<<endl;
	}

	return 0;
}

