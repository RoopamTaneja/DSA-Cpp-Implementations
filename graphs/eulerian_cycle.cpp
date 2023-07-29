#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100; // maximum number of nodes in the graph

vector<int> eulerian_cycle; // stores the eulerian cycle

void dfs(int node, int graph[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (graph[node][i] > 0)
        {
            graph[node][i]--; // remove the edge from the graph
            graph[i][node]--;
            dfs(i, graph, n);
        }
    }
    eulerian_cycle.push_back(node); // add the node to the eulerian cycle
}

int main()
{
    int graph[MAX][MAX]; // adjacency matrix
    int n;               // number of nodes
    // input the graph
    cout << "Input number of nodes : ";
    cin >> n;
    cout << "Input adjacency matrix : \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    // find any eulerian cycle starting from node 0
    dfs(0, graph, n);

    cout << "\nEulerian Cycle : \n";
    // print the eulerian cycle
    for (int i = eulerian_cycle.size() - 1; i >= 0; i--)
    {
        cout << eulerian_cycle[i] << " ";
    }
    cout << "\n";

    return 0;
}

// We start a depth-first search (DFS) from node 0. 
// In each recursive call of the DFS, we look for an adjacent
// node that hasn't been visited yet and remove the corresponding edge 
// from the graph by decrementing the value of graph[node][i] and graph[i][node].
// We then recursively call the DFS on the adjacent node.