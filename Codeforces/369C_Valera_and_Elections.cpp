///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///

#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.ununordered_setf(ios::floatfield); cout.precision(10); cout.unordered_setf(ios::fixed,ios::floatfield);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define endl '\n'
#define ll long long
#define int long long
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define sz(x) (int)x.size()
#define mem(a,b) memunordered_set(a, b, sizeof(a) )
#define sq(a) ((a) * (a))
#define unq(x) {x.erase(unique(x.begin(),x.end()),x.end());}

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const int MX = 2e5+123;
const ll infLL = 9000000000000000000;
const int MOD = 1e9+7;

int n;
vector<pair<int, int>> g[MX];
bool vis[MX];
int needCandidate[MX];
vector<int> ans;

void dfs (int vertex)
{
    vis[vertex] = 1;
    bool isbad = false;

    for (auto child : g[vertex])
    { 
        if (vis[child.first]) continue;
        dfs (child.first);   
        
        // cout << child.first << " " << isbad << endl; 

        if (child.second == 2 && !needCandidate[child.first]) 
        {
            ans.push_back (child.first);
            needCandidate[child.first] = true;
        }

        if (needCandidate[child.first]) needCandidate[vertex] = true;
    }
}


void testCases (int tt)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int u, v, t;
        cin >> u >> v >> t;
        g[u].push_back ({v, t});
        g[v].push_back ({u, t});
    }

    dfs (1);

    cout << ans.size() << endl;
    for (auto u : ans) cout << u << " "; cout << endl;
}


int32_t main()
{
    fastio();
    // srand(time(NULL));

    int testcases = 1;
    // cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        testCases (tt);
    }

    return 0;
}
