#include <bits/stdc++.h>
using namespace std;

int main(){
	auto set = (1<<1 | 1<<3 | 1<<4 | 1<<8); //set=282;
	int subset=0;
	
	// traversing all the subsets of the set indicated by set=282.
	do{
		// process subset;
		// print bit representation of all the subsets.
		cout<<"subset bit representation: "<<subset<<endl;

		//print the subset elements from the bit representations
		cout<<"subsets= {";
		for(auto i=0; i<9; i++){
			if(subset & 1<<i) cout<<i<<" ";
		}
		cout<<"}"<<endl;

		// moving to a newer subset.
		subset=( (subset-set) & set);
	}while(subset);
	return 0; 
} 