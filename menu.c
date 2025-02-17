#include <stdio.h>
  struct Book
  {
     int ID;
     char name[50];
     char author[50];
  }b[10];
  
  int i,num=0;
  
  void Insertbook(int n)
  {
      printf("Details About the Book\n");
      for(i=0;i<n;i++)
      {
         printf("Enter the Details About Book No.%d\n",num+1);
         printf("Enter the Book ID:\n");
         scanf("%d",&b[num].ID);
         printf("Enter the Book Name:\n");
         scanf("%s",b[num].name);
         printf("Enter the Name of Book Author:\n");
         scanf("%s",b[num].author);
         num++;
      }
      
     printf("Book Detalis Insert Sucssefully !");
   }  
   
   
  void Deletebook()
  {
    int position;
    
    printf("Enter the place Where you want to Delete\n");
    scanf("%d",&position); 
     for(i=position-1;i<num-1;i++)
     {
        b[i]=b[i+1];   
     }
     num--;
     printf("Delete details sucssesfully !");
     
 } 
 
  void Modifybook()
  {
    int position;
    
    printf("Enter the place Where you want to Modify\n");
    scanf("%d",&position); 
    
         printf("Enter the Book ID:\n");
         scanf("%d",&b[position-1].ID);
         printf("Enter the Book Name:\n");
         scanf("%s",b[position-1].name);
         printf("Enter the Name of Book Author:\n");
         scanf("%s",b[position-1].author);
         	
   } 
    
  void Displaybook()
   {
       printf("Ubdated details of Book\n");
       for(i=0;i<num;i++)
      {
       printf("The Book Id is %d\n",b[i].ID);
       printf("The Name of Book is %s\n",b[i].name);
       printf("The Name of Book Author is %s\n",b[i].author);
      }
   }  
    
  int main()
  {
     int choice;
     
     do{
           printf("\n---Book Managment Menu---\n");
           printf("1.Insert Book\n");
           printf("2.Delete Book\n");
           printf("3.Modify Book\n");
           printf("4.Display Book\n");
           printf("5.Exit the Program\n");
           printf("Enter your choice:");
           scanf("%d",&choice);
           switch(choice)
           {
             
             case 1: printf("How many Book Details you want to Insert\n");
                     int n;
                     scanf("%d",&n);
                    
                     Insertbook(n);
                     break;
                     
             case 2: Deletebook();
                     break;
             
             case 3: Modifybook();
                     break;
                     
             case 4: Displaybook();
                     break;
                     
             case 5: printf("\nExit the Program Sucssesfully !");
                     break;
                                              
             default:printf("Invalid choice");
             }
         } while(choice !=5);
           
        return 0;
     }
                     
                     
                     
                     
                     
                     
                     
                     
                     
                     
                     
                     
                     
                     
                     
                     
                     
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
