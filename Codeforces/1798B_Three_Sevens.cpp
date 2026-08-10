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


void solve ()
{
    int m; cin >> m;
    vector<vector<int>> lottery;
    for (int i = 1; i <= m; i++)
    {
        int n; cin >> n;
        vector<int> v(n);
        for (int j = 0; j < n; j++) cin >> v[j];
        lottery.push_back (v);
    }

    set<int> f;
    vector<int> ans(m, -1);
    bool possible = 1;
    for (int i = m-1; i >= 0; i--)
    {
        for (auto val : lottery[i])
        {
            if (f.find(val) == f.end())
            {
                ans[i] = val;
            }
            f.insert(val);
        }
        if (ans[i] == -1) {possible = 0; break;}
    }

    if (!possible)
        cout << -1 << endl;
    else
    {
        for (auto u : ans)
            cout << u << " ";
        cout << endl;
    }
}


int32_t main()
{
    fastio();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    // srand(time(NULL));

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve ();
    }

    return 0;
}