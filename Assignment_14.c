#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *top=NULL,*temp,*newnode;

void push(int value)
{
	newnode = malloc(sizeof(struct node));
	newnode->data=value;
	if(top==NULL)
	{
		top= newnode;
		newnode->next = NULL;
	}
	else
	{
		newnode->next =top;
		top=newnode;
	}
}
void pop()
{
	if(top==NULL)
	{
		printf("Stack is Empty\n");
	}
	else
	{
		temp = top;
		top=top->next;
		temp->next=NULL;
		free(temp);
	}	
}

void display()
{
	if(top==NULL)
	{
		printf("Stack is empty");
	}
	else
	{
		temp=top;
		printf("\nStack Elements : \n");
		while(temp!=NULL)
		{
		printf("%d present at %p\n",temp->data,temp);
		temp=temp->next;
		}
	}
}

int main()
{
	int value,choice;
	while(1)
	{
		printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 :
				printf("Enter Data : ");
				scanf("%d",&value);
				push(value);
				break;
			case 2 : pop();
				break;
			case 3 : display();
				break;
			case 4 : 
				printf("Exiting Program......\n");
				return 0;
				
			default : printf("Invalid Choice");
				break;
		}
	}
	return 0;
}