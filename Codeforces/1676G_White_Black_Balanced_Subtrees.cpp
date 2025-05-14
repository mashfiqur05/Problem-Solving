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
const int MX = 4000+123;
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

vector<int> g[MX];
string s;
int score[MX];
bool vis[MX];

void dfs (int vertex)
{
    // cout << "Vertex: " << vertex << endl;

    vis[vertex] = true;
    if (s[vertex-1] == 'W') score[vertex] = 1;
    else score[vertex] = -1;

    for (auto u : g[vertex])
    {
        // cout << "Parent: " << vertex << " Child: " << u << endl;
        if (vis[u]) continue;
        // cout << "Score of par " << vertex << " " << score[vertex] << endl;
        // cout << "Score of par "  << vertex << " " << score[vertex] << " after add " << u << endl;
        dfs (u);
        score[vertex] += score[u];
        // cout << "Score of par "  << vertex << " " << score[vertex] << " after add " << u << endl;
    }
}

void testCases (int tt)
{
    mem (score, 0);
    mem (vis, 0);
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        int par;
        cin >> par;
        g[par].push_back (i);
        g[i].push_back (par);
    }
    cin >> s;

    dfs (1);
    int ans = 0;
    for (int i = 1; i <= n; i++) if (score[i] == 0) ans++;
    cout << ans << endl;

    for (int i = 1; i <= n; i++)
    {
        // dbg(i, g[i]);
        g[i].clear();
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
        testCases (tt);
    }

    return 0;
}