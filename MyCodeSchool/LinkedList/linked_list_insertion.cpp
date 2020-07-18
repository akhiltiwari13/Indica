// inserting nodes in a linked list.
// author: akhil

#include<stdio.h>
#include<stdlib.h>

#define true 1

//structure for the node
typedef struct node {
	int data;
	struct node *next;
}node;

//node* head;
// insertion definition
void insert(int data, int *size, node** head)
{
	node *ptr=(node *)(malloc(sizeof(node)));
	(*ptr).data=data;
	(*ptr).next=*head;
	*head=ptr;
	(*size)++;


}

void insert_at_position(int data, int position, int *size,  node** head)
{
	if((*size)+1>=position)
	{
		node* ptr=(node *)(malloc(sizeof(node)));
		(*ptr).data=data;
		if(position==1)
		{
			(*ptr).next=*head;
			*head=ptr;
			return;

		}
		node* nd_ptr=*head;
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
		(*size)++;
	}
	else{
		puts("an invalid position has been specified");

	}

}

void print(node *ptr)
{
	puts("the list is: ");
	//node* ptr= head;
	while(ptr)
	{
		printf("%d \t", ptr->data);
		ptr=ptr->next;
	} 
	puts("");
}

int main()
{
	node *head = NULL;
	int size=0;
	int i, total_elements, data, position;
	puts("total elements: ");
	scanf("%d", &total_elements);
	for(i=0; i<total_elements; i++)
	{
		// all the insertion operation.
		puts("enter data");
		scanf("%d", &data);
		insert(data,&size, &head);
		print(head);
	}

	while(true)
	{
		// all the insertion operation.
		puts("enter position");
		scanf("%d", &position);
		puts("enter data");
		scanf("%d", &data);
		insert_at_position(data,position,&size, &head);
		print(head);
	}

	return 0;
}
