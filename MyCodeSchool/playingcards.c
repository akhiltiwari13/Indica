#include<stdio.h>
#include<string.h>

char *map="23456789TJQKA";

int getIndexInMap(char c)
{
	int i=0;
	//char *localMap=map;
	//while(*(localMap++))
	//{
	 // if(localMap[i]==c)
	//	  return i;
	 // i++;
	//}
	
	for(;map[i]!='\0';i++)
	{
		if(map[i]==c)
			break;
	}
	return i;
}

int winCountA(char* A, char *B)
{
	int i=0;
	int awins=0;
	int aval=0;
	int bval=0;
	for(;A[i]!='\0';i++)
	{
		aval=getIndexInMap(A[i]);
		bval=getIndexInMap(B[i]);
		if(aval>bval)
		{
		    ++awins;
		}
	}
	return awins;
}

int main(void)
{
	char *A= "A586QK";
	char *B= "JJ653K";
	printf("awins %d times \n", winCountA(A,B));
}
