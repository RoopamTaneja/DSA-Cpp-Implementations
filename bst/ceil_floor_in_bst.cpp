#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};
// Quite similar to successor and predecessor first approach
int findCeil(Node *root, int input)
{
    if (root == NULL)
        return -1;
    Node *x = root;
    int ceil = -1;
    while (x != NULL)
    {
        if (x->data < input)
            x = x->right;
        else if (x->data > input)
        {
            ceil = x->data; // it is a possible ceiling
            x = x->left;
        }
        else
        {
            ceil = x->data;
            break;
        }
    }
    return ceil;
}

int findFloor(Node *root, int input)
{
    if (root == NULL)
        return -1;
    Node *x = root;
    int floor = -1;
    while (x != NULL)
    {
        if (x->data < input)
        {
            floor = x->data; // it is a possible floor
            x = x->right;
        }
        else if (x->data > input)
        {
            x = x->left;
        }
        else
        {
            floor = x->data;
            break;
        }
    }
    return floor;
}

// T.C of both : O(h) ---> O(n) in worst case

int main()
{

    return 0;
}