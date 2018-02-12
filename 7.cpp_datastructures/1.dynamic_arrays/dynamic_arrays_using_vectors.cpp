// vector is one of the dynamic array implementations in c++ standard library.
// vector is implemented using simple arrays; however as the number of elements in the vector increase....
// a larger space is allocated in the memory and the current data is moved to the new location.
// the average time complexity of the push_back() operation however is O(1).
#include <iostream>
#include <vector>

using namespace std;

void printv(vector<int>& v)
{
	for(auto itr:v)
	{
		cout<<itr<<endl;
	}
}

int main ()
{
	vector<int> v(10,13);
	cout<<"initial vector: "<<endl;
	cout<<"size: "<<v.size()<<endl;
	printv(v);
	v.pop_back();
	cout<<"-----------"<<endl;
	cout<<"after a pop_back operation"<<endl;
	cout<<"-----------"<<endl;
	printv(v);
	cout<<"size: "<<v.size()<<endl;
	v.push_back(5);
	cout<<"-----------"<<endl;
	cout<<"after a push_back(5) operation"<<endl;
	cout<<"-----------"<<endl;
	printv(v);
	cout<<"back() operation: "<<v.back()<<endl;
	return 0;
}
