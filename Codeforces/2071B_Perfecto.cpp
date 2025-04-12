///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///

#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define endl '\n'
#define ll long long
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

bool isPerfectSquare (ll n)
{
    ll q = sqrt (n);
    return (q * q == n);
}

void testCases (int tt)
{
    int n;
    cin >> n;
    ll sum = (n * (n + 1)) / 2;
    if (isPerfectSquare (sum)) 
    {
        cout << -1 << endl;
        return;
    }

    vector<int> ans;
    ans.push_back (2);
    ans.push_back (1);
    ll total = 0;
    for (int i = 3; i <= n; i++)
    {
        ans.push_back (i);
    }

    for (int i = 0; i < n; i++)
    {
        total += ans[i];
        if (isPerfectSquare(total))
        {
            if (i != n - 1)
            {
                swap(ans[i], ans[i + 1]);
                total += ans[i];
                i++;
            }
            else 
            {
                cout << -1 << endl;
                return;
            }
        }
    }

    for (auto u : ans)
    {
        cout << u << " ";
    }
    cout << endl;
}


int32_t main()
{
    fastio();
    // srand(time(NULL));

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        testCases (tt);
    }

    return 0;
}