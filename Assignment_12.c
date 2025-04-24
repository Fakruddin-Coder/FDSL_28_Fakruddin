#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head, *temp, *newnode;

void main()
{
    int choice;
    head = NULL;
    do
    {
        newnode = malloc(sizeof(struct node));
        printf("Enter the data : ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if (head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        printf("Do you want to continue (1/0) : ");
        scanf("%d", &choice);
    } while (choice != 0);
    temp = head;
    printf("Linked List : \n");
    while (temp != NULL)
    {
        printf("Data : %d at address %p\n", temp->data, temp);
        temp = temp->next;
    }
}