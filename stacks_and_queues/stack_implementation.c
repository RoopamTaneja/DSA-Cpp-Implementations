// stack implementation using array

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int stack[100];
int top;

bool stack_empty()
{
    if (top == -1)
        return true;
    return false;
}

void push(int x)
{
    top++;
    stack[top] = x;
}

void pop()
{
    if (stack_empty())
        printf("Empty stack can't be popped : underflow\n");
    else
    {
        printf("Popped element : %d\n", stack[top]);
        top--;
    }
}

void display()
{
    if (top >= 0)
    {
        printf("\n The elements in STACK \n");
        for (int i = top; i >= 0; i--)
            printf("\n%d", stack[i]);
        printf("\n Press Next Choice");
    }
    else
    {
        printf("\n The STACK is empty");
    }
}

int main()
{
    int choice, n, x;
    top = -1;
    printf("\n\t STACK OPERATIONS USING ARRAY");
    printf("\n\t--------------------------------");
    printf("\n\t 1.PUSH\n\t 2.POP\n\t 3.DISPLAY\n\t 4.EXIT");
    do
    {
        printf("\n Enter the Choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            printf(" Enter a value to be pushed:");
            scanf("%d", &x);
            push(x);
            break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
        {
            display();
            break;
        }
        case 4:
        {
            printf("\n\t EXIT POINT ");
            break;
        }
        default:
        {
            printf("\n\t Please Enter a Valid Choice(1/2/3/4)");
        }
        }
    } while (choice != 4);
    return 0;
}
