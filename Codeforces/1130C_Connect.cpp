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
const int MX = 123;
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

vector<pair<int, int>> step = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
vector<string> g;
int n, r1,c1, r2, c2;
bool vis[MX][MX];
vector<pair<int, int>> canReachFromR1C1, canReachFromR2C2;

bool isValid (int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < n && g[x][y] == '0' && !vis[x][y]);
}
void bfs (int i , int j, bool f)
{
    queue<pair<int,int>> q;
    q.push ({i, j});
    vis[i][j] = true;

    while (!q.empty())
    {
        auto pos = q.front();
        vis[pos.first][pos.second] = true;
        q.pop();
        for (auto u : step)
        {
            int childX = pos.first + u.first;
            int childY = pos.second + u.second;

            if (isValid (childX, childY))
            {
                q.push ({childX, childY});
                vis[childX][childY] = true;
                if (f) canReachFromR1C1.push_back ({childX, childY});
                else canReachFromR2C2.push_back ({childX, childY});
            }
        }
    }
}

void solve (int CaseNo)
{
    cin >> n >> r1 >> c1 >> r2 >> c2;
    r1--; c1--; r2--; c2--;
    for (int i = 0; i < n; i++)
    {
        string s; cin >> s;
        g.push_back (s);
    }

    canReachFromR1C1.push_back ({r1, c1});
    canReachFromR2C2.push_back ({r2, c2});

    bfs (r1, c1, true);
    bfs (r2, c2, false);

    int ans = inf;

    // dbg (canReachFromR1C1);
    // dbg (canReachFromR2C2);
    for (auto u : canReachFromR1C1)
    {
        for (auto v : canReachFromR2C2)
        {
            int cost = sq (abs (u.first - v.first)) + sq (abs (u.second - v.second));
            ans = min (ans, cost);
        }
    }

    cout << ans << endl;
}


int32_t main()
{
    fastio();
    // srand(time(NULL));

    int testcases = 1;
    // cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve (tt);
    }

    return 0;
}