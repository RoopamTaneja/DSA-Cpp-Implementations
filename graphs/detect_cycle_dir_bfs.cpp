#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;

bool cyclePresent(ll V, vl adj[])
{
    ll indegree[V] = {0};
    for (ll i = 0; i < V; i++)
    {
        for (auto it : adj[i])
            indegree[it]++;
    }

    queue<ll> q;
    for (ll i = 0; i < V; i++)
    { // vertices of 0 indegree of all components get added to q
        if (indegree[i] == 0)
            q.push(i);
    }
    ll cnt = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cnt++;
        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }

    return !(cnt == V);
}

int main()
{

    return 0;
}