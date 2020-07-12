#include <bits/stdc++.h>
#define REP(a,b) for(int i=a; i<b; i++)

using namespace std;

int get_number_with_odd_frequency_hashmapped(vector<int> numbers)
{
	int size= numbers.size();
	// using an unordered map to record the frequency of occurance of each of the elements.
	unordered_map<int, int> cnt;

	// parsing the vector and storing the data in the unordered map.
	REP(0, size)
	{
		cnt[numbers[i]]++;
	}

	REP(0, size)
	{
		if(cnt[numbers[i]]%2)
		{
			return numbers[i];
		}
	}
	return 0;

}

int get_number_with_odd_frequency_xored(vector<int> numbers)
{
	int size= numbers.size();
	int result=0;
	REP(0,size)
	{
		numbers[i]=numbers[i]^result;
		result=numbers[i];

	}
	return result;
}

int main(void)
{
	int num, size;
	vector<int> numbers;


	cout<<"enter the number of elements of the array"<<endl;
	cin>>size;
	cout<<"enter the elements"<<endl;
	REP(0,size)
	{
		cin>>num;
		numbers.push_back( num );
	}

	int result= get_number_with_odd_frequency_hashmapped(numbers);
	cout<<"-------------Result using Hash Map--------------"<<endl;
	if(result)
	{
		cout<<"the number which occurs odd number of times is: "<<result<<endl;
	}
	else{
		cout<<"no such element found."<<endl;
	}

	result= get_number_with_odd_frequency_xored(numbers);
	cout<<"--------------Result using XOR--------------"<<endl;
	if(result)
	{
		cout<<"the number which occurs odd number of times is: "<<result<<endl;
	}
	else{
		cout<<"no such element found."<<endl;
	}

	return 0;
}
