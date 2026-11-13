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
const int N = 2e5+123;
const ll infLL = 9000000000000000000;
const int MOD = 1e9+7;


void solve ()
{
    int n, m; cin >> n >> m;
    if (n == 1 || m == 1)
    {
        if (m == 1)
        {
            cout << 0 << endl;
            for (int i = 0; i < n; i++)cout << 0 << endl;
        }
        else if (n == 1)
        {
            cout << 2 << endl;
            for (int i = 0; i < m; i++) cout << i << " "; cout << endl;
        }

        return;
    }

    vector<vector<int>> ans(n, vector<int> (m));

    for (int i = 0; i < min(n, m-1); i++)
    {
        for (int j = 0; j < m; j++)
        {
            ans[i][j] = (j - i + m) % m;
            // cout << ans[i][j] << " ";
        }
        // cout << endl;
    }

    for (int i = m-1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ans[i][j] = ans[i-1][j];
            // cout << ans[i][j] << " ";
        }
    }

    set<int> res;
    for (int j = 0; j < m; j++)
    {
        set<int> s;
        for (int i = 0; i < n; i++)
        {
            s.insert (ans[i][j]);
        }
        int tmp=0;
        for (auto u : s)
        {
            if (u != tmp) break;
            tmp++;
        }
        res.insert (tmp);
    }

    int aa = 0;
    for (auto u : res)
    {
        if (u != aa) break;
        aa++;
    }

    cout << aa <<endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << ans[i][j] << " ";
        }
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