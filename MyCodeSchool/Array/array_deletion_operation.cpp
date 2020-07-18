// has various functions to delete the array elements.
// author: akhil


#include<stdio.h>
#define  MAX_LEN 10

int curr_size=0;

void delete_at_index(int *begin, int *end, int index)
{
	int *ptr=begin +index;
	// checks if a correct index is specified.
	if(index<curr_size)
	{

		//start shifting all the elements one place to their left starting from the element next to the specified index.
		while(ptr<end-1 )
		{
			*(ptr-1)=*(ptr);
			ptr++;

		}
		--curr_size;


	}
	else{
		puts("the index should be less than the current size of the array");
	}
}
void delete_at_begining(int *begin, int *end)
{

	//start shifting all the elements one place to their left.
	while(begin<end-1)
	{
		*begin=*(begin+1);
		begin++;

	}
	--curr_size;



}

void print_array(int *begin, int *end ){
	puts("given array");
	while(begin!=end)
	{
		printf("%d\n",*(begin));
		begin++;
	}
} 

//main function
int main()
{
	int arr[MAX_LEN]={13,05, 11, 30, 26};
	curr_size=5;
	// print initial array
	print_array(arr, arr+curr_size);
	int kIndex=3;
	char dec,operation;

	do{
		puts("i:to delete at index");
		puts("b: to delete at the beginnig");
		puts("p: to print the array");

		scanf(" %c", &operation);
		switch (operation)
		{

			case 'i':
				puts("index");
				scanf("%d", &kIndex);
				// delete at the given index
				delete_at_index(arr, arr+curr_size, kIndex);
				break;


			case 'b':
				// delete at the beginig of the array
				delete_at_begining(arr, arr+curr_size);
				break;

			case 'p':
				print_array(arr, arr+curr_size);
				break;


			default:
				print_array(arr, arr+curr_size);
				puts("incorrect choice");
				break;



		}


		printf("enter q to quit\n");
		scanf( " %c",&dec);

	}
	while(dec!='q');

	puts("final array");
	print_array(arr, arr+curr_size);

	return 0;

}
