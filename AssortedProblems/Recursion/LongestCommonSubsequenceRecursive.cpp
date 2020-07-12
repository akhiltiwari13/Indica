#include <iostream>
#include <string>

using namespace std;

int fun(string str_a , string str_b, unsigned int len_a, unsigned int len_b)
{
	if(len_a==0 || len_b==0)
		return 0;
		else{
			if(str_a[len_a-1]== str_b[len_b-1])
			{
				return fun(str_a, str_b, len_a-1, len_b-1)+1;
			}
			else{
				return max(fun(str_a, str_b, len_a, len_b-1),
				fun(str_a, str_b, len_a-1, len_b)
				);
			}
		}
}

int main(int argc, char **argv)
{
	string str_a, str_b;
	
	cout<<"string 1:";
	cin>>str_a;
	cout<<"string 2:";
	cin>>str_b;
	cout<<"longest common subsequence="<<fun(str_a, str_b, str_a.size(), str_b.size())<<endl;
	
	return 0;
}
