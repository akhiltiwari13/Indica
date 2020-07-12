/**
 * File              : demo_move_semantics.cpp
 * Author            : akhil <akhiltiwari.13@gmail.com>
 * Date              : 29.04.2018
 * Last Modified Date: 29.04.2018
 * Last Modified By  : akhil <akhiltiwari.13@gmail.com>
 */

#include <iostream>

/* These are the containers that we require */
#include <vector>
#include <list>

#include <random>
#include <algorithm>
#include <string>

/* The chrono standard header could be used for performance measurement in terms of time. */
#include <chrono>

using std::cout;
using std::vector;
using std::list;
using std::vector;
using std::string;
using std::endl;
using std::chrono::system_clock; // for using system_clock::now(). 
using std::chrono::duration; //for duration.

using namespace std;

#define REP(a,b) for(int i=0; i<b; i++)


/* Template  function to print values in a container. */
	template <class T>
void print(T t)
{
	for(auto itr: t)
	{
		cout<<itr<<" ";
	}
	cout<<endl;
}


//class resource definition
class Resource{
	private:
		string name;
	public:
		Resource(string str):name(str){
			//Constructor
			/* cout<<"Constructing Resource: "<<name<<endl; */
		} 

		Resource(const Resource &ref): name(ref.name){ 
			// Copy Constructor.
			/* cout<<"Copy Constructing Resource: "<<name<<endl; */
		}
		~Resource(void)
		{
			// Destructor
			/* cout<<"Destructing Resource: "<<name<<endl; */

		}
		Resource& operator = (const Resource &ref)
		{
			/* When you write a copy assignment operator, values are going into an object that exists already. */
			//Copy Assignment Operator.
			this->name=ref.name;
			/* cout<<"Copy Assigning Resource: "<<name<<endl; */
			return *this;// return type is the reference to object type.
		}

		// a const member fucntion to return name of the resource.
		string GetName() const {return name;}

		bool operator > (const Resource &ref)
		{
			return name>ref.name;
		}
		bool operator < (const Resource &ref)
		{
			return name<ref.name;
		}
		bool operator == (const Resource &ref)
		{
			return name==ref.name;
		}

		/* Defining move constructor for our Resource class */
		Resource( Resource &&rvalue_ref): name(std::move(rvalue_ref.name)){ 
		}

		/* Defining move assignment operator */
		Resource& operator = (Resource &&rvalue_ref)
		{
			// check that we are not self assigning.
			if(this != &rvalue_ref)
			{
			name=std::move(rvalue_ref.name);
			rvalue_ref.name.clear();
			}
			return *this;// return type is the reference to object type.
		}
};


/* Template function to manipulate a container. */
/* This is template is designed keeping in mind that I'll be using it for containers storing string. */
	template <class T>
void exercise(int size, string commonname)
{
	T c;
	typename T::value_type res1("starting entry");
	c.push_back(res1);
	REP(0, size)
	{
		int random= (int)rand();
		string s;
		int ss= random%100; // reserving last 2 digits of my random number (0-99)for my string.
		s.reserve(ss);
		std::generate_n(std::back_inserter(s), ss, [ss]()->char{return (char)('a' + ss/4);});
		typename T::value_type res(s);
		bool inserted = false;
		for(auto itr = begin(c); itr != end(c); itr++)
		{
			if(*itr > res)
			{
				c.insert(itr, res);
				inserted = true;
				break;
			}
		}
		if(!inserted)
		{
			c.push_back(res);
		}
	}
	auto i1= max_element(begin(c), end(c));
	auto m1=*i1;
	cout<<endl;
	cout<<"max element in the "<<commonname<<" is: "<<m1.GetName()<<endl;

	auto i2= min_element(begin(c), end(c));
	auto m2=*i2;
	cout<<"min element in  the "<<commonname<<" is: "<<m2.GetName()<<endl;

	bool sorted = is_sorted(begin(c), end(c));
	cout<<"The "<<commonname<<" is ";
	if(!sorted)
		cout<<"not ";
	cout<<"sorted."<<endl;
}

int main( int argc, char *argv[])
{
	if(argc == 2){
		const int size= atoi(argv[1]);
		auto start_time = system_clock::now();
		//vector
		exercise <vector<Resource>>(size, "vector");
		auto end_time = system_clock::now();
		duration<double> elapsed_time= end_time - start_time;
		cout<<"VECTOR (ms): "<<elapsed_time.count() * 1000<<endl;

		start_time= system_clock::now();
		//list
		exercise<list<Resource>>(size, "list");
		end_time = system_clock::now();
		elapsed_time= end_time- start_time;
		cout<<"LIST (ms): "<<elapsed_time.count()* 1000<<endl;

		return 0;
	}
	else{
		cout<<"Specify length as argument to the program."<<endl;
		return 0;
	}
}
