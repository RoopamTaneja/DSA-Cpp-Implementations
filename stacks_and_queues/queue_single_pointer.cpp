#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Queue
{
private:
    Node *rear;

public:
    Queue() { rear = NULL; }
    void enqueue(int x);
    int dequeue();
    void display();
};

void Queue::enqueue(int x)
{
    Node *temp = new Node;
    temp->data = x;
    temp->next = NULL;
    if (rear == NULL)
    {
        rear = temp;
        rear->next = rear;
    }
    else
    {
        temp->next = rear->next;
        rear->next = temp;
        rear = temp;
    }
}

int Queue::dequeue()
{
    if (rear == NULL)
    {
        cout << "Queue is empty" << endl;
        return -1;
    }
    int x;
    if (rear->next == rear)
    {
        x = rear->data;
        delete rear;
        rear = NULL;
    }
    else
    {
        Node *temp = rear->next;
        x = temp->data;
        rear->next = temp->next;
        delete temp;
    }
    return x;
}

void Queue::display()
{
    if (rear == NULL)
    {
        cout << "Queue is empty" << endl;
        return;
    }
    Node *temp = rear->next;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != rear->next);
}

int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    cout << "\n";
    cout << q.dequeue() << "\n";
    q.display();
    return 0;
}

// This code creates a Queue class that has a Node structure to represent each element in
// the queue. The Queue class has a single pointer rear that points to the last element in
// the queue. The enqueue function adds an element to the end of the queue, while the
// dequeue function removes and returns the first element in the queue. The display
// function prints out all the elements in the queue.