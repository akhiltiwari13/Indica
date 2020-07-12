#include<iostream>
#include<string>
#include<vector>

using namespace std;

// function for creating the lookup table for the lenghts of longest common subsequence.
void fun(vector<vector<int>>& lookup, string str_a, string str_b)
{
	int len_a=  str_a.size();
	int len_b=  str_b.size();

	for(int i=1; i<=len_a; i++)
	{
		for(int j=1; j<=len_b; j++)
		{
			if(str_a[i-1]==str_b[j-1])
			{
				lookup[i][j]=lookup[i-1][j-1]+1;
			}
			else{
				lookup[i][j]=max(lookup[i-1][j], lookup[i][j-1]);
			}
		}
	}
}

// function for printing the string.
void print_subsequence(vector<vector<int>> lookup, string str_a, int len_a, int len_b, vector<char> &subsequence)
{
	if(len_a>0 && len_b>0)
	{
		if(lookup[len_a][len_b]- lookup[len_a-1][len_b-1])
		{
			subsequence.insert(subsequence.begin(), str_a[len_a-1]);
			return print_subsequence(lookup, str_a, len_a-1, len_b-1, subsequence);
		}
		else if(lookup[len_a-1][len_b]> lookup[len_a][len_b-1]){
			return print_subsequence(lookup,str_a, len_a-1, len_b, subsequence);
		}
		else{
			return print_subsequence(lookup, str_a, len_a, len_b-1, subsequence);
		}
	}
}

//main
int main(void)
{
	string str_a, str_b;

	cin>>str_a>>str_b;
	int len_a= str_a.size(), len_b= str_b.size();

	vector<vector<int>> lookup(len_a+1, vector<int>(len_b+1,0));

	fun(lookup, str_a, str_b);

	cout<<"-------------"<<endl;
	cout<<"lookup table"<<endl;
	cout<<"-------------"<<endl;
	for(auto itr: lookup)
	{
		for(auto iitr: itr)
		{
			cout<<iitr;
		}
		cout<<endl;
	}
	cout<<endl;

	cout<<"-----------------------------------------------"<<endl;
	cout<<"getting the longest subsequence from the lookup"<<endl;
	cout<<"-----------------------------------------------"<<endl;
	vector<char> subs;
	print_subsequence(lookup, str_a, len_a, len_b, subs);
	for(auto itr: subs)
	{
		cout<<itr;
	}
	cout<<endl;
	return 0; 
}
