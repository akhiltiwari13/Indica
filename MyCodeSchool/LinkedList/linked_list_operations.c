// menu based program for performing general operations on a linked list
// author: akhil

#include<stdio.h>
#include<stdlib.h>

#define true 1


//structure for the node
typedef struct node {
	int data;
	struct node *next;
}node;

// globally declared head of the linked list for easy manipulations.
node* head;


// globally declared size of the linked list to check for the boundry conditions of the operations.
int size;

// insertion definition
void insert_at_begining(int data )
{
	node *ptr=(node *)(malloc(sizeof(node)));
	(*ptr).data=data;
	(*ptr).next=head;
	head=ptr;
	size++;

}

void insert_at_position(int data, int position)
{
	if(size+1>=position)
	{
		node* ptr=(node *)(malloc(sizeof(node)));
		(*ptr).data=data;
		if(position==1)
		{
			(*ptr).next=head;
			head=ptr;
			return;

		}
		node* nd_ptr=head;
		int counter=1;
		while(counter<position-1 && position!=1)
		{
			nd_ptr=(*nd_ptr).next;
			counter++;

		}

		if(position!=1)
		{

			(*ptr).next=(*nd_ptr).next;
			(*nd_ptr).next=ptr;
		}
		size++;
	}
	else{
		puts("an invalid position has been specified");

	}

}

void delete_at_position(int position)
{
	if(position>0 && position<=size)
	{
		node *tmp;
		if(position==1)
		{
			tmp=head;
			head=tmp->next;
			free(tmp);
		}
		else {
			node *ptr=head;
			for(int i=0; i<position-2; i++)
			{
				ptr=ptr->next;
			}
			tmp=ptr->next;
			ptr->next=tmp->next;
			free(tmp);
		}
		size--;
		return;
	}
	else{
		puts("enter a valid element to be deleted");
		return;
	}
}

void  reverse_iteratively()
{
	node *cur=head;
	node *prv=NULL;
	node *nxt=NULL;
	while(cur)
	{
		nxt=cur->next;
		cur->next=prv;
		prv=cur;
		cur=nxt;
	}
	head=prv;
}

void reverse_recursively( node *cur)
{
	if(!cur->next)
	{
	head=cur;
	return;
	}
	reverse_recursively(cur->next);
	  cur->next->next=cur;
	  cur->next=NULL;
}

void print()
{
	puts("the list is: ");
	node* ptr= head;
	while(ptr)
	{
		printf("%d ", ptr->data);
		ptr=ptr->next;
	} 
	puts("");
}

void print_recursively(node *head)
{
	// aparently c compiler always takes in the local variable if there is a name conflict wiht a global variable.
	if(head)
	{
		printf("%d ", head->data);
		print_recursively(head->next);
	}
}
void reverse_print(node *head)
{
	// aparently c compiler always takes in the local variable if there is a name conflict wiht a global variable.
	if(head)
	{
		reverse_print(head->next);
		printf("%d ", head->data);
	}
}

int main()
{

	// initializing the global varaibles.
	head = NULL;
	size=0;
	char choice;
	int  data, position, number_of_elements;
	do
	{
		// show the menu
		puts("i: insert at begining");
		puts("p: print the list");
		puts("P: print the list using a recursive algorithm");
		puts("a: print the list in the reverse order using recursion");
		puts("h: print the size of the linked list");
		puts("s: insert at a specific position");
		puts("d: delete at a specific position");
		puts("r: reverse the linked list iteratively");
		puts("R: reverse the linked list recursively");
		puts("q: to quit the program");

		scanf(" %c", &choice);
		switch (choice)
		{
			case 'i':
			case 'I':
				puts("enter the number of elements to be inserted");
				scanf("%d",&number_of_elements);
				for(int i=0; i<number_of_elements; i++)
				{
					puts("enter data:");
					scanf("%d",&data);
					insert_at_begining(data);
				}
				break;
			case 'p':
				print();
				break;
			case 'P':
				puts("recursive print happening.....");
				print_recursively(head);
				puts("");
				break;
			case 'a':
				puts("recursive reverse print");
				reverse_print(head);
				puts("");
				break;
			case 's': 
			case 'S':
				puts("enter position:");
				scanf("%d",&position);
				puts("enter data:");
				scanf("%d",&data);
				insert_at_position(data,position);
				break;

			case 'd':
			case 'D':
				puts("enter position:");
				scanf("%d",&position);
				delete_at_position(position);
				break;
			case 'h':
			case 'H':
				printf("size of the list is %d\n", size);
				break;
			case 'r':
				puts("reverse the linked list using iterative algorithm");
				reverse_iteratively();
				break;
			case 'R':
				reverse_recursively( head );
				break;
			case 'q':
			case 'Q':
				puts("exiting application...");
				break;
			default: 
				break;
		}

	}
	while(choice != 'q' && choice !='Q');

	return 0;
}
