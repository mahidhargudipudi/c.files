#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *next;
}NODE;
NODE*head=NULL,*tail=NULL,*temp,*res,*dn;
void insert(NODE*NN)
{
	if(head==NULL && tail==NULL)
	{
		head=NN;
		tail=NN;
		tail->next=head;
	}
	else
	{
		tail->next=NN;
		tail=tail->next;
		tail->next=head;		
	}
}
NODE *deletee()
{
	temp=head;
	if(head==NULL && tail==NULL)
	{
		return NULL;
	}
	else if(head==tail)
	{
		dn=head;
		head=NULL;
		tail=NULL;
		return dn;	
	}
	else 
	{
		while(temp->next->next!=head)
		{
			temp=temp->next;
		}
		dn=temp->next;
		temp->next=head;
		tail=temp;
		return dn;	
	}
}
void display()
{
	temp=head;
	if(head==NULL && tail==NULL)
	{
		printf("NO NODES\n");
	}
	else
	{
		while(temp->next!=head)
		{
			printf("%d %d %d\n",temp,temp->data,temp->next);
			temp=temp->next;
		}
		printf("%d %d %d\n",temp,temp->data,temp->next);
	}
}
void insert_head(NODE*NN)
{
	if(head==NULL && tail==NULL)
	{
		head=NN;
		tail=NN;
		tail->next=head;
	}
	else
	{
		temp=head;
		NN->next=temp;
		head=NN;
		tail->next=head;
	}
}
NODE * delete_head()
{
	if(head==NULL&&tail==NULL)
	{
		return NULL;
	}
	else if (head==tail)
	{
		dn=head;
		head=NULL;
		tail=NULL;
		return dn;
	}	
	else 
	{
		dn=head;
		head=head->next;
		tail->next=head;
		return dn;
	}
}
void insert_pos(NODE*NN,int pos)
{
	temp=head;
	for(int p=1;p<pos-1;p++)
	{
		if(temp->next==head)
		{
			printf("INSERTION IS NOT POSIIBLE\n");
			return;
		}
		temp=temp->next;
	}
	NN->next=temp->next;
	temp->next=NN;
}
NODE * delete_pos(int pos)
{
	temp=head;
	if(head==NULL && tail==NULL)
	{
		return NULL;
	}
	else
	{
		for(int p=1;p<pos-1;p++)
		{
			if(temp->next==head)
			{
				return NULL;
			}
			temp=temp->next;
		}
		dn=temp->next;
		temp->next=dn->next;
		dn->next=NULL;
		return dn;
	}
}
int main()
{
	int ch,val,pos;
	while(1)
	{
		printf("1.insert 2.delete 3. display 4. insert_head 5.delete_head 6.insert_pos 7.delete_pos");
		scanf("%d",&ch);
		if(ch==1)
		{
			NODE*NN=(NODE*)malloc(sizeof(NODE));
			scanf("%d",&val);
			NN->next=NULL;
			NN->data=val;
			insert(NN);
		}
		else if(ch==2)
		{
			res=deletee();
			if(res==NULL)
			{
				printf("NO NODES\n");
			}
			else
			{
				printf("%d\n",res->data);
				free(res);
			}
		}
		else if(ch==3)
		{
			display();
		}
		else if(ch==4)
		{
			NODE*NN=(NODE*)malloc(sizeof(NODE));
			scanf("%d",&val);
			NN->next=NULL;
			NN->data=val;
			insert_head(NN);
		}
		else if (ch==5)
		{
			res=delete_head();
			if(res==NULL)
			{
				printf("NO NODES\n");
			}
			else
			{
				printf("%d\n",res->data);
			}
		}
		else if(ch==6)
		{
			NODE*NN=(NODE*)malloc(sizeof(NODE));
			scanf("%d",&pos);
			scanf("%d",&val);
			NN->next=NULL;
			NN->data=val;
			insert_pos(NN,pos);
		}
		else if(ch==7)
		{
			scanf("%d",&pos);
			res=delete_pos(pos);
			if(res==NULL)
			{
				printf("DELETION NOT POSSIBLE\n");
			}
			else 
			{
				printf("%d \n",res->data);
				free(res);
			}
		}
		else 
		{
			break;
		}
	}
	
}