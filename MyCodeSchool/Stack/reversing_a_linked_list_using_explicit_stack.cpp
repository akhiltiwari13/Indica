#include <iostream>
#include <stack>

using namespace std;

// global definition of the node of the linked list
typedef struct node{
	int data; 
	struct node* next; 
}node;

stack<node *> stk;

struct node *head; // head of the linked list

void insert_at_begining(int num) { // initialize a new node and put the data in it, hold a reference to it so as to add it to the remaining lists.
	// using the complicated syntax for dereferencing the structure pointer.
	node *tmp=(node *)malloc(sizeof(node));
	(*tmp).data=num; 
	(*tmp).next=head;
	head=tmp;
}
void print()
{
	node* tmp=head;
	while(tmp)
	{
		printf("%d\n",(*tmp).data);
		tmp=(*tmp).next;
	}
}
int main(void)
{
	for(int i=0; i<5; i++)
	{
		insert_at_begining(i+2);
	}
	cout<<"original linked list: "<<endl;
	print();

	// reversing the linked list using explicit stack.
	// pushing all the elements of the linked list onto a stack.
	node *tmp=head;
	cout<<"starting the linked list reversal"<<endl;
	while(tmp)
	{
		stk.push(tmp);
		tmp=tmp->next;
	}
	tmp=stk.top();
	head=tmp;
	stk.pop();
	while(!stk.empty())
	{
		tmp->next=stk.top();
		stk.pop();
		tmp=tmp->next;
	}
	tmp->next=NULL;
	cout<<"reversed linked list: "<<endl;
	print();
	return 0;
}
