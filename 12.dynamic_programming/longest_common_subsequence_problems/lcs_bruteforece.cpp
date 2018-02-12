/******************************************************************************
 * bruteforce implementation of longest common subsequence problem.
 * author- akhil
 *******************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

unsigned int max_subsequence_length= 0;

// works in O(n)
bool is_subseq(vector<int> subsequence, vector<int> sequence)
{
	if(subsequence.empty())
	{
		return true;
	}
	if(sequence.empty())
	{
		return false;
	}
	else
	{
		if(sequence.front()==subsequence.front())
		{
			subsequence.erase(subsequence.begin());
			sequence.erase(sequence.begin());
			return is_subseq(subsequence, sequence); 
		}
		else{
			sequence.erase(sequence.begin());
			return is_subseq(subsequence, sequence); 
		}
	}
	return false;
}

// complete search, works in O(2^n)
void gen_subset(vector<int> &sequence,vector<int> &sequence2, vector<int> &subset, unsigned int i)
{
	if(i== sequence.size())
	{
		// this means that a subset is complete
		if(is_subseq(subset, sequence2))
		{
			if(subset.size()> max_subsequence_length)
			{
				max_subsequence_length=subset.size();
			}
		}
	}
	else
	{
		subset.push_back(sequence[i]);
		gen_subset(sequence,sequence2, subset, i+1);
		subset.pop_back();
		gen_subset(sequence,sequence2, subset, i+1);
	}

}

int main()
{
	int len1, len2, num;
	vector<int> str1;
	vector<int> str2;
	vector<int> subset;

	cout<<"string1 length"<<endl;
	cin>>len1;

	cout<<"string2 length"<<endl;
	cin>>len2;

	cout<<"enter string1: "<<endl;
	for(int i=0; i<len1; i++)
	{
		cin>>num;
		str1.push_back(num);
	}

	cout<<"enter string2: "<<endl;
	for(int i=0; i<len2; i++)
	{
		cin>>num;
		str2.push_back(num);
	}


	gen_subset(str1, str2,  subset ,0);
	cout<<"length of maximum common subsequence is: "<<max_subsequence_length<<endl;

}
