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

int cntPowerOf2(int n)
{
    int cnt = 0;
    while (n%2 == 0)
    {
        n /= 2;
        cnt++;
    }

    return cnt;
}

int cntPowerOf5(int n)
{
    int cnt = 0;
    while (n%5 == 0)
    {
        n /= 5;
        cnt++;
    }

    return cnt;
}

void solve (int CaseNo)
{
    int n, k; cin >> n >> k;
    vector<int> v(n), c2(n), c5(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        c2[i] = cntPowerOf2 (v[i]);
        c5[i] = cntPowerOf5 (v[i]);
    }

    vector<vector<int>> dp (k+1, vector<int> (10000+1, -inf));
    dp[0][0] = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = k; j >= 1; j--)
        {
            for (int f = 10000 - c5[i]; f >= 0; f--)
            {
                dp[j][f + c5[i]] =
                    max(dp[j][f + c5[i]],
                        dp[j - 1][f] + c2[i]);
            }
        }
    }

    int ans = 0;
    for (int f = 0; f <= 10000; f++)
    {
        ans = max(ans, min(f, dp[k][f]));
    }

    cout << ans << endl;
}


int32_t main()
{
    fastio();
    // srand(time(NULL));

    int testcases = 1;
    // cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve (tt);
    }

    return 0;
}