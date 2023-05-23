#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int x)
{
    Node *temp = new Node;
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Recursive :
Node *insertRecur(Node *node, int val)
{
    if (node == NULL)
        return newNode(val);

    if (val < node->data)
        node->left = insertRecur(node->left, val);

    else if (val > node->data)
        node->right = insertRecur(node->right, val);

    return node;
}

// Iterative:
Node *insertIter(Node *root, int val)
{
    Node *x = root;
    if (x == NULL)
        return newNode(val); // if tree is empty
    while (true)
    {
        if (x->data <= val) // bada chahiye
        {
            if (x->right != NULL)
                x = x->right; // right jao
            else
            {
                x->right = newNode(val); // bada chahiye but right DNE, so waha node daal do
                break;                   // job done
            }
        }
        else // chhota chahiye
        {
            if (x->left != NULL)
                x = x->left; // left jao
            else
            {
                x->left = newNode(val); // chhota chahiye but aur left DNE, waha daal do
                break;                  // job done
            }
        }
    }
    return x;
}

int main()
{

    return 0;
}