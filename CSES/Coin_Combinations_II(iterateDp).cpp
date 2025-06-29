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


void testCases (int tt)
{
    int n, sum;
    cin >> n >> sum;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    // vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
    /// dp[i][k] -> dp[i+1][k] & dp[i][k-vi] -> same row

    // for (int i = 0; i <= n; i++) dp[i][0] = 1;

    vector<int> nextStates (sum + 1, 0);
    nextStates[0] = 1;

    for (int i = n-1; i >= 0; i--)
    {
        vector<int> curState(sum + 1, 0);
        curState[0] = 1;
        for (int k = 1; k <= sum; k++)
        {
            if (v[i] <= k) curState[k] = (nextStates[k] + curState[k - v[i]]) % MOD;
            else curState[k] = (nextStates[k]) % MOD;
        }
        nextStates = curState;

        // nextStates[k] -> dp[i][k], curState[k-vi] -> dp[i][k-vi]
    }

    cout << nextStates[sum] << endl;
}


int32_t main()
{
    fastio();
    // srand(time(NULL));

    int testcases = 1;
    // cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        testCases (tt);
    }

    return 0;
}