#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int data;
    struct Node *next;
};

// This function prints contents of linked list starting from the given node
void printList(struct Node *n)
{
    struct Node *p = n;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}
// Driver's code
int main()
{
    struct Node head;
    struct Node second;
    struct Node third;

    head.data = 1;       // assign data in first node
    head.next = &second; // Link first node with second

    second.data = 2; // assign data to second node
    second.next = &third;

    third.data = 3; // assign data to third node
    third.next = NULL;

    // Function call
    printList(&head);

    return 0;
}
