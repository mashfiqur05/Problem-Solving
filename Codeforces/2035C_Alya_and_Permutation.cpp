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

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const int MX = 2e5+123;
const ll infLL = 9000000000000000000;
const int MOD = 1e9+7;

vector<int> sequence (int n)
{
    vector<int> ret;
    if (n == 4)
    {
        ret = {2, 1, 3, 4};
        return ret;
    }
    if (n == 6)
    {
        ret = {1, 2, 4, 6, 5, 3};
        return ret;
    }

    int x = log2(n);
    int y = (1LL << x);

    ret.push_back (y);
    ret.push_back (y-1);
    ret.push_back (y-2);
    ret.push_back (3);
    ret.push_back (1);
    ret.push_back (2);

    for (int i = 4; i < y-2; i++) ret.push_back (i);
    for (int i = y+1; i <= n; i++) ret.push_back (i);

    reverse (all (ret));

    return ret;
}

void solve (int testCase)
{
    int n;
    cin >> n;
    vector<int> ans;

    if (n & 1)
    {
        vector<int> ans = sequence (n-1);
        cout << n << endl;
        for (auto u : ans) cout << u << " "; cout << n << " " <<  endl;
    }
    else 
    {
        vector<int> ans = sequence (n);
        int k = (1LL << ((int)log2(n) + 1));
        k--;
        cout << k << endl;
        for (auto u : ans) cout << u << ' '; cout << endl;
    }
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