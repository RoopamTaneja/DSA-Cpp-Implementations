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
};
node *head = NULL;
node *temp = NULL;
void create_node()
{
    node *new_node = new node;
    new_node->next = NULL;
    cout << "Enter data of node : ";
    cin >> new_node->data;
    if (head == NULL)
    { // if list is empty, this node is first node, so stored in head
        head = new_node;
        temp = new_node;
    }
    else
    { // if list is not empty, prev node(temp) ka next = new_node, temp is updated to this node
        temp->next = new_node;
        temp = new_node;
    }
}

void insert_node(node *curr)
{
    node *tmp = new node;
    tmp->next = curr->next;
    curr->next = tmp; // inserts node named tmp after node named curr
}

void delete_node(node *curr)
{
    if (curr == head)
    { // to delete the head
        head = curr->next;
        free(curr);
    }
    else
    { // to delete node next to curr
        node *tmp;
        tmp = curr->next;
        curr->next = tmp->next;
        free(tmp);
    }
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
    return 0;
}