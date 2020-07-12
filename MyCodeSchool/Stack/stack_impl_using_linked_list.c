// implementing stack using linked lists.
// author: akhil

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node;

node *top=NULL; 

void push(int data)
{
	node *ptr=(node *)malloc(sizeof(node));
	ptr->data=data;
	ptr->next=top;
	top=ptr;

}

void pop()
{
	if(!top)
	{
		puts("there are no elements in the stack to be poped");
		return ;
	}
	node *tmp=top;
	top=tmp->next;
	free(tmp);
}

void print()
{
	puts("stack:");
	node *ptr=top;

		while(ptr)
		{
			printf("%d ", ptr->data);
			ptr=ptr->next;
		}
	puts("");
}

int main()
{
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
