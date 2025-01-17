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


void solve (int testCase)
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(m), q(k);
    for (int i = 0; i < m; i++) cin >> a[i];
    for (int i = 0; i < k; i++) cin >> q[i];

    vector<bool> pare (n+1, 0);
    for (int i = 0; i < k; i++)
    {
        pare[q[i]] = true;
    }

    for (int i = 0; i < m; i++)
    {
        if (pare[a[i]] == true)
        {
            if (n == k) cout << 1;
            else cout << 0;
        }
        else 
        {
            if (n-1 == k) cout << 1;
            else cout << 0;
        }
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
        solve (tt);
    }

    return 0;
}