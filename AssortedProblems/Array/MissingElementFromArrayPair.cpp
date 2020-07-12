#include <bits/stdc++.h>

using namespace std;

int get_missing_ele_using_arithmetic_opr(int *arr1, int *arr2,  int size1)
{
	int sum=0;
	for(int i=0; i<size1; i++)
	{
		sum+=arr1[i];
	}

	// subtract the sum of the duplicate array from the total sum.
	for(int i=0; i<size1-1; i++)
	{
		sum-=arr2[i];
	}

	return sum;

}

int get_missing_ele_using_xor(int *arr1, int *arr2,  int size1)
{
	int result=0;
	for(int i=0; i<size1; i++)
	{
		result=result^arr1[i];
	}

	for(int i=0; i<size1-1; i++)
	{
		result=result^arr2[i];
	}
	return result;
}

int main(void)
{
	int arr1[]={9,7, 8, 5, 4, 6, 2, 1, 3};
	int arr2[]={2, 4, 3, 9, 1, 8, 5, 6};

	cout<<"-------------missing element using arithmatic operator approach is-------------"<<endl;
	cout<<"using addition: "<<get_missing_ele_using_arithmetic_opr(arr1, arr2, 9)<<endl;

	cout<<"-------------missing element using XOR operator approach is-------------"<<endl;
	cout<<"using XORing: "<<get_missing_ele_using_xor(arr1, arr2, 9)<<endl;

	return 0;
}

