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

vector<int> divisor(int n)
{
    vector<int> ans;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ans.push_back (i);
            if (i != n/i) ans.push_back (n/i);
        }
    }

    return ans;
}

void solve (int CaseNo)
{
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    vector<int> prefix (n+1, 0);
    map<int, int> cnt;
    for (auto u : v) cnt[u]++;
    for (int i = 1; i <= n; i++) prefix[i] = prefix[i-1] + cnt[i];
    // for (int i = 1; i <= n;i++) cout << i << " " << prefix[i] << endl;

    int ans = 1;
    for (int g = 1; g <= n; g++)
    {
        int canRemove = k;
        if (prefix[g-1] > canRemove) continue;
        else canRemove -= prefix[g-1];

        int midElement;
        if (4 * g <= n) midElement = prefix[4*g-1] - prefix[g];
        else midElement = n - prefix[g];

        if (midElement <= canRemove)
        {
            ans = g;
            continue;
        }

        if (2 * g <= n) midElement -= (prefix[2*g] - prefix[2*g-1]);
        if (3*g <= n) midElement -= (prefix[3*g] - prefix[3*g-1]);

        if (midElement <= canRemove) ans = g;
    }

    cout << ans << endl;
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