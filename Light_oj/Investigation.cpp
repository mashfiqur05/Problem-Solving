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
int a, b, k; 
int dp[12][105][105][2]; // pos-sum mod - num mod -f.

int fun (int pos, int sum, int val, int f)
{
    if (pos == num.size())
    {
        if (sum % k == 0 && val % k == 0) return 1;
        else return 0;
    }
    if (dp[pos][sum][val][f] != -1) return dp[pos][sum][val][f];

    int res= 0, LMT;
    if (f == 0) LMT = num[pos];
    else LMT = 9;

    for (int dgt = 0; dgt<= LMT; dgt++)
    {
        int nf = f, nsum = (sum+dgt) % k, nval = (10*val+dgt) % k;
        if(f == 0 && dgt < LMT) nf = 1;
        res += fun (pos+1, nsum, nval, nf);
    }

    return dp[pos][sum][val][f] = res;
}

int sol (int n)
{
    if(n < 0) return 0;
    num.clear();
    while (n)
    {
        num.push_back (n%10);
        n/=10;
    }
    if(num.empty()) num.push_back(0);
    reverse (all (num));
    mem (dp, -1);

    return fun (0, 0, 0, 0);
}   

void solve (int CaseNo)
{
    cin >> a >> b >> k;
    if (k > 90) cout << 0 << endl;
    else cout << sol(b) - sol (a-1) << endl;
}


int32_t main()
{
    fastio();
    // srand(time(NULL));

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        cout << "Case " << tt << ": ";
        solve (tt);
    }

    return 0;
}