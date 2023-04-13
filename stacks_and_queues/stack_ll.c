#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int value;
    struct node *next;
} stack;
stack *top = NULL;
void create(stack **top)
{
    *top = NULL;
    /* top points to NULL,
    indicating empty stack */
}
void push(stack **top, int element)
{
    stack *temp;
    temp = (stack *)malloc(sizeof(stack));
    if (temp == NULL) // ie we can't allocate more space on heap
    {
        printf("\n Stack is full");
        return;
    }
    temp->value = element;
    temp->next = *top;
    *top = temp;
}
int pop(stack **top)
{
    int t;
    stack *p;
    if (*top == NULL)
    {
        printf("\n Stack is empty");
        return 0;
    }
    else
    {
        t = (*top)->value;
        p = *top;
        *top = (*top)->next;
        free(p);
        return t;
    }
}
int isempty(stack *top)
{
    if (top == NULL)
        return (1);
    else
        return (0);
}

int main()
{
    stack *A, *B;
    create(&A);
    create(&B);
    push(&A, 10);
    push(&A, 20);
    push(&A, 30);
    push(&B, 100);
    push(&B, 5);

    return 0;
}