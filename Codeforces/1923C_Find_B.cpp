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
#define unq(x) {x.erase(unique(x.begin(),x.end()),x.end());}

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const int MX = 2e5+123;
const ll infLL = 9000000000000000000;
const int MOD = 1e9+7;


void solve (int CaseNo)
{
    int n, q; cin >> n >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    vector<int> prefix_sum (n+1, 0), cnt1(n+1, 0);
    for (int i = 1; i <= n; i++) prefix_sum[i] = prefix_sum[i-1] + v[i-1];
    for (int i = 1; i <= n; i++) cnt1[i] = cnt1[i-1] + (v[i-1] == 1);
    while (q--)
    {
        int l, r; cin >> l >> r;
        int len = r - l + 1;
        int cnt = cnt1[r] - cnt1[l-1];
        int possible_sum = len + cnt;
        int sum = prefix_sum[r] - prefix_sum[l-1];
        if (possible_sum > sum || len == 1)
        {
            cout << "NO" << endl;
        }
        else cout << "YES" << endl;
    }
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