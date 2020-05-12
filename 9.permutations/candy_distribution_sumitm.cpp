#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

uint solution(vector<long> v){
	std::set<long> s;
	auto max=v.size()/2;
	for(auto itr: v){
		s.insert(itr);
	}
	auto unq=s.size();
	return min(unq,max);
}
int main(){
	vector<long> x = {1, 2, 4, 4, 5, 5};
	cout<<"answer: " <<solution(x);
	return 0;
}