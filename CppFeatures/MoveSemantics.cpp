/**
 * File              : more_move_semantics.cpp
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


//class resource definition
class Resource{
	private:
		string name;
	public:
		//Constructor
		Resource(string str):name(str){
			cout<<"Constructing: "<<name<<endl;
		} 

		// Copy Constructor.
		Resource(const Resource &ref): name(ref.name){ 
			cout<<"Copy Constructing: "<<name<<endl;
		}
		// Destructor
		~Resource(void)
		{
			cout<<"Destructing: "<<name<<endl;

		}
		//Copy Assignment Operator.
		Resource& operator = (const Resource &ref)
		{
			this->name=ref.name;
			cout<<"Copy Assigning: "<<name<<endl;
			return *this;// return type is the reference to object type.
		}

		/* Move Constructor */
		Resource( Resource &&rvalue_ref): name(std::move(rvalue_ref.name)){ 
			cout<<"Move Constructing: "<<name<<endl;
		}

		//Move Assignment Operator.
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

};

/* main */
int main()
{
	vector<Resource> vec;
	cout<<"----------------------------------------------"<<endl;
	Resource res("Thinkpad");
	cout<<"----------------------------------------------"<<endl;
	vec.push_back(res);
	cout<<"----------------------------------------------"<<endl;
	vec.push_back(Resource("Mackbook"));
	cout<<"----------------------------------------------"<<endl;
	std::for_each(begin(vec), end(vec), [](const Resource &r){
			cout<<r.GetName()<<endl;
			});
		return 0;
	}


