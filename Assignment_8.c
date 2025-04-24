#include<stdio.h>
#define n 100
int s[n];
int top = -1;

void push(int q)
{
    if(top == n-1)
    {
        printf("Stack Overflow !\n");
    }
    else 
    {
        top++;
        s[top]=q;
    }
}
void display()
{   
    int i;
    if(top == -1)
    {
        printf("Stack Underflow !\n");
    }
    else
    {
        printf("Binary Number : ");
        for( i = top ; i>=0 ; i--)
        {
            printf("%d",s[i]);
        }
    }
}
int main()
{
    int q;
    int d;
    printf("Enter Decimal Number : ");
    scanf("%d",&d);
    while(d>0)
    {
        q = d%2;
        d/=2;
        push(q);
    }
    display();

}