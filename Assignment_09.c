#include<stdio.h>
#include<string.h>
#define max 10
int stack[max];
int top = -1;

void push(char c) {
    if (top == max - 1) {
        printf("Stack is full\n");
        return;
    }
    top++;
    stack[top] = c;
}

void pop() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    top--;
}

void check(char str[]) {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            push(str[i]);
        }
        if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
            if (top == -1 || (str[i] == ')' && stack[top] != '(') ||
                (str[i] == ']' && stack[top] != '[') ||
                (str[i] == '}' && stack[top] != '{')) {
                printf("Invalid string\n");
                return;
            }
            pop();
        }
    }
    if (top == -1) {
        printf("Valid string\n");
    } else {
        printf("Invalid string\n");
    }
}

int main() {
    char str[10];
    printf("Enter the Expression: ");
    scanf("%9s", str);
    check(str);
    return 0;
}
