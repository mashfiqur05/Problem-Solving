///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///

#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define endl '\n'
#define ll long long
#define int long long
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a) )
#define sq(a) ((a) * (a))

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const int MX = 2e5+123;
const ll infLL = 9000000000000000000;
const int MOD = 1e9+7;
//
//debug
template<typename F,typename S>ostream&operator<<(ostream&os,const pair<F,S>&p){return os<<"("<<p.first<<", "<<p.second<<")";}
template<typename T>ostream&operator<<(ostream&os,const vector<T>&v){os<<"{";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<*it;}return os<<"}";}
template<typename T>ostream&operator<<(ostream&os,const set<T>&v){os<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<",";os<<*it;}return os<<"]";}
template<typename T>ostream&operator<<(ostream&os,const multiset<T>&v) {os<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<*it;}return os<<"]";}
template<typename F,typename S>ostream&operator<<(ostream&os,const map<F,S>&v){os<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<it->first<<" = "<<it->second;}return os<<"]";}
#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)
void faltu(){cerr << endl;}
template<typename T>void faltu(T a[],int n){for(int i=0;i<n;++i)cerr<<a[i]<<' ';cerr<<endl;}
template<typename T,typename...hello>void faltu(T arg,const hello&...rest){cerr<<arg<<' ';faltu(rest...);}
//#else
//#define dbg(args...)


int n;
vector<pair<int, int>> adj[MX];
vector<int> cost[MX];
bool vis[MX];
int dis[MX];

void dfs (int vertex)
{
    vis[vertex] = 1;

    for (auto u : adj[vertex])
    {
        if (!vis[u.first])
        {
            dis[u.first] = dis[vertex] + u.second;
            // dbg (u);
            dfs (u.first);
        }
    }
}

/// solve this with dfs. this also can be solved with bfs.

void solve (int testCase)
{
    mem (dis, 0);
    mem (vis, 0);
    cout << "Case " << testCase << ": ";
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back ({b, c});
        adj[b].push_back ({a, c});
    }

    dfs (0);
    // for (int i = 0; i < n; i++) cout << dis[i] << " ";cout << endl;
    int mx = 0;
    int id = 0;
    for (int i = 0; i < n; i++) 
    {
        if (dis[i] > mx)
        {
            mx = dis[i];
            id = i;
        }
    }

    mem (dis, 0);
    mem (vis, 0);

    dfs (id);
    int ans = 0;
    for (int i = 0; i < n; i++) 
    {
        ans = max (ans, dis[i]);
    }

    cout << ans << endl;
    for (int i = 0; i <= n; i++)
    {
        adj[i].clear();
    }
}


int32_t main()
{
    fastio();
    // srand(time(NULL));

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve (tt);
    }

    return 0;
}