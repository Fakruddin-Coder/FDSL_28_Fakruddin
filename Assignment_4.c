#include <stdio.h>
#include <string.h>

struct soldier
{
    char Code[20];
    char Name[50];
    char Rank[20];
    int Mission;
    int Age;
} s[10];

int n;

void Insert()
{
    printf("How Many Soldier Details Want To Insert:\n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("\nSoldier %d:\n", i + 1);
        printf("Soldier Code: \n");
        scanf("%s", s[i].Code);
        printf("Name: \n");
        scanf(" %[^\n]", s[i].Name);
        printf("Rank: \n");
        scanf("%s", s[i].Rank);
        printf("Missions: \n");
        scanf("%d", &s[i].Mission);
        printf("Age: \n");
        scanf("%d", &s[i].Age);
    }
    printf("Details Inserted Successfully!\n");
}

void Agesort()
{
    for (int i = 1; i < n; i++)
    {
        struct soldier key = s[i];
        int j;
        for (j = i - 1; j >= 0 && s[j].Age > key.Age; j--)
        {
            s[j + 1] = s[j];
        }
        s[j + 1] = key;
    }
    printf("According to Age, Details Sorted Successfully!\n");
}

void Missionsort()
{
    for (int i = 1; i < n; i++)
    {
        struct soldier key = s[i];
        int j;
        for (j = i - 1; j >= 0 && s[j].Mission > key.Mission; j--)
        {
            s[j + 1] = s[j];
        }
        s[j + 1] = key;
    }
    printf("According to Mission, Details Sorted Successfully!\n");
}

void Namesort()
{
    for (int i = 1; i < n; i++)
    {
        struct soldier key = s[i];
        int j;
        for (j = i - 1; j >= 0 && strcasecmp(s[j].Name, key.Name) > 0; j--)
        {
            s[j + 1] = s[j];
        }
        s[j + 1] = key;
    }
    printf("According to Alphabetical Order of Name, Details Sorted Successfully!\n");
}

int getposition(char Rank[])
{
    if (strcmp(Rank, "General") == 0)
        return 1;
    if (strcmp(Rank, "Colonel") == 0)
        return 2;
    if (strcmp(Rank, "Major") == 0)
        return 3;
    if (strcmp(Rank, "Captain") == 0)
        return 4;
    if (strcmp(Rank, "Lieutenant") == 0)
        return 5;
    return 6;
}

void Ranksort()
{
    for (int i = 1; i < n; i++)
    {
        struct soldier key = s[i];
        int j;
        for (j = i - 1; j >= 0 && getposition(s[j].Rank) > getposition(key.Rank); j--)
        {
            s[j + 1] = s[j];
        }
        s[j + 1] = key;
    }
    printf("According to Rank, Details Sorted Successfully!\n");
}

void Display()
{
    printf("*************************|Soldier Details |************************\n");
    printf("-------------------------------------------------------------------\n");
    printf("| %-12s | %-15s | %-12s | %-8s | %-4s |\n", "Code", "Name", "Rank", "Missions", "Age");
    printf("-------------------------------------------------------------------\n");

    for (int i = 0; i < n; i++)
    {
        printf("| %-12s | %-15s | %-12s | %-8d | %-4d |\n", s[i].Code, s[i].Name, s[i].Rank, s[i].Mission, s[i].Age);
    }
    printf("-------------------------------------------------------------------\n");
}

int main()
{
    int choice;

    do
    {
        printf("\n--- Army Camp Management System ---\n");
        printf("1. Insert Details.\n");
        printf("2. Sort Details According to Age.\n");
        printf("3. Sort Details According to Mission.\n");
        printf("4. Sort Details According to Rank.\n");
        printf("5. Sort Details According to Alphabet.\n");
        printf("6. Display Details\n");
        printf("7. Exit the program.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            Insert();
            break;
        case 2:
            Agesort();
            break;
        case 3:
            Missionsort();
            break;
        case 4:
            Ranksort();
            break;
        case 5:
            Namesort();
            break;
        case 6:
            Display();
            break;
        case 7:
            printf("\nExiting program. Goodbye!\n");
            break;
        default:
            printf("\nInvalid choice! Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}