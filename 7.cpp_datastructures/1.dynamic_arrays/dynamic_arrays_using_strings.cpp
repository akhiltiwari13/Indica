#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string str1= "akhil"; 
	cout<<"&str1: "<<&str1<<endl;
	string str2= "tiwari";
	str1= str1+" "+str2;
	cout<<"&str1: "<<&str1<<endl;

	cout<<"str1: "<<str1<<endl;
	str1[5]='-';
	cout<<"str1[5]:"<<str1[5]<<endl;
	cout<<"str1.substr(2,5):"<<str1.substr(2,5)<<endl;
	return 0;
}

