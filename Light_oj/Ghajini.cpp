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

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const int MX = 2e5+123;
const ll infLL = 9000000000000000000;
const int MOD = 1e9+7;

int n;
int arr[MX], mx_tree[4 * MX], mn_tree[4 * MX];

void build(int node, int l, int r)
{
    if (l == r)
    {
        mx_tree[node] = arr[l];
        mn_tree[node] = arr[l];
    }
    else 
    {
        int mid = (l + r) / 2;
        
        build (2 * node, l, mid);
        build (2 * node + 1, mid + 1, r);

        mx_tree[node] = max (mx_tree[2 * node], mx_tree[2 * node + 1]);
        mn_tree[node] = min (mn_tree[2 * node], mn_tree[2 * node + 1]);
    }
}

int mx_query (int node, int l, int r, int sl, int sr)
{
    if (sr < l or r < sl) return INT_MIN;

    if (sl <= l and r <= sr) return mx_tree[node];

    int mid = (l + r) / 2;

    return max (mx_query (2 * node, l, mid, sl, sr), mx_query (2 * node + 1, mid + 1, r, sl, sr));
}

int mn_query (int node, int l, int r, int sl, int sr)
{
    if (sr < l or r < sl) return INT_MAX;

    if (sl <= l and r <= sr) return mn_tree[node];

    int mid = (l + r) / 2;

    return min (mn_query (2 * node, l, mid, sl, sr), mn_query (2 * node + 1, mid + 1, r, sl, sr));
}

void solve (int testCase)
{
    int d;
    cin >> n >> d;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    build (1, 1, n);

    int ans = 0;
    for (int i = 1; i + d - 1<= n; i++)
    {
        ans = max (ans, abs (mx_query (1, 1, n, i, i + d - 1) - mn_query (1, 1, n, i, i + d - 1)));
    }

    cout << "Case " << testCase << ": " << ans << endl;
}


int32_t main()
{
    fastio();
    // srand(time(NULL));

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve (tt);
    }

    return 0;
}