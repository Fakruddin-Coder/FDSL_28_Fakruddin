#include <stdio.h>

struct Mark {
    char subject[50];
    int mark;
    int age;
} M[10];

int n;

void insert() {   
    int i;

    printf("Enter how many details you want to store:\n");
    scanf("%d", &n);

    printf("Enter the Details\n");
    for (i = 0; i < n; i++) {
        printf("Enter Subject Name: ");
        scanf("%s", M[i].subject);
        printf("Enter the Marks: ");
        scanf("%d", &M[i].mark);
        printf("Enter the Age: ");
        scanf("%d", &M[i].age);
    }
    printf("Details Inserted Successfully\n");
}

void marksort() {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (M[j].mark < M[j + 1].mark) {
                struct Mark temp = M[j];
                M[j] = M[j + 1];
                M[j + 1] = temp;
            }
        }
    }
    printf("Details Sorted According to Marks\n");
}

void Agesort() {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (M[j].age < M[j + 1].age) {
                struct Mark temp = M[j];
                M[j] = M[j + 1];
                M[j + 1] = temp;
            }
        }
    }
    printf("Details Sorted According to Age\n");
}

void Display() {
    int i;
    printf("\n---------------------------------------\n");
    printf("| %-15s | %-10s | %-5s |\n", "Subject", "Marks", "Age");
    printf("---------------------------------------\n");

    for (i = 0; i < n; i++) {
        printf("| %-15s | %-10d | %-5d |\n", M[i].subject, M[i].mark, M[i].age);
    }
    
    printf("---------------------------------------\n");
}

int main() {
    int choice;

    do {
        printf("\n------ Sorted Details ------\n");
        printf("1. Insert Details\n2. Sort by Marks\n3. Sort by Age\n4. Display Details\n5. Exit Program\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                marksort();
                break;
            case 3:
                Agesort();
                break;
            case 4:
                Display();
                break;
            case 5:
                printf("\nExiting the program!\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);

    return 0;
}
