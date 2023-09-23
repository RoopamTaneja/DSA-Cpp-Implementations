#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
#define PI 3.14159265359

struct node
{
    int coeff;
    int exp;
    node *next;
};

node *create_list()
{ // need to ensure descending order of powers while making list
    cout << "Enter no. of nodes you wish to enter : ";
    int value;
    cin >> value;
    node *head = NULL;
    node *temp = NULL;
    for (int i = 0; i < value; i++)
    {
        node *new_node = new node;
        new_node->next = NULL;
        cout << "Enter coeff of term : ";
        cin >> new_node->coeff;
        cout << "Enter exponent of term : ";
        cin >> new_node->exp;
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

node *poly_add(node *h1, node *h2)
{
    node *head = NULL;
    node *temp = NULL;
    while (h1 != NULL && h2 != NULL)
    {
        node *new_node = new node;
        new_node->next = NULL;
        if (h1->exp > h2->exp)
        {
            new_node->exp = h1->exp;
            new_node->coeff = h1->coeff;
            h1 = h1->next;
        }
        else if (h2->exp > h1->exp)
        {
            new_node->exp = h2->exp;
            new_node->coeff = h2->coeff;
            h2 = h2->next;
        }
        else
        {
            new_node->exp = h2->exp;
            new_node->coeff = h1->coeff + h2->coeff;
            h1 = h1->next;
            h2 = h2->next;
        }
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
    while (h1 != NULL)
    {
        node *new_node = new node;
        new_node->next = NULL;
        new_node->exp = h1->exp;
        new_node->coeff = h1->coeff;
        h1 = h1->next;
        temp->next = new_node;
        temp = new_node;
    }
    while (h2 != NULL)
    {
        node *new_node = new node;
        new_node->next = NULL;
        new_node->exp = h2->exp;
        new_node->coeff = h2->coeff;
        h2 = h2->next;
        temp->next = new_node;
        temp = new_node;
    }
    return head;
}
void display(node *head)
{
    node *h = head;
    while (h->next != NULL)
    {
        cout << h->coeff << "x^" << h->exp << " + ";
        h = h->next;
    }
    cout << h->coeff << "x^" << h->exp;
}

int main()
{
    node *head1 = create_list();
    node *head2 = create_list();
    node *sum = poly_add(head1, head2);
    display(sum);
    return 0;
}
