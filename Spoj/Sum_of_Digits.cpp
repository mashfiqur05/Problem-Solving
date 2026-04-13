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

pair<int, int> dp[20][2]; // pos- f
int a, b;
vector<int> num;

pair<int, int> dfs (int pos, int f)
{
    if (pos == num.size()) return {1, 0};

    if (dp[pos][f].first != -1) return dp[pos][f];

    int lim, sum = 0, cnt = 0;
    if (f == 0) lim = num[pos];
    else lim = 9;

    for (int d = 0; d <= lim; d++)
    {
        int nf = f;
        if (f == 0 && d < lim) nf = 1;

        auto child = dfs (pos + 1, nf);

        cnt += child.first;
        sum += child.second + d * child.first;
    }

    return dp[pos][f] = {cnt, sum};
}

int sumOfDigit (int n)
{
    if (n <= 0) return 0;
    num.clear();
    while (n)
    {
        num.push_back (n % 10);
        n/= 10;
    }

    reverse(all (num));
    mem (dp, -1);

    return dfs (0, 0).second;
}

void solve (int CaseNo)
{ 
    while (1)
    {
        cin >> a >> b;
        if (a == -1 && b == -1) break;

        cout << sumOfDigit (b) - sumOfDigit (a-1) << endl;
    }
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