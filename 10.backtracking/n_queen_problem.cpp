#include<iostream>

using namespace std;

const int sq_size=16;
int count=0;
int column [sq_size];
int left_diagonal[2* (sq_size-1)+1];
int right_diagonal[2* (sq_size-1)+1];

void n_queen_solution(int r)
{
	if(r==sq_size)
	{
		// one solution has been found as all the elements of the matrix/ chess board have been visited.
		count++; 
	}
	else
	{
		for(int c=0 ; c< sq_size; c++)
		{
			if( column[c]|| left_diagonal[c+r] || right_diagonal[r-c+sq_size-1])
				continue;
			else
			{{{
				  column[c]= left_diagonal[c+r] = right_diagonal[r-c+sq_size-1]=1;
				  n_queen_solution(r+1);
				  column[c]= left_diagonal[c+r] = right_diagonal[r-c+sq_size-1]=0;
			  }}}
		}
	}
}
int main(void)
{
	n_queen_solution(0);
	cout<<"total solutions to the 4-queens problem are: "<<count<<endl;
	return 0;
}
