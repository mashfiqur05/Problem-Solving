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

vector<int> num;
string k;
int d;
int dp[10005][105][2];

int fun (int pos, int sum, int f)
{
    if (pos == k.size())
    {
        if (sum % d == 0) return 1;
        else return 0;
    }

    if (dp[pos][sum][f] != -1) return dp[pos][sum][f];
    
    int res = 0, lmt;
    if (f == 0) lmt = num[pos];
    else lmt = 9;

    for (int i = 0; i <= lmt; i++)
    {
        int nf = f, nsum = (sum+i) %d;
        if (f == 0 && i < lmt) nf = 1;
        res += fun (pos+1, nsum, nf);
        res %= MOD;
    }

    return dp[pos][sum][f]=res;
}

int sol (string n)
{
    num.clear();
    for (auto u : n) num.push_back (u-'0');
    mem (dp, -1);
    // problem wants 1 to k. but it 'fun(0,0,0)' counts  0 to k.
    return (fun(0,0,0) - 1 + MOD) % MOD;
}

void solve (int CaseNo)
{
    cin >> k >> d;
    cout << sol(k) << endl;
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