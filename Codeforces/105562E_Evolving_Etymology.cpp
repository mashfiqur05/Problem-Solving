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

long long powerMod(long long base, long long exp, long long mod) {
    long long ans = 1 % mod;

    while (exp > 0) {
        if (exp % 2 == 1) {
            ans = (ans * base) % mod;
        }

        base = (base * base) % mod;
        exp /= 2;
    }

    return ans;
}

void solve ()
{
    int n, k; cin >> n >> k;
    string s; cin >> s;
    // s = '.'+s;
    string ans = "";

    int val = powerMod(2, k, n);
    // cout << val << endl;
    for (int i = 0; i < n; i++)
    {
        int ind = ((i * val) % n) % n;
        // cout << ind << " ";
        ans += s[ind];
    }

    cout << ans << endl;
}   


int32_t main()
{
    fastio();
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //#endif
    // srand(time(NULL));

    int testcases = 1;
    // cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve ();
    }

    return 0;
}