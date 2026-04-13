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
const int MOD = 998244353;

int l, r, k; 
int power10[20];
vector<int> num;
pair<int, int> dp[20][2][1<<10][2];

pair<int, int> fun (int pos, int f, int mask, int started)
{
    if (pos == num.size())
    {
        if (started) return {1, 0};
        else return {0, 0};
    }
    if (dp[pos][f][mask][started].first != -1) return dp[pos][f][mask][started];

    int sum = 0, cnt = 0, lim = (f == 0 ? num[pos] : 9);

    for (int d = 0; d <= lim; d++)
    {
        int nf = f;
        if (f == 0 && d < lim) nf = 1;
        int nmask = mask;
        int nst = started | (d != 0);
        if (nst) nmask |= (1 << d);
        else nmask = 0;

        if (nst && __builtin_popcount(nmask) > k) continue;

        auto res = fun (pos+1, nf, nmask, nst); // res.first = child count and second = child sum.

        int rem = num.size() - pos - 1;
        int add = (d * power10[rem]) % MOD;
        add = (add * res.first) % MOD;

        sum = (sum + res.second + add) % MOD;
        cnt = (cnt + res.first) % MOD;
    }

    return dp[pos][f][mask][started] = {cnt, sum};
}

int findSum (int n)
{
    if (n <= 0) return 0;
    num.clear();
    while (n)
    {
        num.push_back(n %10);
        n/=10;
    }

    reverse (all (num));
    mem (dp, -1);

    auto ans = fun (0, 0, 0, 0);
    return ans.second;
}

void solve (int CaseNo)
{
    cin >> l >> r >> k;

    int ans = (findSum(r) - findSum(l-1) + MOD) % MOD;
    cout << ans << endl;
}


int32_t main()
{
    fastio();
    // srand(time(NULL));

    power10[0] = 1;
    for (int i = 1; i < 20; i++)
    {
        power10[i] = (power10[i - 1] * 10) % MOD;
    }
    int testcases = 1;
    // cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve (tt);
    }

    return 0;
}