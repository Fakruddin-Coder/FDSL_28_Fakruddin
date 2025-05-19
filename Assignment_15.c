#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *temp,*front=NULL,*rear=NULL,*temp,*newnode;

void enQueue(int value)
{
	newnode = malloc(sizeof(struct node));
	newnode->data=value;
	if(rear == NULL)
	{
		front = rear = newnode;
		newnode->next = NULL;
	}
	else
	{
		temp = rear;
		while(temp->next!=NULL)
		{
			temp = temp->next;
		}
		temp->next=newnode;
		newnode->next = NULL;
	}
}
void deQueue()
{
	temp = front;
	if(temp==NULL)
	{
		printf("Queue is empty\n");
	}
	else
	{
		front=front->next;
		temp->next=NULL;
		free(temp);
	}
}
void display()
{	
	temp=front;
	if(temp==NULL)
	{
		printf("Queue is empty");
	}
	else
	{
	
		printf("\nQueue Elements : \n");
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
		printf("\n1. enQueue\n2. deQueue\n3. Display\n4. Exit\nEnter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 :
				printf("Enter Data : ");
				scanf("%d",&value);
				enQueue(value);
				break;
			case 2 : deQueue();
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