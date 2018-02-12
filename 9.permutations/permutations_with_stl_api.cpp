#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string given = { 'a', 'b', 'c', 'd' };

int main(void)
{
	do{
		cout<< given <<endl;

	}while(next_permutation(begin(given), end(given)));
	return 0;
}


