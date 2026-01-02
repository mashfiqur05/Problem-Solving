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
    int n, k, c; cin >> n >> k >> c;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;

    int ans = -1;
    
    for (int i = 1; i+k-1 <= n; i++)
    {
        int l = i, r = l + k-1, f = 1;
        for (int j = 0; j < c; j++)
        {
            int l_hit;
            if (i == 1) l_hit = 0;
            else l_hit = (l-1) / v[j].first;
            int r_hit = r / v[j].first;

            int total_hit = r_hit - l_hit;

            if (total_hit != v[j].second)
            {
                f = 0;
                break;
            }
        }
        if (f)
        {
            ans = l;
            break;
        }
    }

    cout << ans << endl;
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