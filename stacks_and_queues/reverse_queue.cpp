#include <iostream>
using namespace std;
// reverse singly ll wali circular queue
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
    bool isEmpty();
};
bool Queue::isEmpty()
{
    if (rear == NULL)
        return true;

    return false;
}
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

void rev_q_recursive(Queue &q)
{
    int i;
    if (!q.isEmpty())
    {
        i = q.dequeue();
        rev_q_recursive(q);
        q.enqueue(i);
    }
}

int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    cout << "\n";
    rev_q_recursive(q);
    q.display();
    return 0;
}

/*In the main() function, a Queue object q is created and the values 10, 20, and 30 are enqueued to it. The display() method is then called to display the contents of the Queue object, which outputs 10 20 30.

The f(q) function is then called with the Queue object as an argument. Inside the function, since the Queue object is not empty, the first element 10 is dequeued from the front of the Queue object and stored in variable i. The function then calls itself recursively with the updated Queue object as an argument.

In the next recursive call, since the Queue object is still not empty, the first element 20 is dequeued from the front of the Queue object and stored in variable i. The function then calls itself recursively again with the updated Queue object as an argument.

In the third recursive call, since the Queue object is still not empty, the first element 30 is dequeued from the front of the Queue object and stored in variable i. The function then calls itself recursively again with the updated Queue object as an argument.

In the fourth recursive call, since the Queue object is now empty, the function returns. The function then enqueues the value stored in variable i, which is 30, to the rear of the Queue object. The previous recursive call then returns and enqueues the value stored in variable i, which is 20, to the rear of the Queue object. The first recursive call then returns and enqueues the value stored in variable i, which is 10, to the rear of the Queue object.

The final state of the Queue object after all recursive calls have returned is [30, 10, 20]. The display() method is then called again to display the contents of the updated Queue object, which outputs 30 10 20.*/

/*The variable i does not store multiple values at the same time. Instead, it stores a single value at a time during each recursive call of the f(Queue &q) function.

In each recursive call of the f(Queue &q) function, a new instance of the variable i is created with its own memory location. This means that each recursive call has its own separate copy of the variable i that can store a different value.

For example, in the first recursive call of the f(Queue &q) function, the variable i stores the value 10 that is dequeued from the front of the Queue object. In the next recursive call, a new instance of the variable i is created and it stores the value 20 that is dequeued from the front of the updated Queue object. In the third recursive call, another new instance of the variable i is created and it stores the value 30 that is dequeued from the front of the updated Queue object.*/