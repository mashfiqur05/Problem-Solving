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
const int inf = (1LL << 30) - 1;
const int MX = 2e5+123;
const ll infLL = 9000000000000000000;
const int MOD = 1e9+7;


void solve ()
{
    int n; cin >> n;
    vector<vector<int>> v(n, vector<int> (n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) cin >> v[i][j];
    }

    bool f = 1;
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++)
    {
        vector<int> bitOn(32, 0);
        for (int j = 0; j < n; j++)
        {
            int val = v[i][j];
            for (int k = 0; k <= 30; k++)
            {
                if ((1LL << k) & val)
                {
                    bitOn[k]++;
                }
            }
        }

        int cur= 0;
        for (int m = 0; m < 32; m++)
        {
            if (bitOn[m] == n-1) cur |= (1LL << m);
        }
        ans[i] = min (cur, inf);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) 
        {
            if (i == j) continue;
            if ((ans[i] | ans[j]) != v[i][j]) f = 0;
        }
    }
    if (!f) 
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) cout << ans[i] << " "; cout << endl;
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