#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *temp,*head,*newnode,*prevnode;

void insertatfirst()
{
    newnode=malloc(sizeof(struct node));
    printf("Enter Data : ");
    scanf("%d",&newnode->data);
    if(head==NULL)
    {
        head=newnode;
        newnode->next=NULL;
        
    }
    else
    {
        newnode->next=head;
        head=newnode;
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
        newnode->next=NULL;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=NULL;
    }
}

void insertafter()
{
    int pos;
    int count=0;
    int i;
    printf("After which position u want to insert? : ");
    scanf("%d",&pos);
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
        count++;
    }
    if(pos<1 || pos>count)
    {
        printf("Invalid Position\n");
    }
    else
    {
        newnode=malloc(sizeof(struct node));
        printf("Enter data : ");
        scanf("%d",&newnode->data);
        temp=head;
        while(i<pos)
        {
            temp=temp->next;
            i++;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
}

void deletefirst()
{
    if(head==NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        temp=head;
        head=head->next;
        temp->next=NULL;
        free(temp);
    }
}

void deletelast()
{
    if(head==NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            prevnode=temp;
            temp=temp->next;
        }
        prevnode->next=NULL;
    }
}

void display()
{
    temp=head;
    if(head==NULL)
    {
        printf("Singly List is empty\n");
    }
    else{
    printf("Singly Linked List : ");
    while(temp!=NULL)
    {
        printf("%d at %p\n",temp->data,temp);
        temp=temp->next;
    }
}
}

int main()
{
    int choice;
    while(1)
    {
        printf("1. Insert at first\n");
        printf("2. Insert at last\n");
        printf("3. Insert After\n");
        printf("4. Delete first\n");
        printf("5. Delete last\n");
        printf("6. Display\n");
        printf("7. Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
    switch(choice)
    {
        case 1 : insertatfirst();
            break;
        case 2 : insertatlast();
            break;
        case 3 : insertafter();
            break;
        case 4 : deletefirst();
            break;
        case 5 : deletelast();
            break;
        case 6 : display();
            break;
        case 7 : return 0;
        default : printf("Invalid Choice\n");
    }
}
    return 0;
}
