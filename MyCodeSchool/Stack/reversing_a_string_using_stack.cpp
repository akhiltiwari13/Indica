#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

int main(void)
{
	const char *str= "hello";
	int len= strlen(str);
	cout<<"given string: "<<str<<endl;

	stack<char> char_stk;
	for(int i=0; str[i]; i++)
	{
		char_stk.push(str[i]);
	}
	cout<<"reversed string: ";
	for(int i=0; i<len; i++)
	{
		cout<<char_stk.top();
		char_stk.pop();
	}
	cout<<endl;
	return 0;
}

