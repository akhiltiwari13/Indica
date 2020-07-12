#include<stdio.h>
#include<stdlib.h>

#define true 1


//structure for the node
typedef struct node {
	int data;
	struct node *next;
	struct node *prev;
}node;


// globally declared head of the linked list for easy manipulations.
node* head;

// globally declared tail to the double linked list.
node *tail;

// globally declared size of the linked list to check for the boundry conditions of the operations.
int size;
node* get_node(int data)
{
	node *ptr=(node *)malloc(sizeof(node));
	ptr->data=data;
	ptr->next=NULL;
	ptr->prev=NULL;
	return ptr;
}

void insert_at_start(int data)
{
	node *ptr=get_node(data);
	ptr->next=head;
	head=ptr;
	size++;
}
void insert_at_end(int data)
{
	node *ptr=get_node(data);
	node *tmp=head;
	if(!tmp)
	{
		insert_at_start(data);
		return;
	}
	while(tmp->next)
	{
	  tmp=tmp->next;
	}
	tmp->next=ptr;
	ptr->prev=tmp;
	size++;
}

void print_forward()
{
	puts("the doubly-linked-list is:");
	node *ptr=head;
	while(ptr)
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
	puts("");
}

void print_backwards()
{
	puts("the doubly-linked-list backwards, is:");
	node *ptr=head;
	if(!ptr)
	{
		puts("empty list");
		return;
	}
	//traversing forward to reach the last node of the doubly linked list.
	while(ptr->next)
	{
		ptr=ptr->next;
	}
	//traversing backwards while printing data.
	while(ptr)
	{
		printf("%d ",ptr->data);
		ptr=ptr->prev;
	}
	puts("");
}
// function main
int main()
{

	// initializing the global varaibles.
	head = NULL;
	tail = NULL;
	size=0;
	char choice;
	int  data, position, number_of_elements;
	do
	{
		// show the menu
		puts("i: insert at begining");
		puts("I: insert at the end");
		puts("p: print the doubly linked list in a forward manner");
		puts("P: print the doubly linked list in a backwards manner");
		puts("q: to quit");

		scanf(" %c", &choice);
		switch (choice)
		{
			case 'i':
				puts("enter the number of elements to be inserted");
				scanf("%d",&number_of_elements);
				for(int i=0; i<number_of_elements; i++)
				{
					puts("enter data:");
					scanf("%d",&data);
					insert_at_start(data);
				}
				break;
			case 'I':
				puts("enter the number of elements to be inserted");
				scanf("%d",&number_of_elements);
				for(int i=0; i<number_of_elements; i++)
				{
					puts("enter data:");
					scanf("%d",&data);
					insert_at_end(data);
				}
				break;
			case 'p':
				print_forward();
				break;
			case 'P':
				print_backwards();
				break;
			case 'a':
				break;
			case 's':
			case 'S':
				puts("enter position:");
				scanf("%d",&position);
				puts("enter data:");
				scanf("%d",&data);
				break;

			case 'd':
			case 'D':
				puts("enter position:");
				scanf("%d",&position);
				break;
			case 'h':
			case 'H':
				printf("size of the list is %d\n", size);
				break;
			case 'r':
				puts("reverse the linked list using iterative algorithm");
				break;
			case 'R':
				break;
			case 'q':
			case 'Q':
				puts("exiting application.....");
				break;
			default:
				break;
		}

	}while(choice !='q' && choice !='Q');

	return 0;
}
