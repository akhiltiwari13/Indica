#include <bits/stdc++.h>
using namespace std;

void max_heapify(std::vector<int> &vec, int i)
{
	int heap_len= vec.size();
	int largest=i;
	int l= 2*i +1;
	int r= 2*i +1;

	if(l<heap_len && vec[i]<vec[l])
	{
		largest=i;
	}
	if(r<heap_len && vec[largest]<vec[r])
	{
		largest=r;
	}
	if(largest!=i)
	{
		swap(vec[largest], vec[i]);
		max_heapify(vec, largest);
	}
	return;
}

void print(vector<int> &vec)
{
	for(auto itr: vec)
	{
		cout<<itr<<" ";
	}
	cout<<endl;
}

void creat_heap(vector<int> &vec)
{
	int last_non_leaf_ind= (vec.size()/2)-1;
	for(int i=last_non_leaf_ind; i>=0; i--)
	{
		max_heapify(vec, i);
	}
}

int extract_max(vector<int> &vec)
{
	int max= vec[0];
	vec[0]=vec[vec.size()-1];
	vec.pop_back();
	max_heapify(vec,0);
	return max;
}

void increase_key(vector<int> &vec, int key, int value)
{
	if(value<=vec[key])
	{
		cout<<"error"<<endl;
	}else{
		vec[key]=value;
		int parent= key/2;
		if(parent>=0 && vec[parent]<vec[key])
			swap(vec[key], vec[parent]);
	}
}

void insert_key(vector<int> &vec, int val)
{
	vec.push_back(numeric_limits<int>::min());
	increase_key(vec, vec.size()-1,val );
}

int main() {
	int test_cases, heap_len, element;
	vector <int> vec;
	cin>>test_cases;
	for(auto i=0; i<test_cases; i++)
	{
		cin>>heap_len;
		vec.clear();
		for(auto j=0; j<heap_len; j++)
		{
			cin>>element;
			vec.push_back(element);
		}
		cout<<"-------"<<endl;
		cout<<"output:"<<endl;
		cout<<"-------"<<endl;
		cout<<"created heap: ";
		creat_heap(vec);
		print(vec);
		cout<<"extract_max: "<<extract_max(vec)<<endl;
		cout<<"after extraction: ";
		print(vec);
		cout<<"increased key: ";
		increase_key(vec, 5, 100*(i+3));
		print(vec);
		cout<<"insert_key: ";
		insert_key(vec, 200*(i+6));
		print(vec);
	}
	return 0;
}
