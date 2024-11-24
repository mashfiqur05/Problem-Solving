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

bool isPrime(int num)
{
    if (num <= 1)
    {
        return false;
    }
    if (num == 2)
    {
        return true;
    }
    if (num % 2 == 0)
    {
        return false;
    }

    for (int i = 3; i * i <= num; i += 2)
    {
        if (num % i == 0)
        {
            return false;
        }
    }

    return true;
}

void solve (int testCase)
{
    int n;
    cin >> n;
    vector<int> ans;
    int prev = 0;
    for (int i = 1; i <= n; i+=2)
    {
        ans.push_back (i);
        prev = i;
    }

    int rev;
    bool f = 0;
    for (int i = 2; i <= n; i+=2)
    {
        if (!f && !isPrime (i+prev))
        {
            f = 1;
            ans.push_back (i);
            rev = i;
        }
        else if (f) ans.push_back (i);
    }
    if (f) for (int i = rev-2; i >= 2; i-= 2) ans.push_back (i);

    if (!f) 
    {
        cout << -1 << endl;
        return;
    }
    for (auto u : ans) cout << u << ' ';cout << endl;
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