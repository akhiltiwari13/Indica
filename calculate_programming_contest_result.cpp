#include<stdio.h>
#include<string.h>
#define REP(i,l) for(int i=0; i<l; i++)

int has_passed(char *result)
{
	if(strcmp(result, "OK"))
		return 1;
	return 0;
}
int is_num(char c)
{
	char num[]={'1','2','3','4','5', '6', '7', '8', '9'};
	REP(i,10)
	{
		if(num[i]==c)
			return (i);
	}
	return 0;
}
int calc_test_case_index(char *tc)
{
	int ind;
	char *tmp=tc;
	while(*tmp)
	{
		tmp++;
	}
	ind=is_num(*tmp);
	if(ind)
	{
		return  ind--;
	}
	else{
		tmp--;
		ind=is_num(*tmp);
		return ind--;
	}
	return 0;
}
int solution(char *T[], int N, char *R[], int M) {
	// write your code in C99 (gcc 6.2.0)
	int res_arr[N];
	int ind;
	int sum=0;
	// making result for all the groups as 1.
	REP(i,10)
	{
		res_arr[i]=-1;


	}
	REP(i,N)
	{
		ind=calc_test_case_index(T[i]);
		if(has_passed(R[i]))
		{
			res_arr[i]=1;
		}
		else{
			res_arr[i]=0;
		}

	}
	int x=0;int count=0;
	REP(i,10)
	{
		if(res_arr[i]==1)
		sum+=res_arr[i];
		i++;
		count++;
	}
	return ((sum*100)/count);


}

int main()
{

	return 0;
}
