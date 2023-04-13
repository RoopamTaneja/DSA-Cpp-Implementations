// pending

// #include <bits/stdc++.h>
// using namespace std;

// struct node
// {
//     int data;
//     node *next;
//     node *prev;
// };
// node *nil = NULL;
// node *temp = NULL;

// void create_list(vector<int> v) // creates circular doubly ll from a vector
// {
//     int size = v.size();
//     for (int i = 0; i < size; i++)
//     {
//         node *new_node = new node;
//         new_node->next = NULL, new_node->prev = NULL;
//         new_node->data = v[i];
//         if (head == NULL)
//         {
//             head = new_node;
//             temp = new_node;
//         }
//         else
//         {
//             temp->next = new_node;
//             new_node->prev = temp;
//             temp = new_node;
//         }
//     }
//     temp->next = head;
//     head->prev = temp;
// }

// void delete_node(node *to_del)
// {
//     if (to_del == head)
//     {
//         head = to_del->next;
//     }
//     to_del->prev->next = to_del->next;
//     to_del->next->prev = to_del->prev;
// }
// // NEEDS TO BE RECTIFIED
// //  void insert_begin(node *curr)
// //  {
// //      curr->next = head;
// //      if (head != NULL)
// //          curr->prev = head->prev;
// //      if (head != NULL && head->prev != NULL)
// //          head->prev->next = curr;
// //      if (head != NULL)
// //          head->prev = curr;
// //      head = curr;
// //  }

// node *search_node(int key)
// { // finds first element with key in list
//     node *x = head;
//     while (x != head && x->data != key)
//         x = x->next;
//     return x;
// }

// void display()
// {
//     node *tmp = head;
//     do
//     {
//         cout << tmp->data << " ";
//         tmp = tmp->next;
//     } while (tmp != head);
// }

// int main()
// {
//     int n, value;
//     cin >> n;
//     vector<int> elements;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> value;
//         elements.emplace_back(value);
//     }
//     create_list(elements);
//     display();
//     // cout << "\nMention what you wish to insert : ";
//     // cin >> value;
//     // node *x;
//     // x->data = value, x->prev = NULL, x->next = NULL;
//     // insert_begin(x);
//     // display();
//     return 0;
// }
