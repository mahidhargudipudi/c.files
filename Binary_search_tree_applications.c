#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node *left;
	struct Node *right;
};
typedef struct Node NODE;
NODE *root=NULL,*temp,*par,*NN,*res;

NODE *newnode(int val)
{
	NN=(NODE*)malloc(sizeof(NODE));
	NN->data=val;
	NN->right=NULL;
	NN->left=NULL;
	return NN;
}

void inorder(NODE *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}

void preorder(NODE *root)
{
	if(root!=NULL)
	{
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(NODE *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->data);
	}
}

int search(int key)
{
	temp=root;
	if (root==NULL)
		{
			return 0;
		}
	while(temp)
	{
		if(temp->data==key)
		{
			return 1;
		}
		else if (temp->data>key)
		{
			temp=temp->left;
		}
		else if (temp->data<key)
		{
			temp=temp->right;
		}
	}
	return 0;
}
void insert(int val)
{
	NN=newnode(val);
	temp=root;
	if(temp==NULL)
	{
		root=NN;
		return;
	}
	while(1)
	{	
		if(temp->data==NN->data)
		{
			printf("Element is already in the Tree\n");
			return;
		}
		else if (temp->data>NN->data)
		{
		   if(temp->left!=NULL)
			{
				temp=temp->left;
			}				
			else 
			{
				temp->left=NN;
				return;
			}
		}
		else if (temp->data<NN->data)
		{
			if(temp->right!=NULL)
			{
				temp=temp->right;
			}
			else 
			{
				temp->right=NN;
				return;
			}
		}
	}
}
NODE *del(int key)
{
	if(root==NULL)
	{
		return NULL;
	}
	temp=root;
	par=NULL;
	while(temp && temp->data!=key)
	{
		if(temp->data > key)
		{
			par=temp;
			temp=temp->left;
		}
		else if (temp->data< key)
		{
			par=temp;
			temp=temp->right;
		}
	}
	if(temp==NULL)
	{
		return NULL;
	}
	if(temp->left==NULL && temp->right==NULL)
	{
//		zero child
		res=temp;
		if(par->right!=NULL && par->right->data==key)
		{
			par->right=NULL;
		}
		else if (par->left!=NULL && par->left->data==key)
		{
			par->left=NULL;
		}
		return res;
	}
	else if(temp->left==NULL)
	{
//		single child right 
		res=temp;
		if(par->left!=NULL && par->left->data==key)
		{
			par->left=temp->right;
		}
		else if(par->right!=NULL && par->right->data==key)
		{
			par->right=temp->right;
		}
		return res;
	}
	else if(temp->right==NULL)
	{
//		single child left
		res=temp;
		if(par->left!=NULL && par->left->data==key)
		{
			par->left=temp->left;
		}
		else if(par->left!=NULL && par->left->data==key)
		{
			par->left=temp->right;
		}
		return res;
	}
	else if(temp->left!=NULL && temp->right!=NULL)
	{
//		two child
		NODE *p=NULL,*t=temp->right;
		int val;
		while(t->left)
		{
			p=t;
			t=t->left;
		}
		if(p!=NULL)
		{
			res=t;
			val=t->data;
			t->data=temp->data;
			temp->data=val;
			p->left=t->right;
			return res;
		}
		else 
		{
			res=t;
			val=t->data;
			t->data=temp->data;
			temp->data=val;
			temp->right=t->right;
			return res;
		}
	}
}

int main()
{
	int ch,val,key,n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&val);
		insert(val);
	}
	while(1)
	{
		printf("1.insert 2.delete 3.search 4.inorder 5.preorder 6.postorder 7.level_order 8.exit");
		scanf("%d",&ch);
		if(ch==1)
		{
		scanf("%d",&val);
		insert(val);
		}
		else if(ch==2)
		{
			//delete
			scanf("%d",&key);
			res=del(key);
			if(res)
			{
			printf("%d\n",res->data);
			free(res);
			}
			else 
			{
				printf("Element is not found\n");
			}
		}
		else if (ch==3)
		{
			scanf("%d",&key);
			if(search(key))
			{
				printf("Element found\n");
			}
			else 
			{
				printf("ELement not found\n");
			}
		}
		else if (ch==4)
		{
			inorder(root);
			printf("\n");
		}
		else if (ch==5)
		{
			preorder(root);
			printf("\n");
		}
		else if (ch==6)	
		{
			postorder(root);
			printf("\n");
		}
		else if (ch==7)
		{
//			levelorder(root)
		}
		else 
		{
			break;
		}
}
}
/*
13
50 40 80 30 45 70 90 25 35 42 48 65 100
*/