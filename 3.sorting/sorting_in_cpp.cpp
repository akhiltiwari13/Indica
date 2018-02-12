/*author-akhil
  counting sort*/
#include<iostream>
#include<tuple>
#include<vector>
#include<algorithm>

#define REP(a,b) for(int i=(a); i<(b); i++) // to save me the trouble of writing loops.
using namespace std;

int main()
{
	vector<int> v= {21, 23,13,4,7,54,6,9,23};
	cout<<"initial vector:"<<endl;
	for(auto var: v)	
	{
		cout<<var<<" ";
	}
	cout<<endl;

	sort(begin(v), end(v));

	cout<<"sorted vector: "<<endl;
	for(auto var: v)	
	{
		cout<<var<<" ";
	}
	cout<<endl;

	sort(v.rbegin(), v.rend()); // could not find a non member function corressponding to rbegin() and rend().

	cout<<"reverse sorted vector: "<<endl;
	for(auto var: v)	
	{
		cout<<var<<" ";
	}
	cout<<endl;

	int arr[]={4,3,2,1,7,65,0};

	sort(arr, arr+sizeof(arr)/sizeof(arr[0]));

	cout<<"sorted simple array: "<<endl;
	for(auto var: arr)	
	{
		cout<<var<<" ";
	}
	cout<<endl;

	  
	sort(arr, arr+sizeof(arr)/sizeof(arr[0]), greater<int>()); // for reverse sorting an integer array

	cout<<"reverse sorted simple array: "<<endl;
	for(auto var: arr)	
	{
		cout<<var<<" ";
	}
	cout<<endl;

	string s= "monkey";
	sort(s.rbegin(), s.rend());

	cout<<"reverse sorted string: "<<endl;
	for(auto var: s)	
	{
		cout<<var<<" ";
	}
	cout<<endl;


	pair<int, int> pr1(3,2);
	pair<int, int> pr2(2,2);
	pair<int, int> pr3(3,1);
	vector<pair<int, int>> vpr;
	vpr.push_back(pr1);
	vpr.push_back(pr2);
	vpr.push_back(pr3);

	cout<<"vector of pairs"<<endl;
	for(auto var: vpr)	
	{
		cout<<var.first<<" ";
		cout<<var.second<<" ";
		cout<<endl;
	}
	cout<<endl;

	sort(begin(vpr), end(vpr));

	cout<<"sorted vector of pairs"<<endl;
	for(auto var: vpr)	
	{
		cout<<var.first<<" ";
		cout<<var.second<<" ";
		cout<<endl;
	}

	// similarly for vector of tupples.
	tuple<int, int, int> t1(13,06,16);
	tuple<int, int, int> t2= {13,05, 16};
	tuple<int, int, int> t3= make_tuple(13,05, 17);
	vector<tuple<int, int, int>> vtp;
	vtp.push_back(t1);
	vtp.push_back(t2);
	vtp.push_back(t3);
	
	cout<<"vector of tuples"<<endl;
	for(auto var: vtp)	
	{
		cout<<get<0>(var)<<" ";
		cout<<get<1>(var)<<" ";
		cout<<get<2>(var)<<" ";
		cout<<endl;
	}
	cout<<endl;

	sort(begin(vtp), end(vtp));

	cout<<"sorted vector of tuples"<<endl;
	for(auto var: vtp)	
	{
		cout<<get<0>(var)<<" ";
		cout<<get<1>(var)<<" ";
		cout<<get<2>(var)<<" ";
		cout<<endl;
	}
	cout<<endl;
}

