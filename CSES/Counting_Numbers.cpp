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
int a, b;
int dp[20][12][2]; // pos-prev-smaller or not

int fun (int pos, int prev, int f)
{
    if (pos == num.size()) return 1;

    if (dp[pos][prev][f] != -1) return dp[pos][prev][f];

    int res = 0;
    int LMT;

    if (f == 0) LMT = num[pos];
    else LMT = 9;

    for (int digit = 0; digit <= LMT; digit++)
    {
        int nf = f;
        if (prev != 10 && prev == digit) continue;
        if(f == 0 && digit < LMT) nf = 1;
        int nprev = (prev==10 && digit==0) ? 10 : digit;
        res += fun (pos+1, nprev, nf);
    }

    return dp[pos][prev][f] = res;
}


int solve(int n){
    if (n < 0) return 0;
    if (n == 0) return 1;
    num.clear();
    while(n>0){
        num.push_back(n%10);
        n/=10;
    }
    reverse(num.begin(), num.end());
    /// Stored all the digits of b in num for simplicity

    memset(dp, -1, sizeof(dp));
    int res = fun(0, 10, 0);
    return res;
}

int32_t main()
{
    fastio();
    // srand(time(NULL));

    int testcases = 1;
    // cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        cin >> a >> b;
        cout << solve (b) - solve(a-1) << endl;
    }

    return 0;
}