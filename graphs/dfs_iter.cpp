// starting vertex different and multi source functionality pending

#include <bits/stdc++.h>
using namespace std;

vector<int> dfsIter(int V, vector<int> adj[])
{
    int vis[V] = {0};
    vis[0] = 1;
    stack<int> st;
    // push the initial starting node
    st.push(0);
    vector<int> result;

    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        result.push_back(node);

        // for (auto it : adj[node])
        // {
        //     if (!vis[it])
        //     {
        //         vis[it] = 1;
        //         st.push(it);
        //     }
        // }

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
    vector<int> adj[5];

    addEdge(adj, 0, 2);
    addEdge(adj, 2, 4);
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 3);

    vector<int> ans = dfsIter(5, adj);
    printAns(ans);

    return 0;
}