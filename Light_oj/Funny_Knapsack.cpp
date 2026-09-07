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

void  generate (int ind,int sum,vector<int> &s, vector<int> &v)
    {
        if (ind == v.size())
        {
            s.push_back (sum);
            return;
        }

        generate(ind+1, sum, s, v);
        generate(ind+1, sum+v[ind], s, v);
    }

void solve ()
{
    int n, w; cin >> n >> w;
    vector<int> a, b;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        if (i%2 == 0) a.push_back(x);
        else b.push_back (x);
    }

    vector<int> sa,sb;
    generate(0, 0, sa, a);
    generate(0, 0, sb, b);

    sort (all (sb));

    int ans = 0;
    for (auto u : sa)
    {
        if (u <= w) ans += upper_bound(all(sb), w-u) - sb.begin();
    }

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
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        cout << "Case " << tt << ": ";
        solve ();
    }

    return 0;
}