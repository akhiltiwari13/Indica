/**
 * File              : advanced_features.cpp
 * Author            : akhil <akhiltiwari.13@gmail.com>
 * Date              : 27.04.2018
 * Last Modified Date: 27.04.2018
 * Last Modified By  : akhil <akhiltiwari.13@gmail.com>
 */

#include <bits/stdc++.h>
/* #include <memory> -- This header has the smart pointers */

/* inclusion of non standard library */
#include<boost/progress.hpp> //this boost library is used for performance measurement.

using namespace std;


#define REP(a,b) for(int i=0; i<b; i++)

/* Template  function to print values in a container. */
	template <class T>
void printc(T t)
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
			cout<<"Constructing Resource: "<<name<<endl;
		} 

		Resource(const Resource &ref): name(ref.name){ 
			// Copy Constructor.
			cout<<"Copy Constructing Resource: "<<name<<endl;
		}
		~Resource(void)
		{
			// Destructor
			cout<<"Destructing Resource: "<<name<<endl;

		}
		Resource& operator = (const Resource &ref)
		{
			/* When you write a copy assignment operator, values are going into an object that exists already. */
			//Copy Assignment Operator.
			this->name=ref.name;
			cout<<"Copy Assigning Resource: "<<name<<endl;
			return *this;// return type is the reference to object type.
		}

		// a const member fucntion to return name of the resource.
		string GetName() const {return name;}

};

// class Person; this is an example of composition
class Person{
	private:
		string firstname;
		string lastname;
		int arbitrarynumber;
		/* unique_ptr<Resource> pResource; //the Person objects will have a solid Resouce object. */
		shared_ptr<Resource> pResource; //the Person objects will have a solid Resouce object.
	public:
		Person(string fname, string lname, int arbitrary):firstname(fname), lastname(lname), arbitrarynumber(arbitrary) {cout<<"Constructing Person "<<fname<<" "<<lname<<endl;}
		string GetName() const {return firstname+" "+lastname;}
		int GetNumber() const {return arbitrarynumber;}
		void SetNumber(int arb){arbitrarynumber=arb;}
		void SetFName(string  name){firstname=name;}
		void SetLName(string  name){lastname=name;}
		void SetResource(string name){
			pResource=make_shared<Resource>(name);
		}
		string GetResourceName() const { return pResource->GetName();}


		/* for shared pointer, copy constructor definition and copy assignment operator definition would not be necessary. */
		// Defining the copy constructor for the Person Class.
		/* Person(const Person& ref) */
		/* { */
		/* 	this->firstname=ref.firstname; */
		/* 	this->lastname=ref.lastname; */
		/* 	this->arbitrarynumber=ref.arbitrarynumber; */
		/* 	this->pResource.reset(new Resource(ref.pResource->GetName())); */
		/* } */
		/* Defining the copy assignment operator */
		/* Person& operator = (const Person& ref) */
		/* { */
		/* 	this->firstname=ref.firstname; */
		/* 	this->lastname=ref.lastname; */
		/* 	this->arbitrarynumber=ref.arbitrarynumber; */
		/* 	this->pResource.reset(new Resource(ref.pResource->GetName())); */
		/* 	return *this; */
		/* } */
		/* Defining Destructor */
		~Person()
		{
			cout<<"Destructing Person: "<<firstname<<" "<<lastname<<endl;
		}

};

int fun(int y){cout<<"hello world";return ++y;};

int main()
{
	boost::progress_timer timer; // as it goes out of scope, it prints the time the timer was in scope.

	/* Demonstration of memory management. */
	/* Person p("akhil", "tiwari", 13); */
	/* p.SetResource("Lenovo Thinkpad x1 carbon"); */
	/* p.SetResource("Macbook pro"); */
	/* Person p2 = p; //when creating a new object using assignment operator, a copy constructor is invoked and not the copy assignment operator. */
	/* p=p2; */
	/* string str=p.GetName(); */

	/* Demo of LAMBDA Capture */
	int x=0, y=0;

	/* LAMBDA that captures the entire stack by reference. */
	auto print= [&](){cout<<"x: "<<x<<" y: "<<y<<endl;};

	vector<int> vec;

	REP(0,5)
	{
		vec.push_back(i);
	}
	printc(vec);

	for_each(begin(vec), end(vec), [=](int element) mutable {x+=element; y+=element;});
	print();//call to the lambda.

	for_each(begin(vec), end(vec), [&](int element) mutable {x+=element; y+=element;});
	print();//call to the lambda.

	return 0;
}
