//program to impement a stack using arrays
//author: akhil.

#include<stdio.h>
#include<stdlib.h> // needed for dynamic memory allocation.

//memory is allocated to static variables at runtime therefore they may be initialized without any runtime cost.
int top=-1;
int stack_size=4; //define the max number of elements in the stack.

// there is some compile time error when i try to initialize this pointer here.
int *stack;

void push(int data)
{
	if(top+1==(stack_size)/2)
	{
		// expand the stack if the content of the stack increase to half the current size.
		stack=(int *)realloc(stack,sizeof(int)*2*stack_size);
	}
	stack[++top]=data;
}

int isempty()
{
	return top==-1;
}
void pop()
{
	if(!isempty())
	{
		top--;
		return ;
	}
	puts("there are no elements in the stack to be poped");
}
void print()
{
	puts("stack:");

	for(int i=0; i<=top; i++)
	{
		printf("%d ", stack[i]);
	}
	puts("");
}
int main()
{
	// why could I not initialize stack as a static variable?
	stack=(int *)malloc(sizeof(int)*stack_size);
	int num_of_elements,data;
	char choice;
	do{
		puts("p: to push");
		puts("r: to pop");
		puts("s: to print");
		puts("q: to quit");
		
		//store the user's choice.
	scanf(" %c", &choice);
	
	//menu based processing.
	switch(choice)
	{
		case 'p':
			puts("# of elements to be pushed?");
			scanf("%d", &num_of_elements);
			for(int i=0; i<num_of_elements; i++)
			{
				puts("data");
				scanf("%d",&data);
				push(data);
			}
			break;
		case  'r':
			pop();
			break;
		case 's':
			print();
			break;
		case 'q':
		case 'Q':
			break;
				
	}
		
	}while(choice !='q' && choice !='Q');
	
	return 0;

}
