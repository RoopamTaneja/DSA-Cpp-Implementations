// Code for iterative DFS traversal as well as
// no. of connected components in undirected using DFS

#include <bits/stdc++.h>
using namespace std;

vector<int> dfsIter(int S, vector<int> adj[], int vis[], vector<int> &result)
{
    vis[S] = 1;
    stack<int> st;
    st.push(S);
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        result.push_back(node);

        for (int i = adj[node].size() - 1; i >= 0; --i)
        {
            int it = adj[node][i];
            if (!vis[it])
            {
                vis[it] = 1;
                st.push(it);
            }
        }
    }
    return result;
}

vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    int vis[V] = {0};
    int count = 0;

    vector<int> result;
    for (int i = 0; i < V; i++)
    {
        if (vis[i] == 0)
        {
            dfsIter(i, adj, vis, result);
            count++;
        }
    }
    cout << "Number of connected components: " << count << "\n";
    return result;
}
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAns(vector<int> &ans)
{
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}

int main()
{
    vector<int> adj[7];

    addEdge(adj, 0, 2);
    addEdge(adj, 2, 4);
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 3);
    addEdge(adj, 5, 6);

    vector<int> ans = dfsOfGraph(7, adj);
    printAns(ans);

    return 0;
}