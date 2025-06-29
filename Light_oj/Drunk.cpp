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
#define unq(x) {x.erase(unique(x.begin(),x.end()),x.end());}

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const int MX = 2e5+123;
const ll infLL = 9000000000000000000;
const int MOD = 1e9+7;

int n;
vector<int> g[MX]; 
bool vis[MX], record[MX];

bool cycleDetectionForDirectedGraph (int vertex, int par = 0)
{   
    if (record[vertex]) return true;
    if (vis[vertex]) return false;

    vis[vertex] = true;
    record[vertex] = true;

    for (auto u : g[vertex])
    {
        if (cycleDetectionForDirectedGraph (u, vertex)) return true;
    }

    record[vertex] = false;

    return false;
}


void solve (int CaseNo)
{
    for (int i = 0; i < MX; i++) g[i].clear(); 
    mem (vis, false);
    mem (record, false);
    set<string> s;
    vector<pair<string, string>> v;

    cout << "Case " << CaseNo << ": ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string a, b;
        cin >> a >> b;
        v.push_back ({a, b});
        s.insert (a);
        s.insert (b);
    }
    
    map<string, int> id;
    int tmp = 1;
    for (auto u : s)
    {
        id[u] = tmp++;
    }
    for (int i = 0; i < n; i++)
    {
        int a = id[v[i].first];
        int b = id[v[i].second];
        g[a].push_back (b);
    }

    // for (auto u : id) cout << u.second << "-" << u.first << endl;
    // for (int i = 1; i < tmp; i++) 
    // {
    //     cout << i << "--->";
    //     for (auto u : g[i]) cout << u << ' '; cout << endl;
    // }

    for (int i = 1; i < tmp; i++)
    {
        if (!vis[i] && cycleDetectionForDirectedGraph (i))
        {
            cout << "No" << endl;
            
            return;
        } 
    }
    
    cout << "Yes" << endl;
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