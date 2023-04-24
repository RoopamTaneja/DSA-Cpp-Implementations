#include <bits/stdc++.h>
using namespace std;

class Queue
{
	int rear, front;
	int size;
	int *arr;

public:
	Queue(int s)
	{
		front = rear = -1;
		size = s;
		arr = new int[s];
	}

	void enqueue(int value);
	int dequeue();
	void displayQueue();
};

/* Function to create Circular queue */
void Queue::enqueue(int value)
{
	if ((front == 0 && rear == size - 1) ||
		(rear == (front - 1)))
	{
		printf("\nQueue is Full\n");
		return;
	}

	else if (front == -1) /* Insert First Element */
	{
		front = rear = 0;
		arr[rear] = value;
	}

	else if (rear == size - 1 && front != 0)
	{
		rear = 0;
		arr[rear] = value;
	}

	else
	{
		rear++;
		arr[rear] = value;
	}
}

// Function to delete element from Circular Queue
int Queue::dequeue()
{
	if (front == -1)
	{
		printf("\nQueue is Empty\n");
		return INT_MIN;
	}

	int data = arr[front];
	arr[front] = -1;
	if (front == rear) // 1 element remaining
	{
		front = -1;
		rear = -1;
	}
	else if (front == size - 1)
		front = 0;
	else
		front++;

	return data;
}

// Function displaying the elements
// of Circular Queue
void Queue::displayQueue()
{
	if (front == -1)
	{
		printf("\nQueue is Empty\n");
		return;
	}
	printf("\nElements in Circular Queue are: ");
	if (rear >= front)
	{
		for (int i = front; i <= rear; i++)
			printf("%d ", arr[i]);
	}
	else
	{
		for (int i = front; i < size; i++)
			printf("%d ", arr[i]);

		for (int i = 0; i <= rear; i++)
			printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	Queue q(5);
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
			int value;
			printf("Enter value to be enqueued : ");
			scanf("%d", &value);
			q.enqueue(value);
			break;
		case 2:
			q.dequeue();
			break;
		case 3:
			q.displayQueue();
			break;
		case 4:
			break;
		default:
			printf("Incorrect choice \n");
		}
	} while (ch != 4);
	return 0;
}
