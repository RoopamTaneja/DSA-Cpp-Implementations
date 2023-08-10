#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void create_node(node *&head, int val)
{
    node *newNode = new node(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode; // insert after tail
    return;
}

node *reverse_list_iter(node *&head)
{
    node *prev_p = NULL;
    node *current_p = head;
    node *next_p;
    while (current_p)
    {
        next_p = current_p->next;
        current_p->next = prev_p;
        prev_p = current_p;
        current_p = next_p;
    }
    head = prev_p;
    return head;
}

node *reverse_list_recur(node *&head)
{
    if (head == NULL || head->next == NULL)
        return head;

    node *newHead = reverse_list_recur(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

void display(node *&head)
{
    node *tmp;
    tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << "\n";
}

int main()
{
    node *head = NULL;
    create_node(head, 1);
    create_node(head, 2);
    create_node(head, 3);
    create_node(head, 4);
    display(head);
    reverse_list_iter(head);
    display(head);
    reverse_list_recur(head);
    display(head);
    return 0;
}