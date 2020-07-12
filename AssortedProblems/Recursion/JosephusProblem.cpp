#include<bits/stdc++.h>

using namespace std;

// returns the position for the josephus problem.
int fun(int num)
{
int tmp=1, x=0, l=0, result;
while(tmp<=num)
{
	x=tmp;
	tmp*=2;
}

l= num-x;
result= l<<1;
result +=1;
return result;
}

int main()
{
	int num;
	cin>>num;
	cout<<"posintion= "<<fun(num)<<endl;
    return 0;
}

