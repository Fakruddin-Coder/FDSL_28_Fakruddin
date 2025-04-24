#include <stdio.h>

int a[100], n;

void Insert()  
{  
    int i;  

    printf("Enter the Size:\n");    
    scanf("%d", &n);    

    printf("Enter Array Element:\n");  
    for(i = 0; i < n; i++)  
    {  
        scanf("%d", &a[i]);  
    }  
    printf("Array Accept Successfully !\n");
}

void Bubblesort()  
{  
    int i, j;  

    for(i = 0; i < n - 1; i++)  
    {  
        for(j = 0; j < n - i - 1; j++)  
        {  
            if(a[j] > a[j + 1])  
            {  
                int tem = a[j];  
                a[j] = a[j + 1];  
                a[j + 1] = tem;  
            }  
        }  
    }  
    printf("Array Sorted by Bubble Sort Successfully !\n");
}  

void Selectionsort()  
{  
    int i, j;  

    for(i = 0; i < n; i++)  
    {  
        for(j = i + 1; j < n; j++)  
        {  
            if(a[j] < a[i])  
            {  
                int tem = a[j];  
                a[j] = a[i];  
                a[i] = tem;  
            }  
        }  
    }  
    printf("Array Sorted by Selection Sort Successfully !\n");
}  

void Insertionsort()  
{  
    int i, j, key;  

    for(i = 1; i < n; i++)  
    {  
        key = a[i];  
        j = i - 1;  

        while(j >= 0 && a[j] > key)  
        {  
            a[j + 1] = a[j];  
            j = j - 1;  
        }  
        a[j + 1] = key;  
    }  
    printf("Array Sorted by Insertion Sort Successfully !\n");
}  

void Linearsearch()  
{  
    int key, i, found = 0;  

    printf("Enter the Element that you want search:\n");    
    scanf("%d", &key);  

    for(i = 0; i < n; i++)  
    {  
        if(a[i] == key)  
        {  
            printf("Element is %d Found.\n", key);  
            found = 1;  
            break;  
        }  
    }  
    if(!found)  
    {  
        printf("Element not Found !\n");  
    }  
    printf("Array Searched by Linear Search Successfully !\n");
}  

void Binarysearch()  
{  
    int key, low = 0, high = n - 1, mid;  

    printf("Enter Key:\n");  
    scanf("%d", &key);  

    while(low <= high)  
    {  
        mid = (low + high) / 2;  

        if(key == a[mid])  
        {  
            printf("Element %d is Found.\n", key);  
            return;  
        }  
        else if (key < a[mid])  
        {  
            high = mid - 1;  
        }  
        else  
        {  
            low = mid + 1;  
        }  
    }  

    printf("Element Not Found.\n");  
    printf("Array Searched by Binary Search Successfully !\n");
}  

int main()  
{  
    int choice;  

    do  
    {   
        printf("1. Insert Array.\n");    
        printf("2. Sort by Bubble Sort.\n");    
        printf("3. Sort by Selection Sort.\n");    
        printf("4. Sort by Insertion Sort.\n");    
        printf("5. Search by Linear Search.\n");    
        printf("6. Search by Binary Search.\n");    
        printf("7. Exit\n");    
        printf("Enter the Choice...\n");    
        scanf("%d", &choice);    

        switch(choice)    
        {    
            case 1:    
                Insert();    
                break;    

            case 2:      
                Bubblesort();    
                break;    

            case 3:    
                Selectionsort();    
                break;    

            case 4:    
                Insertionsort();    
                break;    

            case 5:    
                Linearsearch();    
                break;    

            case 6:    
                Binarysearch();    
                break;    

            case 7:    
                printf("Exit....\n");    
                break;    

            default:  
                printf("Invalid Choice! Please try again.\n");  
        }    
    } while(choice != 7);    

    return 0;  
}
