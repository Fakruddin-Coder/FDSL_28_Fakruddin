#include <stdio.h>

#define MAX 100  

int Stack[MAX];  
int i = -1;      

void push() {
    int x;
    printf("Enter the Element: ");
    scanf("%d", &x);

    if (i == MAX - 1) {
        printf("Overflow!\n");
    } else {
        i++;
        Stack[i] = x;
        printf("Pushed %d into the stack.\n", x);
    }
}

void pop() {
    if (i == -1) {
        printf("Underflow!\n");
    } else {
        printf("Popped element: %d\n", Stack[i]);
        i--;
    }
}

void Display() {
    if (i == -1) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements: ");
    for (int j = i; j >= 0; j--) {
        printf("%d ", Stack[j]);
    }
    printf("\n");
}

int main() {
    int choice;

    do {
        printf("\n1. Push Element\n");
        printf("2. Pop Element\n");
        printf("3. Display Stack\n");
        printf("4. Exit\n");
        printf("Enter your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                Display();
                break;
            case 4:
                printf("Exiting the program!\n");
                break;
            default:
                printf("Enter a correct choice!\n");
        }
    } while (choice != 4);

    return 0;
}