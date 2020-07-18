#include <bits/stdc++.h>

using namespace std;

// structure of a binary tree node.
struct node{
	int data;
	node *left;
	node *right;
};

node* get_node(int data)
{
	node* ptr= new node();
	ptr->data= data;
	ptr->left= NULL;
	ptr->right= NULL;
	return ptr;
}

void insert_node_left(node* parent_node, int data)
{
	node *new_node= get_node(data);
	parent_node->left=new_node;
}
void insert_node_right(node* parent_node, int data)
{
	node *new_node= get_node(data);
	parent_node->right=new_node;
}

void lot(node* root)
{
	queue<node*> lot_queue;
	lot_queue.push(root);
	node * ptr;
	while(!lot_queue.empty())
	{
		ptr= lot_queue.front();
		cout<<ptr->data<<endl;
		if(ptr->left)
		{
			lot_queue.push(ptr->left);
		}
		if(ptr->right)
		{
			lot_queue.push(ptr->right);
		}
		lot_queue.pop();
	}
}

// checking if a given binary tree is a binary search tree or not.
bool isbst(node* ptr)
{
	bool islbst, isrbst;
	if(ptr)
	{
		islbst=isbst(ptr->left);
		isrbst=isbst(ptr->right);
	}
}

int main(void)
{
	node* root_ptr= get_node(13);
	insert_node_right(root_ptr, 11);
	insert_node_left(root_ptr, 23);
	insert_node_left(root_ptr->left, 3);
	lot(root_ptr);
}



