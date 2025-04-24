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
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (s[j].Age > s[j + 1].Age)
            {
                struct soldier temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
    printf("Sorted by Age Successfully!\n");
}

void Missionsort()
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (s[j].Mission > s[j + 1].Mission)
            {
                struct soldier temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
    printf("Sorted by Missions Successfully!\n");
}

void Namesort()
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (strcasecmp(s[j].Name, s[j + 1].Name) > 0)
            {
                struct soldier temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
    printf("Sorted by Name Successfully!\n");
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
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (getposition(s[j].Rank) > getposition(s[j + 1].Rank))
            {
                struct soldier temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
    printf("Sorted by Rank Successfully!\n");
}

void SearchByAge()
{
    int age, found = 0;
    printf("Enter Age to Search: ");
    scanf("%d", &age);
    
    for (int i = 0; i < n; i++)
    {
        if (s[i].Age == age)
        {
            printf("Soldier Found: %s (%s, %s, %d Missions, %d Years Old)\n", 
                   s[i].Name, s[i].Code, s[i].Rank, s[i].Mission, s[i].Age);
            found = 1;
        }
    }
    if (!found)
        printf("No soldier found with Age %d\n", age);
}

void SearchByName()
{
    char name[50];
    int found = 0;
    printf("Enter Name to Search: ");
    scanf(" %[^\n]", name);
    
    for (int i = 0; i < n; i++)
    {
        if (strcasecmp(s[i].Name, name) == 0)
        {
            printf("Soldier Found: %s (%s, %s, %d Missions, %d Years Old)\n", 
                   s[i].Name, s[i].Code, s[i].Rank, s[i].Mission, s[i].Age);
            found = 1;
        }
    }
    if (!found)
        printf("No soldier found with Name %s\n", name);
}

void SearchByMission()
{
    int mission, found = 0;
    printf("Enter Number of Missions to Search: ");
    scanf("%d", &mission);
    
    for (int i = 0; i < n; i++)
    {
        if (s[i].Mission == mission)
        {
            printf("Soldier Found: %s (%s, %s, %d Missions, %d Years Old)\n", 
                   s[i].Name, s[i].Code, s[i].Rank, s[i].Mission, s[i].Age);
            found = 1;
        }
    }
    if (!found)
        printf("No soldier found with %d Missions\n", mission);
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
        printf("1. Insert Details\n");
        printf("2. Sort by Age\n");
        printf("3. Sort by Missions\n");
        printf("4. Sort by Rank\n");
        printf("5. Sort by Name\n");
        printf("6. Search by Age\n");
        printf("7. Search by Name\n");
        printf("8. Search by Missions\n");
        printf("9. Display Details\n");
        printf("10. Exit\n");
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
            SearchByAge();
            break;
        case 7:
            SearchByName();
            break;
        case 8:
            SearchByMission();
            break;
        case 9:
            Display();
            break;
        case 10:
            printf("\nExiting program. Goodbye!\n");
            break;
        default:
            printf("\nInvalid choice! Please try again.\n");
        }
    } while (choice != 10);

    return 0;
}
