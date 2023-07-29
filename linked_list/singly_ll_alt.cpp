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

void insert_node(node *&curr, int val)
{
    node *tmp = new node(val);
    tmp->next = curr->next;
    curr->next = tmp; // inserts node named tmp after node named curr
}

void insert_at_beginning(node *&head, int val)
{
    node *tmp = new node(val);
    tmp->next = head;
    head = tmp;
}

void delete_node(node *&head, node *curr)
{
    if (curr == head)
    { // to delete the head
        head = curr->next;
        delete curr;
    }
    else
    { // to delete node next to curr
      // (if u want to delete current node, u need to traverse to reach node before curr)
        node *tmp;
        tmp = curr->next;
        curr->next = tmp->next;
        delete tmp;
    }
}

int get_length(node *&head)
{
    int count = 0;
    node *curr = head; // Initialize current
    while (curr != NULL)
    {
        count++;
        curr = curr->next;
    }
    return count;
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
}

node *search_node(node *&head, int key)
{ // finds first element with key in list
    node *x = head;
    while (x != NULL && x->data != key)
        x = x->next;
    return x;
}

int main()
{
    node *head = NULL;
    create_node(head, 1);
    create_node(head, 2);
    create_node(head, 3);
    create_node(head, 4);
    display(head);
    return 0;
}