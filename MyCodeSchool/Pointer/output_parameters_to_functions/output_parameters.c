#include<stdio.h>

void minMax(int *begin, int *end, int **min, int **max)
{
	if(begin==end)
		*min=*max=0;// setting the values of minumum and maximum to a null.
	else{
		//initializing the output parameters to the null
	       *min=*max=begin;
	       while(++begin!=end)
	       {
		       if(**min>*begin)
			       *min=begin;
		       if(**max<*begin)
			       *max=begin;

	       }
	}

}


int main(void)
{
	int arr[]={13,22,30,4,7,22};
	int size= sizeof(arr)/sizeof(arr[0]); // gives the size of array in terms of the number of elements.

	// initializing the 2 supposed output parameters to null
	int *min=0;
	int *max=0;

	minMax(arr, arr+size, &min, &max);
	printf("max=%d\n",*max);
	printf("min=%d\n", *min);

	return 0;
}
