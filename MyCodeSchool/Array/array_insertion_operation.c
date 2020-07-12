#include<stdio.h>
#define  MAX_LEN 10

int curr_size=0;

void insert_at_index(int *begin, int *end, int index, int element)
{
	// checks if a correct index is specified.
	if(index<=curr_size)
	{

		//start shifting all the elements one place to their right.
		while(end!=(begin+index))
		{
			*end=*(end-1);
			end--;

		}
		*end=element;
		curr_size++;


	}
	else{
		puts("the index should be less than or equal to the current size of the array");
	}
}
// for inserting before the given index
void insert_before_index(int *begin, int *end, int index, int element)
{
	// checks if a correct index is specified.
	if(index<=curr_size)
	{

		//start shifting all the elements one place to their right.
		while(end!=(begin+index))
		{
			*end=*(end-1);
			end--;

		}
		*end=element;
		curr_size++;


	}
	else{
		puts("the index should be less than the current size of the array");
	}
}


// for inserting after the given index
void insert_after_index(int *begin, int *end, int index, int element)
{
	// checks if a correct index is specified.
	if(index<curr_size)
	{

		//start shifting all the elements one place to their right.
		while(end!=(begin+index+1))
		{
			*end=*(end-1);
			end--;

		}
		*end=element;
		curr_size++;


	}
	else{
		puts("the index should be less than the current size of the array");
	}
}

void insert_at_begining(int *begin, int *end, int element)
{

	//start shifting all the elements one place to their right.
	while(end!=begin)
	{
		*end=*(end-1);
		end--;

	}
	*end=element;
	curr_size++;



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
	int element=66;
	char dec,operation;

	do{
		puts("b:to insert before index");
		puts("a:to insert at index");
		puts("l:to insert after index");
		puts("s: to insert at the beginnig");
		puts("p: to print the array");

		scanf(" %c", &operation);
		switch (operation)
		{
			case 'b':
				puts("index");
				scanf("%d", &kIndex);
				puts("element");
				scanf("%d",&element);
				// insert before the specified index
				insert_before_index(arr, arr+curr_size, kIndex, element);
				break;

			case 'a':
				puts("index");
				scanf("%d", &kIndex);
				puts("element");
				scanf("%d",&element);
				// insert at the given index
				insert_at_index(arr, arr+curr_size, kIndex, element);
				break;

			case 'l':
				puts("index");
				scanf("%d", &kIndex);
				puts("element");
				scanf("%d",&element);
				// insert after the given index
				insert_after_index(arr, arr+curr_size, kIndex, element);
				break;

			case 's':
				puts("element");
				scanf("%d",&element);
				// insert at the beginig of the array
				insert_at_begining(arr, arr+curr_size, element);
				break;

			case 'p':
				print_array(arr, arr+curr_size);
				break;


			default:
				print_array(arr, arr+curr_size);
				puts("incorrect choice");
				break;



		}


		printf("y to continue\n");
		scanf( " %c",&dec);

	}
	while(dec=='y');

	puts("final array");
	print_array(arr, arr+curr_size);

	return 0;

}
