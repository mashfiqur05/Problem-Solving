///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///

#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

#define endl '\n'
#define ll long long
#define int long long
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a) )
#define sq(a) ((a) * (a))
#define unq(x) {x.erase(unique(x.begin(),x.end()),x.end());}

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const int MX = 2e5+123;
const ll infLL = 9000000000000000000;
const int MOD = 1e9+7;

int parent[MX];
int sz[MX];

int findParent(int u)
{
    if (u == parent[u])
        return u;
    return parent[u] = findParent(parent[u]);
}

void make_union(int u, int v)
{
    u = findParent(u);
    v = findParent(v);
    if (u != v)
    {
        if (sz[u] < sz[v])
            swap(u, v);
        parent[v] = u;
        sz[u] += sz[v];
    }
}


void make_set(int v)
{
    parent[v] = v;
    sz[v] = 1;
}

int find_set(int v) //// Path compression optimization O(log(n)).
{
    if (v == parent[v])
        return v;
    else
        return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) ///  Union by size / rank.
{

    if (sz[a] < sz[b])
    {
        swap(a, b);
    }
    parent[b] = a;
    sz[a] += sz[b];
}

void solve()
{
    int n, m, a;
    cin >> n >> m >> a;

    vector<pair<int,pair<int,int>>> edge;

    for(int i=1;i<=n;i++)
    {
        parent[i]=i;
        sz[i]=1;
    }

    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;

        if(w>=a) continue;

        edge.push_back({w,{u,v}});
    }

    sort(all(edge));

    int cost=0;

    for(auto e: edge)
    {
        int u=e.second.first;
        int v=e.second.second;
        int w=e.first;

        u=findParent(u);
        v=findParent(v);

        if(u!=v)
        {
            make_union(u,v);
            cost+=w;
        }
    }

    int airport=0;

    for(int i=1;i<=n;i++)
    {
        if(parent[i]==i)
            airport++;
    }

    cost += airport*a;

    cout<<cost<<" "<<airport<<endl;
}

int32_t main()
{
    fastio();
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //#endif
    // srand(time(NULL));

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        cout << "Case " << tt << ": ";
        solve ();
    }

    return 0;
}