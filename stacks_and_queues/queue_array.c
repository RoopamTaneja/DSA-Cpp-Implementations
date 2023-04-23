// check overflow underflow again

#include <stdio.h>
#define SIZE 3
int inp_arr[SIZE];
int tail = 0;
int head = 0;

void enqueue()
{
    if (head == tail + 1)
        printf("Overflow \n");
    else
    {
        int insert_item;
        printf("Element to be inserted in the Queue\n : ");
        scanf("%d", &insert_item);
        inp_arr[tail] = insert_item;
        if (tail == SIZE - 1)
            tail = 0;
        else
            tail++;
    }
}

void dequeue()
{
    if (head == tail + 1)
    {
        printf("Underflow \n");
    }
    else
    {
        printf("Element deleted from the Queue: %d\n", inp_arr[head]);
        if (head == SIZE - 1)
            head = 0;
        else
            head++;
    }
}

void show()
{

    if (head == tail + 1)
        printf("Empty Queue \n");
    else
    {
        printf("Queue: \n");
        for (int i = head; i < tail; i++)
            printf("%d ", inp_arr[i]);
        printf("\n");
    }
}

int main()
{
    int ch;
    do
    {
        printf("1.Enqueue Operation\n");
        printf("2.Dequeue Operation\n");
        printf("3.Display the Queue\n");
        printf("4.Exit\n");
        printf("Enter your choice of operations : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            show();
            break;
        case 4:
            break;
        default:
            printf("Incorrect choice \n");
        }
    } while (ch != 4);
    return 0;
}
