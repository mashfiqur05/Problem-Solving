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
    int h, w; cin >> h >> w;
    vector<vector<int>> v(h, vector<int> (w, -1));
    vector<int> r(h), c(w);
    for (int i = 0; i < h; i++) cin >> r[i];
    for (int i = 0; i < w; i++) cin >> c[i];

    for (int i = 0; i < h; i++)
    {
        int val = r[i];
        for (int j = 0; j < val; j++) v[i][j] = 1;
        if (val < w) v[i][val] = 0;
    }

    for (int j = 0; j < w; j++)
    {
        int val = c[j];
        for (int i = 0; i < val; i++) 
        {
            if (v[i][j] == 0) 
            {
                cout << 0 << endl;
                return;
            }
            v[i][j] = 1;
        }

        if (val < h) 
        {
            if (v[val][j] == 1) 
            {
                cout << 0 << endl;
                return;
            }
            v[val][j] = 0;
        }
    }

    int unoccupied = 0;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (v[i][j] == -1) unoccupied++;
        }
    }

    int ans = 1;
    for (int i = 0; i < unoccupied; i++) ans = (ans * 2) % MOD;

    cout << ans << endl;
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
    // cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve ();
    }

    return 0;
}