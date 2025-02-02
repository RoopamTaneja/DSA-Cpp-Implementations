#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
#define PI 3.14159265359

struct node
{
    int data;
    node *next;
    node *prev;
};
node *head = NULL;
node *temp = NULL; // temp points to last node of dll

void create_node()
{
    node *new_node = new node;
    new_node->next = NULL, new_node->prev = NULL;
    cout << "Enter data of node : ";
    cin >> new_node->data;
    if (head == NULL)
    { // if list is empty, this node is first node, so stored in head
        head = new_node;
        temp = new_node;
    }
    else
    { // if list is not empty, prev node ka next = new_node, new_node ka prev = prev node(temp), temp is updated to this node
        temp->next = new_node;
        new_node->prev = temp;
        temp = new_node;
    }
}

node *search_node(int key)
{ // finds first element with key in list
    node *x = head;
    while (x != NULL && x->data != key)
        x = x->next;
    return x;
}

void insert_begin(node *curr)
{
    curr->next = head;
    if (head != NULL)
        head->prev = curr;
    head = curr;
    curr->prev = NULL;
}
void insert_node(node *curr)
{
    node *tmp = new node;
    curr->next->prev = tmp;
    tmp->next = curr->next;
    curr->next = tmp; // inserts node named tmp after node named curr
    tmp->prev = curr;
}

void delete_node(node *to_del)
{ // deletes pointer to_del
    if (to_del->prev != NULL)
        to_del->prev->next = to_del->next;
    else
        head = to_del->next;
    if (to_del->next != NULL)
        to_del->next->prev = to_del->prev;
    free(to_del);
}
void display()
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
    cout << "Enter no of node you wish to enter : ";
    int value;
    cin >> value;
    for (int i = 0; i < value; i++)
        create_node();
    cout << "\nComplete linked list : \n";
    display();
    cout << "\nEnter value to be deleted : ";
    cin >> value;
    delete_node(search_node(value));
    display();
    return 0;
}