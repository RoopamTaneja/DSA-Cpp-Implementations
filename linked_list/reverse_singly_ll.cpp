#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *create_list()
{
    cout << "Enter no. of nodes you wish to enter : ";
    int value;
    cin >> value;
    node *head = NULL;
    node *temp = NULL;
    for (int i = 0; i < value; i++)
    {
        node *new_node = new node;
        new_node->next = NULL;
        cout << "Enter data of node : ";
        cin >> new_node->data;
        if (head == NULL)
        {
            head = new_node;
            temp = new_node;
        }
        else
        {
            temp->next = new_node;
            temp = new_node;
        }
    }
    return head;
}

node *reverseList(node *head)
{ // iterative
    node *p = NULL;
    node *n = NULL;
    while (head)
    {
        n = head->next;
        head->next = p;
        p = head;
        head = n;
    }
    return p;
}

void display(node *head)
{
    node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
}

int main()
{
    node *h = create_list();
    cout << "Original linked list : \n";
    display(h);
    h = reverseList(h);
    cout << "\nReversed linked list : \n";
    display(h);
    return 0;
}
