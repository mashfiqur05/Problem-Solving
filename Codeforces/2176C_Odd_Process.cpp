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


void solve (int CaseNo)
{
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)cin >> v[i];
    
    vector<int> even, odd;
    for (int i = 0; i < n; i++)
    {
        if (v[i] % 2 == 0) even.push_back (v[i]);
        else odd.push_back (v[i]);
    }

    sort (rall (even));
    sort (rall (odd));

    vector<int> ans(n);
    int cur = 0, last = 0;
    if (odd.size() == 0) ans[0] = 0;
    else {ans[0] = odd[0]; cur += odd[0];}

    int sum = accumulate(all (v), 0LL);

    for (int k = 1, e = 0, o = 0; k <n; k++)
    {
        if (odd.size() == 0) 
        {
            ans[k] = 0;
        }
        else if (even.size() == e)
        {
            ans[k] = last;
            last = ans[k-1];
        }
        else 
        {
            cur += even[e];
            e++;
            ans[k] = cur;
            last = ans[k-1];
        }
    }

    if (sum % 2 == 0) ans[n-1] = 0;
    
    for (auto u : ans) cout << u << " "; cout << endl;
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