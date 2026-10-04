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

/*
4 2 3 2

4 1 2 3
7 2 5 6

b = 5 + 5
s = 2 + 7
*/

void solve ()
{
    int n, k, b, s; cin >> n >> k >> b >> s;
    vector<int> p(n+1);
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= n; i++) cin >> a[i];

    int mx = *max_element(all(a));
    // cout << mx << endl;
    vector<int> posb(n + 1, -1), poss(n + 1, -1);

    int pb = 0, ps = 0, cb = 0, cs = 0;

    for (int i = 1; i <= min(n, k); i++)
    {
        cb += a[b];
        cs += a[s];
        pb = max(pb, cb + (k - i) * a[b]);
        ps = max(ps, cs + (k - i) * a[s]);
        b = p[b];
        s = p[s];
    }

    if (pb > ps)
        cout << "Bodya" << endl;
    else if (pb < ps)
        cout << "Sasha" << endl;
    else
        cout << "Draw" << endl;
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