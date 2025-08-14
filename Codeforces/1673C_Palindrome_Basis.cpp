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
const int MX = 4e4+123;
const ll infLL = 9000000000000000000;
const int MOD = 1e9+7;

int dp[MX];

bool isPallindrome (int n)
{
    string s = to_string (n);
    string t = s;
    reverse (all (t));

    return s == t;
}


void solve (int CaseNo)
{
    int n; cin >> n;
    cout << dp[n] << endl;
}


int32_t main()
{
    fastio();
    // srand(time(NULL));

    vector<int> pallin;
    for (int i = 1; i < MX; i++)
    {
        if (isPallindrome (i)) pallin.push_back (i);
    }

    dp[0] = 1;
    for (auto p : pallin)
    {
        for (int i = p; i < MX; i++)
        {
            dp[i] += dp[i-p];
            dp[i] %= MOD;
        }
    }

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve (tt);
    }

    return 0;
}