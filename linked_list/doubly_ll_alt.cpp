#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

class node
{
public:
    int data;
    node *next, *prev;
    node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

void create_node(node *&head, int val)
{
    node *new_node = new node(val);
    if (head == NULL)
    { // if list is empty, this node is first node, so stored in head
        head = new_node;
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new_node;
    new_node->prev = temp;
    return;
}

node *search_node(node *&head, int key)
{ // finds first element with key in list
    node *x = head;
    while (x != NULL && x->data != key)
        x = x->next;
    return x;
}

void insert_begin(node *&head, int val)
{
    node *curr = new node(val);
    curr->next = head;
    if (head != NULL)
        head->prev = curr;
    head = curr;
    curr->prev = NULL;
}

void insert_node(node *&curr, int val)
{
    node *tmp = new node(val);
    curr->next->prev = tmp;
    tmp->next = curr->next;
    curr->next = tmp; // inserts node named tmp after node named curr
    tmp->prev = curr;
}

void delete_node(node *&head, node *&to_del)
{ // deletes pointer to_del
    if (to_del->prev != NULL)
        to_del->prev->next = to_del->next;
    else
        head = to_del->next;
    if (to_del->next != NULL)
        to_del->next->prev = to_del->prev;
    delete to_del;
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