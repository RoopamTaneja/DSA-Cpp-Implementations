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
node *temp = NULL;
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

void display()
{
    node *temp;
    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
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