#include <iostream>
#include <vector>

using namespace std;

const int sq_size=7;
int matrix[sq_size][sq_size] ={{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,0,0,0}};
int count =0;

void traverse(int row)
{
	if(row==sq_size)
	{
		count++;
	}
	else
	{
		for(int c= 0; c<sq_size; c++)
		{
			if(matrix[row][c])
			{
				continue;
			}
			else
			{
				matrix[row][c]=1;
				traverse(c+1);
				matrix[row][c]=0;
			}
		}
	}
}
int main(void)
{
	traverse(0);
	cout<<"result="<<count<<endl;
	return 0;
}
