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
#define mem(a,b) memset(a, b, szof(a) )
#define sq(a) ((a) * (a))
#define unq(x) {x.erase(unique(x.begin(),x.end()),x.end());}

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const ll infLL = 9000000000000000000;
const int MOD = 1e9+7;


const int N = 2e5+123;
vector<int> parent(N), degree(N);
vector<int> sz(N);

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

void union_sets(int a, int b) ///  Union by sz / rank.
{

    if (sz[a] < sz[b])
    {
        swap(a, b);
    }
    parent[b] = a;
    sz[a] += sz[b];
}

void solve ()
{
    int n; cin >> n;
    vector<int> v(n+1);
    for (int i = 1; i <= n; i++) cin >> v[i];

    for (int i = 1; i <= n; i++)
    {
        make_set(i);
    }

    for (int i = 1; i <= n;  i++)
    {
        int a = i, b = v[i];

        int u = find_set(a);
        int v = find_set(b);

        if (u != v)
        {
            union_sets(u, v);
        }
    }

    int mx = 0, cnt = 0;
    vector<bool> vis(n+1, false);
    for (int i = 1; i <= n; i++)
    {
        // cout << i << " " << parent[i] << endl;
        if (parent[i] == i)
            mx++;
        
        if (v[v[i]] == i && vis[find_set(i)]== false) 
        {
            cnt++;
            vis[find_set(i)] = true;
        }
    }

    // cout << cnt << endl;
    int cycle = mx - cnt;
    int mn = cycle + (cnt > 0 ? 1 : 0);
    cout << mn << " " << mx << endl;
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
        solve ();
    }

    return 0;
}