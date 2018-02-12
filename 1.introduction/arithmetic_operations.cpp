#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	long long num=123LL;
	long long div=23LL;
	long long modular= num % div;
	__int128_t bignum=11112345678423; // the value of the type __int128_t can not be printed to console using cout<<.
	cout<<"long long data type"<<num<<endl;
	cout<<"printing the modular"<< modular<<endl;
	return 0;
	// g++ also provide the datatype __int128_t which is a 128 bit number(really big)
}
