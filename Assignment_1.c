#include <stdio.h>
#include <string.h>

struct Book
{
    int ID;
    char name[50];
    char author[50];
} b[10];

int i, num = 0;

void Insertbook(int n)
{
    printf("Details About the Book\n");
    for (i = 0; i < n; i++)
    {
        if (num >= 10)
        {
            printf("Cannot insert more books. Maximum limit reached.\n");
            return;
        }

        printf("Enter the Details About Book No.%d\n", num + 1);
        printf("Enter the Book ID:\n");
        scanf("%d", &b[num].ID);
        printf("Enter the Book Name:\n");
        scanf("%49s", b[num].name);
        printf("Enter the Name of Book Author:\n");
        scanf("%49s", b[num].author);
        num++;
    }

    printf("Book Details Inserted Successfully!\n");
}

void Deletebook()
{
    int position;

    printf("Enter the position Where you want to Delete (1 to %d):\n", num);
    scanf("%d", &position);

    if (position < 1 || position > num)
    {
        printf("Invalid position!\n");
        return;
    }

    for (i = position - 1; i < num - 1; i++)
    {
        b[i] = b[i + 1];
    }

    num--;
    printf("Deleted details successfully!\n");
}

void Modifybook()
{
    int position, ch;

    printf("Enter the position Where you want to Modify (1 to %d):\n", num);
    scanf("%d", &position);

    if (position < 1 || position > num)
    {
        printf("Invalid position!\n");
        return;
    }

    printf("1. Modify the ID:\n2. Modify the Name\n3. Modify the Author Name\n");
    printf("Enter your Choice:\n");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
        printf("Enter the Book ID:\n");
        scanf("%d", &b[position - 1].ID);
        break;
    case 2:
        printf("Enter the Book Name:\n");
        scanf("%49s", b[position - 1].name);
        break;
    case 3:
        printf("Enter the Name of Book Author:\n");
        scanf("%49s", b[position - 1].author);
        break;
    default:
        printf("Invalid choice\n");
    }

    printf("Modified details successfully!\n");
}

void Displaybook()
{
    if (num == 0)
    {
        printf("No books to display!\n");
        return;
    }

    printf("Updated details of Books\n");
    for (i = 0; i < num; i++)
    {
        printf("The Book ID is %d\n", b[i].ID);
        printf("The Name of the Book is %s\n", b[i].name);
        printf("The Name of the Book Author is %s\n", b[i].author);
    }
}

void InsertNewBook()
{
    int position;
    struct Book Newbook;

    printf("Enter Details About the New Book\n");
    printf("Enter the New Book ID:\n");
    scanf("%d", &Newbook.ID);
    printf("Enter the Book Name:\n");
    scanf("%49s", Newbook.name);
    printf("Enter the Name of Book Author:\n");
    scanf("%49s", Newbook.author);

    printf("Enter your choice where You Want to store (1 to %d):\n", num + 1);
    scanf("%d", &position);

    if (position < 1 || position > num + 1)
    {
        printf("Invalid position!\n");
        return;
    }

    if (num >= 10)
    {
        printf("Cannot insert more books. Maximum limit reached.\n");
        return;
    }

    for (i = num; i >= position; i--)
    {
        b[i] = b[i - 1];
    }

    b[position - 1] = Newbook;
    num++;

    printf("New Book Details Inserted Successfully!\n");
}

int main()
{
    int choice;

    do
    {
        printf("\n---Book Management Menu---\n");
        printf("1. Insert Book\n");
        printf("2. Delete Book\n");
        printf("3. Modify Book\n");
        printf("4. Display Book\n");
        printf("5. Insert New Book\n");
        printf("6. Exit the Program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("How many Book Details you want to Insert: ");
            int n;
            scanf("%d", &n);

            Insertbook(n);
            break;

        case 2:
            Deletebook();
            break;

        case 3:
            Modifybook();
            break;

        case 4:
            Displaybook();
            break;

        case 5:
            InsertNewBook();
            break;

        case 6:
            printf("\nExit the Program Successfully!\n");
            break;

        default:
            printf("Invalid choice\n");
        }
    } while (choice != 6);

    return 0;
}
