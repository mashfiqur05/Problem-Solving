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
    int n, d, l;
    cin >> n >> d >> l;
    int mind = ((n+1)/2 - (l * (n/2))), mxd = ((l * (n+1)/2) - (n/2));
    if (d < mind || d > mxd)
    {
        cout << -1 << endl;
        return;
    }

    // cout << mind << " " << mxd << endl;
    vector<int> ans(n+1, 1);
    if ((n%2 == 0 && d == 0) || (n % 2 == 1 && d == 1))
    {
        for (int i = 1; i <= n; i++) cout << ans[i] << " "; cout << endl;
        return;   
    }
    
    if (n % 2 == 0)
    {
        if (d >= 0)
        {
            int need = d, cnt = need / (l-1), extra = need - (cnt * (l-1));
            for (int i = 1; i <= n; i+=2)
            {
                if (cnt == 0)
                {
                    ans[i] += extra;
                    break;
                }
                ans[i] = l;
                cnt--;
            }
        }
        else
        {
            int need = -d, cnt = need / (l-1), extra = need - (cnt * (l-1));
            // cout << need << " " << cnt << " " << extra << endl;
            for (int i = 2; i <= n; i+=2)
            {
                if (cnt == 0)
                {
                    ans[i] += extra;
                    break;
                }
                ans[i] = l;
                cnt--;
            }
        }
    }
    else // odd length
    {
        if (d >= 1) /// increase odd position
        {
            int need = d - 1, cnt = need / (l - 1), extra = need - cnt * (l-1);
            for (int i = 1; i <= n; i+=2)
            {
                if (cnt == 0)
                {
                    ans[i] += extra;
                    break;
                }
                ans[i] = l;
                cnt--;
            }
        }
        else   /// increase even position
        {
            int need = 1 - d, cnt = need / (l - 1), extra = need - cnt * (l-1);
            // cout << need << " " << cnt << " " << extra << endl;
            for (int i = 2; i <= n; i+=2)
            {
                if (cnt == 0)
                {
                    ans[i] += extra;
                    break;
                }
                ans[i] = l;
                cnt--;
            }
        }
    }

    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 1) sum += ans[i];
        else sum -= ans[i];
    }
    if (sum != d) cout << "SUM --> " << sum << endl;
    
    for (int i = 1; i <= n; i++) cout << ans[i] << " "; cout << endl;
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