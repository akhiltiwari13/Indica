#include <stdio.h>
#include <stdlib.h>

// global definition of the node of the linked list
typedef struct node {
  int data;
  struct node *next;
} node;

struct node *head; // head of the linked list

void insert_at_begining(
    int num) { // initialize a new node and put the data in it, hold a reference
               // to it so as to add it to the remaining lists.
  // using the complicated syntax for dereferencing the structure pointer.
  node *tmp = (node *)malloc(sizeof(node));
  (*tmp).data = num;
  (*tmp).next = head;
  head = tmp;
}
void print() {
  node *tmp = head;
  while (tmp) {
    printf("%d\n", (*tmp).data);
    tmp = (*tmp).next;
  }
}

int main() {
  head = NULL; // initialize the head to NULL initially.
  int total, i, num;
  puts("enter the number of elements to be inserted in the linked list");
  scanf("%d", &total);
  for (i = 0; i < total; i++) {
    // puts("enter the number to be stored");
    // scanf("%d\n",&num);
    insert_at_begining(33);
    print();
  }
  return 0;
}
