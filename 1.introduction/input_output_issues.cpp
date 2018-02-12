/*ios::sync_with_stdio(0);
cin.tie(0);*/
// this was not working .... it is supposed to make takingkk the inputs easier.

#include<bits/stdc++.h> // this line includes all the header files / libraries of c++. good for competitive programming.
using namespace std; // for using all the classes and functions of the standard library without any conflict.

// for making input and output more efficient
	

int main()
{
	int int1, int2;
	string str,withSpaces, biggestsofar;
	cout<<"enter the string with spaces"<<endl;
	getline(cin, withSpaces);
	cout<<"enter 2 numbers followed by a string without spaces"<<endl;
	cin>>int1>>int2>>str;
	cout<<int1<<"\n"<<int2<<"\n"<<str<<"\n"; // "\n" is faster than endl as endl always performs a flush operation.
	cout<<withSpaces<<endl;
	cout<<"keep entering"<<endl;
	while(cin>>biggestsofar)
	{
	// this is awesome	
	}
	cout<<biggestsofar;
	return 0;
}

// for compiling the code use: g++ -O2 -Wall -std=c++11
// this compiles the source and generates an optimized solution along with giving warnings and the used the c++11 standard for compilation.

