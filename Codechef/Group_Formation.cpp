///   ***   ---   |||        In the name of ALLAH        |||   ---   ***   ///

#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false); cin.tie(nullptr);

#define ll long long
#define int long long
#define endl '\n'

const int N = 2e5 + 5;

vector<int> parent(N);
vector<int> sz(N);


// Create a new set
void make_set(int v)
{
    parent[v] = v;
    sz[v] = 1;
}


// Find parent with Path Compression
int find_set(int v)
{
    if (v == parent[v])
        return v;

    return parent[v] = find_set(parent[v]);
}


// Union by Size
void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);

    if (a == b)
        return;

    if (sz[a] < sz[b])
        swap(a, b);

    parent[b] = a;
    sz[a] += sz[b];
}


void solve()
{
    int n, m;
    cin >> n >> m;


    for (int i = 1; i <= n; i++)
    {
        make_set(i);
    }

    while (m--)
    {
        int u, v;
        cin >> u >> v;

        union_sets(u, v);
    }

    int components = 0, ways = 1;

    for (int i = 1; i <= n; i++)
    {
        if (find_set(i) == i)
        {
            components++;
            ways = (ways * sz[i]) % 1000000007;
        }
    }

    cout << components << " " << ways << endl;
    // cout << "Connected Components: " << components << endl;

}


int32_t main()
{
    fastio();


    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }


    return 0;
}