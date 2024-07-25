#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define Bismillah() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);    ///  Fast IO.
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define mem(a,b) memset(a, b, sizeof(a) )
#define sq(a) ((a) * (a))
#define all(v) (v).begin(),(v).end()     /// ascending
#define rall(v) (v).rbegin(),(v).rend()  /// descending

//int gcd ( int a, int b ) { return __gcd ( a, b ); }
//int lcm ( int a, int b ) { return a * ( b / gcd ( a, b ) ); }

const int N = 2e4+123;
vector<int> adj[N];
bool vis[N];
int cnt, cnt1;
bool isValid[N];


void dfs (int vertex, int col)
{
    vis[vertex] = 1;
    cnt++;
    if (col == 1) cnt1++;

    int tmp;
    if (col == 1) tmp = 2;
    else tmp = 1;

    for (auto child : adj[vertex])
    { 
        if (vis[child]) continue;
        dfs (child, tmp);     
    }
}

int32_t main()
{
    Bismillah();

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        for (int i = 1; i < N; i++)
        {
            adj[i].clear();
            isValid[i] = 0;
            vis[i] = 0;
        }

        int n, mx = 1;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            adj[a].push_back (b);
            adj[b].push_back (a);
            isValid[a] = 1;
            isValid[b] = 1;
        }      

        int ans = 0;

        for (int i = 1; i <= N; i++)
        {
            if (isValid[i] == 1 && vis[i] == 0)
            {
                cnt = 0, cnt1 = 0;
                dfs (i, 1);
                
                ans += max (cnt1, cnt-cnt1);
            }
        }

        cout << "Case " << tt << ": " << ans << endl;

        
    }
    
    return 0;
}