/******************************************************************************
 * top down dynamic programming approach for finding the longest common subsequence.
 * author- akhil
 *******************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;



int  lcs_len_calc(vector<vector<int>> &lookup, string &str1, string &str2, int j, int i)
{
	if( lookup[i][j]  )
	{
		return lookup[i][j];
	}
	else
	{
		
		if(str1[j] == str2[i])
		{
			lookup[i][j]=(lookup[i-1][j-1]+1); 
		}
		else
		{
			lookup[i][j]=max(lcs_len_calc(lookup, str1, str2, j-1, i), lcs_len_calc(lookup, str1, str2, j, i-1)); 
		}
		return lookup[i][j];
	}
}

int main()
{
	int len1, len2;
	string str1;
	string str2;



	cout<<"string1: "<<endl;
	cin>>str1;

	cout<<"string2: "<<endl;
	cin>>str2;

	len1 =  str1.length();
	len2 =  str2.length();

	vector<vector<int>> lookup(len2, vector<int>(len1, 0));

	cout<<"max length: "<<lcs_len_calc(lookup, str1, str2,  len1-1, len2-1);
}

