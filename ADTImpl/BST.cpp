#include <iostream>
#include <queue>
using namespace std;

struct node{
	int data;
	node *l;
	node *r;
};

node *create_node(int data)
{
	node *ptr= new node();
	ptr->data=data;
	ptr->l=NULL;
	ptr->r=NULL;
	return ptr;
}

void recursive_insert(int data, node **ptr)
{
	if(!*ptr)
	{
		
		(*ptr)= create_node(data);
	}
	else{
		if(data<= (*ptr)->data)
		{
			recursive_insert(data, &((*ptr)->l));
		}
		else{
			recursive_insert(data, &((*ptr)->r));
		}
	}
}

void iterative_insert(int data, node **ptr)
{
	
	while(*ptr)
	{
	if(data<=(*ptr)->data)
	{
		ptr=&(*ptr)->l;
	}	
	else{
		ptr=&(*ptr)->r;
	}
	}
		
		(*ptr)=create_node(data);
		

	
}

void recursive_inorder_traversal(node *ptr)
{
	if(ptr)
	{
		recursive_inorder_traversal(ptr->l);
		cout<<ptr->data<<endl;
		recursive_inorder_traversal(ptr->r);

	}
}

bool recursive_search(int data, node *ptr)
{
	if(!ptr)
	{
		return false;
	}
	else{
		if(data==ptr->data)
		{
			return true;
		}
		if(data<ptr->data)
		{
			return recursive_search(data, ptr->l);
		}
		else{
			return recursive_search(data, ptr->r);

		}
	}
}

bool iterative_search(int data, node *ptr)
{
	bool found=false;
	while(ptr)
	{
		if(ptr->data==data)
			{found=true;
			break;}
			else{
				if(data<ptr->data)
				{
					ptr=ptr->l;
				}
				else{
					ptr=ptr->r;
				}
			}
	}
	return found;
}

int iterative_findmin(node *ptr)
{
		if(!ptr)
		{
			cout<<"empty tree!!"<<endl;
			return -1;
		}
		else
		{
			while(ptr->l)
			{
				ptr=ptr->l;
			}
		}
		return ptr->data;
}

int recursive_findmin(node *ptr)
{
	if(!ptr)
	{
		cout<<"empty tree!!!"<<endl;
		return -1;
	}
	else{
		if(!(ptr->l))
		{
			return ptr->data;
		}
		else{
			return recursive_findmin(ptr->l);
		}
	}
}

int iterative_findmax(node *ptr)
{
	if(!ptr)
	{
		cout<<"empty tree!"<<endl;
		return -1;
	}
	else
	{
		while(ptr->r)
		{
			ptr=ptr->r;
		}
		return ptr->data;
	}
}

int recursive_findmax(node *ptr)
{
	if(!ptr)
	{
		cout<<"empty tree!"<<endl;
		return -1;
	}
	if(!ptr->r)
		return ptr->data;
	return recursive_findmax(ptr->r);
}

// functions returns the height of the specifed node
int height(node *ptr)
{
	if(!ptr)
	{
		return -1;
	}
	else{
		return max(height(ptr->l)+1, height(ptr->r)+1);
	}
}

// level order traversal.
void lot(node *ptr)
{
	if(!ptr)
	{
		cout<<"empty tree"<<endl;
		return;
	}
	else
	{
		cout<<"level order traversal..."<<endl;
		queue <node *> q;
		q.push(ptr);
		
		while(!q.empty())
		{
			node *pop= q.front();
			cout<<pop->data<<endl;
			if(pop->l)
			{
				q.push(pop->l);

			}
			if(pop->r)
			{
				q.push(pop->r);

			}
			q.pop();
		}
	}
	
}

void inorder(node *ptr)
{
	if(ptr)
	{
		inorder(ptr->l);
		cout<<ptr->data<<endl;
		inorder(ptr->r);
	}
}


void preorder(node *ptr)
{
	if(ptr)
	{
		cout<<ptr->data<<endl;
		preorder(ptr->l);
		preorder(ptr->r);
	}
}

void postorder(node *ptr)
{
	if(ptr)
	{
		postorder(ptr->l);
		postorder(ptr->r);
		cout<<ptr->data<<endl;
	}
}

int main()
{
	node *root=nullptr;
	recursive_insert(10, &root);
	recursive_insert(15, &root);
	recursive_insert(20, &root);
	iterative_insert(7, &root);
	iterative_insert(9, &root);
	iterative_insert(5, &root);
	recursive_insert(6, &root);
	recursive_insert(3, &root);

	
	recursive_inorder_traversal(root);
	cout<<"recursive_search(10, root): "<<(recursive_search(10,root)?"true":"false")<<endl;
	cout<<"recursive_search(13, root): "<<(recursive_search(13,root)?"true":"false")<<endl;
	cout<<"iterative_search(10, root): "<<(iterative_search(10,root)?"true":"false")<<endl;
	cout<<"iterative_search(13, root): "<<(iterative_search(13,root)?"true":"false")<<endl;
	cout<<"iterative_findmin(root): "<<iterative_findmin(root)<<endl;
	cout<<"recursive_findmin(root): "<<recursive_findmin(root)<<endl;
	cout<<"iterative_findmax(root): "<<iterative_findmax(root)<<endl;
	cout<<"recursive_findmax(root): "<<recursive_findmax(root)<<endl;
	cout<<"height(root): "<<height(root)<<endl;
	lot(root);
	cout<<"inorder traversal"<<endl;
	inorder(root);
	cout<<"preorder traversal"<<endl;
	preorder(root);
	cout<<"postorder traversal"<<endl;
	postorder(root);

	
	return 0;
}
