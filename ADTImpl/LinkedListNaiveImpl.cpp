//Program that implements a linked list to act a queue.

typedef struct node{
  struct node * next;
}node;

typedef struct list{
  node * first;
  node * last;
}list;

void list_init(list * container)
{
  container->first=0;
  container->last=0;
}

short is_empty(list * container)
{
  return (0==container->first);
}

node * list_begin(list * container)
{
  return container->first;
}

node * list_next( node * element)
{
  return element->next;
}

void push_back(list* container, node* element)
{

  if(is_empty(container))
  {
    container->first=element;
    container->last=element;
  }
  else{
    container->last->next=element;
    container->last=element;
  }
  element->next=0;
}

node*  pop_front(list* container)
{
  // This function assumes that the list points to atleast on element.
  node* first_element= container->first;
  container->first=container->first->next;
  return first_element;
}

//included the header files of the standard c libraries for the upcomming main function.
#include<stdio.h>
#include<stdlib.h>


typedef struct prog_node{
  node  header;
  int value;
}prog_node;

int main()
{
  list prog_nodes;
  prog_node* n1= (prog_node*)malloc(sizeof(prog_node));
  prog_node* n2= (prog_node*)malloc(sizeof(prog_node));
  prog_node* n3= (prog_node*)malloc(sizeof(prog_node));

  n1->value=1;
  n2->value=2;
  n3->value=3;

  list_init(&prog_nodes);

  push_back(&prog_nodes, &(n1->header));
  push_back(&prog_nodes, &(n2->header));
  push_back(&prog_nodes, &(n3->header));

  for(prog_node* n= (prog_node*)list_begin(&prog_nodes);n;n=(prog_node*)list_next(&n->header))
  {
    printf("node value:%d\n",n->value );
  }

  return 0;
}
