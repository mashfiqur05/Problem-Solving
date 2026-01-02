///---  In the name of ALLAH    ---///
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

vector<bool> visited;
vector<int> order;
vector<int> roots;
vector<vector<int>> adj;
vector<vector<int>> adj_rev;
vector<vector<int>> components;

void dfs1(int v)
{
    visited[v] = true;
    for (auto u : adj[v])
        if (!visited[u])
            dfs1(u);
    order.push_back(v);
}

void dfs2(int v, vector<int> &component)
{
    visited[v] = true;
    component.push_back(v);
    for (auto u : adj_rev[v])
        if (!visited[u])
            dfs2(u, component);
}

void strongly_connected_components(int n)
{
    order.clear();
    components.clear();
    roots.clear();
    visited.assign(n, false);

    for (int i = 0; i < n; i++)
        if (!visited[i])
            dfs1(i);

    visited.assign(n, false);
    reverse(order.begin(), order.end());
    roots.assign(n, 0);

    for (auto v : order)
    {
        if (!visited[v])
        {
            vector<int> component;
            dfs2(v, component);
            components.push_back(component);

            int root = *min_element(component.begin(), component.end());
            for (auto u : component)
                roots[u] = root;
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int line;
        cin >> line;

        vector<string> s(line);
        for (int i = 0; i < line; i++)
            cin >> s[i];

        int n = line;
        adj.assign(n, {});
        adj_rev.assign(n, {});

        for (int i = 0; i < line; i++)
        {
            for (int j = 0; j < line; j++)
            {
                if (s[i][j] == 'Y')
                {
                    adj[i].push_back(j);
                    adj_rev[j].push_back(i);
                }
            }
        }

        strongly_connected_components(n);

        cout << components.size() << endl;
    }
    return 0;
}
