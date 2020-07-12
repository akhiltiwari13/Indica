// this program gives all the prime numbers in the range 2 to n.
#include<stdio.h>
#include<math.h>
#define SIZE 256

int main(int argc, char *argv[], char* env[])
{

	int num;
	printf("enter a number: \n");
	scanf("%d",&num);
        int i=0, j=0;
	int p_arr[SIZE];

	for (i=0; i<=num ; i++)
		p_arr[i]=1;

	p_arr[0]=0;
	p_arr[1]=0;
	
	for(i=2; i<=sqrt(num); i++)
	{
		if(p_arr[i]=1)
		{
			for(j=2; i*j<=num; j++)
			{
				p_arr[i*j]=0;
			}
		}
	}
	
	printf("the prime numbers are:\n");
	for(i=2;i<=num; i++)
	{
		if(p_arr[i]==1)
			printf("%d\n",i);
	}

	return 0;
}


