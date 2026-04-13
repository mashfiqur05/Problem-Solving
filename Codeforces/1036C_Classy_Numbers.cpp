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
int dp[20][2][4];

int fun (int pos, int f, int non_zero)
{
    if (pos == num.size()) return 1;

    if (dp[pos][f][non_zero] != -1) return dp[pos][f][non_zero];
    
    int res = 0;
    int lim = (f == 0 ? num[pos] : 9);
    if (non_zero == 3) lim = 0;

    for (int d = 0; d <= lim; d++)
    {
        int nf = f;
        if (f ==0 && d < lim) nf = 1;
        int cnt = non_zero + (d != 0);
        res += fun (pos + 1, nf, cnt);
    }

    return dp[pos][f][non_zero] = res;
}

int classyNumber (int n)
{
    if (n <= 0) return 1;
    num.clear();
    while (n)
    {
        num.push_back(n % 10);
        n /= 10;
    }
    reverse (all (num));

    mem (dp, -1);

    return fun (0, 0, 0);
}

void solve (int CaseNo)
{
    int l, r; cin >> l >> r;
    cout << classyNumber (r) - classyNumber (l-1) << endl;
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