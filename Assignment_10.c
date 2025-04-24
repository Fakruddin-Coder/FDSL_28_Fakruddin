#include <stdio.h>
#define max 20

int q[max];
int front = -1, rear = -1;

void enQueue(int element)
{
    if (rear == max - 1)
    {
        printf("Queue is full!\n");
    }
    else
    {
        rear++;
        q[rear] = element;
    }
}

void deQueue()
{
    if (front == rear)
    {
        printf("Queue is empty!\n");
    }
    else
    {
        front++;
        printf("Element deleted is %d\n", q[front]);
    }
}

void display()
{
    if (front == rear)
    {
        printf("Queue is empty!\n");
    }
    else
    {
        printf("\nQueue elements: ");
        for (int i = front + 1; i <= rear; i++)
        {
            printf("%d ", q[i]);
        }
        printf("\n");
    }
}

int main()
{
    int c;
    int choice;
    int d;
    do
    {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter element : ");
            scanf("%d", &c); 
            enQueue(c);
            break;
        case 2:
            deQueue();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice!\n");
        }
        printf("Do you want to continue (1/0) ?: ");
        scanf("%d", &d);
    } while (d != 0);

    return 0;
}
