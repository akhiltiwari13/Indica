#include <bits/stdc++.h>

using namespace std;

// structure of a bst node.
struct bst_node{
	int data;
	bst_node *left;
	bst_node *right;
};

bst_node* get_node(int data)
{
	bst_node *ptr= new bst_node();
	ptr->data=data;
	ptr->left=NULL;
	ptr->right=NULL;
	return ptr;
}


bst_node* insert(bst_node *root_ptr,int  data)
{
	if(!root_ptr) //empty tree.
	{
		root_ptr= get_node(data);
	}
	else{
		//if(root_ptr->data<=data) -- this is incorrect as it will insert the data in the left subtree if it is larger than the root.
		if(data<=root_ptr->data)
		{
			root_ptr->left= insert(root_ptr->left, data);
		}
		else
		{
			root_ptr->right= insert(root_ptr->right, data);
		}
	}
	return root_ptr;
}


bool search(bst_node* root_ptr, int data)
{
	if(!root_ptr)
	{
		return false;
	}
	else if(data<root_ptr->data)
	{
		return search(root_ptr->left, data);
	}
	else if(data>root_ptr->data)
	{
		return search(root_ptr->right, data);
	}
	return true;
}

// finding the minimum element in the binary search tree, using iterative approach.
int find_min_iterative( bst_node* root_ptr)
{
	if(!root_ptr) // Empty tree.
	{
		cout<<"BST is empty"<<endl;
		return -1;
	}
	else
	{
		while(root_ptr->left)
		{
			root_ptr=root_ptr->left;
		}
		// returning the min value.
		return root_ptr->data;
	}
}

// finding the minimum element in the binary search tree, using recursion.
int find_min_recursive(bst_node* root_ptr)
{
	if(!root_ptr) // Empty tree.
	{
		cout<<"BST is empty"<<endl;
		return -1;
	}
	else
	{
		if(!root_ptr->left)
		{
			return root_ptr->data;
		}
		else
		{
			return 	find_min_recursive(root_ptr->left);
		}

	}
}

//finding the maximum element in the binary search tree, using recursion.
int find_max_using_recursion(bst_node* root_ptr)
{
	if(!root_ptr)
	{
		cout<<"BST is empty."<<endl;
		return -1;
	}
	else
	{
		if(!root_ptr->right)
		{
			return root_ptr->data;
		}
		else
		{
			return find_max_using_recursion(root_ptr->right);
		}
	}
}

int get_height(bst_node *root_ptr)
{
	if(!root_ptr)
	{
		return -1;
	}
	else
	{
		return max((get_height(root_ptr->left)+1), get_height(root_ptr->right)+1);
	}
}

// inorder (DFS) of the binary tree
void inorder(bst_node *root_ptr)
{
	if(root_ptr)
	{
		inorder(root_ptr->left);
		cout<<root_ptr->data<<endl;
		inorder(root_ptr->right);
	}
}

// preorder (DFS) of the binary tree.
void preorder(bst_node *root_ptr)
{
	if(root_ptr)
	{
		cout<<root_ptr->data<<endl;
		preorder(root_ptr->left);
		preorder(root_ptr->right);
	}
}

// postorder (DFS) of the binary tree.
void postorder(bst_node *root_ptr)
{
	if(root_ptr)
	{
		postorder(root_ptr->left);
		postorder(root_ptr->right);
		cout<<root_ptr->data<<endl;
	}
}

// Level Order Traversal in a binary tree.
void level_order_traversal(bst_node* root_ptr)
{
	if(!root_ptr)
	{
		cout<<"empty tree"<<endl;
		return ;
	}
	else
	{
		queue<bst_node*> q;
		q.push(root_ptr);
		// iterating through the queue and pushing and poping the elements to and from the queue.
		while(!q.empty())
		{
			cout<<q.front()->data<<endl;
			if(q.front()->left)
			{
				q.push(q.front()->left);
			}
			if(q.front()->right)
			{
				q.push(q.front()->right);
			}
			q.pop();
		}
	}
}
int main(void)
{
	bst_node *root_ptr=NULL;
	root_ptr=insert(root_ptr, 25);
	root_ptr=insert(root_ptr, 18);
	root_ptr=insert(root_ptr, 14);
	root_ptr=insert(root_ptr, 11);
	root_ptr=insert(root_ptr, 9);
	root_ptr=insert(root_ptr, 5);
	root_ptr=insert(root_ptr, 19);
	root_ptr=insert(root_ptr, 16);
	root_ptr=insert(root_ptr, 13);
	root_ptr=insert(root_ptr, 7);
	root_ptr=insert(root_ptr, 17);
	root_ptr=insert(root_ptr, 10);
	root_ptr=insert(root_ptr, 15);
	if(search(root_ptr,14))
	{
		cout<<"found"<<endl;
	}
	else{
		cout<<"not found"<<endl;
	}
	cout<<"min element is: "<<find_min_iterative(root_ptr)<<endl;
	cout<<"min element found using recursion is: "<<find_min_recursive(root_ptr)<<endl;
	cout<<"max element found using recursion is: "<<find_max_using_recursion(root_ptr)<<endl;
	cout<<"height="<<get_height(root_ptr)<<endl;
	cout<<"printing the binary tree using inorder traversal:"<<endl;
	inorder(root_ptr);
	cout<<"printing the binary tree using preorder traversal:"<<endl;
	preorder(root_ptr);
	cout<<"printing the binary tree using postorder traversal:"<<endl;
	postorder(root_ptr);
	cout<<"printing the binary tree using level order traversal:"<<endl;
	level_order_traversal(root_ptr);

	return 0;
}
