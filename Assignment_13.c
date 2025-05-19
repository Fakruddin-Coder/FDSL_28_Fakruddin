#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
	struct node *prev;
};

struct node *temp,*head,*prevnode,*newnode;

void insertatfirst()
{
	newnode=malloc(sizeof(struct node));
	printf("Enter data : ");
	scanf("%d",&newnode->data);
	if(head==NULL)
	{
		head=newnode;
		newnode->next=NULL;
		newnode->prev=NULL;
	}
	else
	{	
		newnode->next=head;
		head->prev=newnode;
		head=newnode;
		newnode->prev=NULL;
	}
}

void insertatlast()
{
	newnode=malloc(sizeof(struct node));
	printf("Enter data : ");
	scanf("%d",&newnode->data);
	if(head==NULL)
	{
		head=newnode;
		head->next=NULL;
		newnode->prev=NULL;
	}
	else
	{
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		newnode->next=NULL;
		temp->next=newnode;
		newnode->prev=temp;
	}
}

void insertatpos()
{
	int pos,i=1,count=0;
	printf("Enter the position : ");
	scanf("%d",&pos);
	temp=head;
	while(temp->next!=NULL)
	{
		count++;
		temp=temp->next;
	}
	if(pos<1 || pos>count)
	{
		printf("Position out of range");
	}
	else
	{	
		newnode=malloc(sizeof(struct node));
		printf("Enter data : ");
		scanf("%d",&newnode->data);
		i=1;
		temp=head;
		while(i<pos)
		{
			prevnode=temp;
			temp=temp->next;
			i++;
		}
		newnode->next=temp;
		temp->prev=newnode;
		prevnode->next=newnode;
		newnode->prev=prevnode;
	}
}

void deletefirst()
{
	if(head==NULL)
	{
		printf("DLL is empty");
	}
	else if(head->next==NULL)
	{
		temp=head;
		head=NULL;
		free(temp);
	}
	else
	{
		temp=head;
		head=head->next;
		head->prev=NULL;
		temp->next=NULL;
		free(temp);
	}
}

void deletelast()
{
	temp=head;
	while(temp->next!=NULL)
	{
		prevnode=temp;
		temp=temp->next;
	}
	if(head==NULL)
	{
		printf("DLL is empty");
	}
	else if(head==temp)
	{
		head=NULL;
		free(temp);
	}
	else
	{
		prevnode->next=NULL;
		temp->prev=NULL;
		free(temp);
	}
}

void deleteatpos()
{
	int i=1,count=0,pos;
	printf("Enter position : ");
	scanf("%d",&pos);
	temp=head;
	while(temp->next!=NULL)
	{
		count++;
		temp=temp->next;
	}
	if(pos<1 || pos>count)
	{
		printf("Position out of range");
	}
	else if(pos==1)
	{
		deletefirst();
	}
	else
	{	temp=head;
		i=1;
		while(i<pos)
		{
			prevnode=temp;
			temp=temp->next;
			i++;
		}
		prevnode->next=temp->next;
		temp->next->prev=prevnode;
		temp->prev=NULL;
		temp->next=NULL;
		free(temp);
	}
}

void display()
{
	if(head==NULL)
	{
		printf("Linked list is empty");
	}
	else
	{
		temp=head;
		printf("\nDoubly linked list : \n");
		while(temp!=NULL)
		{
		printf("%d present at %p\n",temp->data,temp);
		temp=temp->next;
		}
	}
}
			
void main()
{
	int choice;
	while(1)
	{
	printf("\n1. Insert At first\n2. Insert At last\n3. Insert At Position\n4. Delete first\n5. Delete last\n6. Delete At Position\n7. Display\n8. Exit\nEnter your choice : ");
	scanf("%d",&choice); 	
	switch(choice)
	{
		case 1 : insertatfirst();
			break;
		case 2 : insertatlast();
			break;
		case 3 : insertatpos();	
			break;
		case 4 : deletefirst();
			break;
		case 5 : deletelast();
			break;
		case 6 : deleteatpos();
			break;
		case 7 : display();
			break;
		case 8 : return;
		
		default : printf("Invalid choice");
	}
}

}