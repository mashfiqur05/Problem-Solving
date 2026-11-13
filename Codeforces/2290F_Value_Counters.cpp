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
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    int sum = accumulate (all (v), 0LL);
    if (sum != 0)
    {
        cout << -1 << endl;
        return;
    }

    vector<int> ans(n, -1);
    // int l = 0, r = n-1;
    // if (v[0] == 0) ans[r--] = 1;
    // if (v[n-1] == 0) ans[l++] = n;
    for (int i = 0; i < n; i++) 
    {
        int val = v[i];
        // if (val == 0) 
        // {
        //     if (i == 0 || i == n-1) continue;
        //     else 
        //     {
        //         cout << -1 << endl;
        //         return;
        //     }
        // }
        if (val <= 0)
        {
            int great = n-i-1;
            int ind = (great+val);
            // cout << ind << endl;
            if (ans[ind] != -1 || ind < 0 || ind >= n)
            {
                cout << -1 << endl;
                return;
            }
            ans[ind] = i+1;
        }
        else 
        {
            int small = i;
            int ind = n - (small-val)-1;
            if (ans[ind] != -1  || ind < 0 || ind >= n)
            {
                cout << -1 << endl;
                return;
            }
            ans[ind] = i+1;
        }
    }

    for (auto u : ans) cout << u << " "; cout << endl;
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