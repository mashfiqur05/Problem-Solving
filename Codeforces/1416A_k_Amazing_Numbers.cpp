///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///

#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

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


void solve ()
{
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    vector<pair<int, int>> pos(n+1, {0, 0}); // prev, maxdis
    vector<int> ans(n+1, -1);

    for (int i = 0; i < n; i++)
    {
        int prevPos = pos[v[i]].first, dis = pos[v[i]].second;
        pos[v[i]].first = i+1;
        pos[v[i]].second = max (dis, i+1 - prevPos);
    }

    for (int i = 1; i <= n; i++)
    {
        int prevPos = pos[i].first, dis = pos[i].second;
        pos[i].first = n+1;
        pos[i].second = max (dis, n+1 - prevPos);
    }
    
    // for (int i = 1; i <= n; i++) cout << pos[i].first <<" " << pos[i].second << endl;

    for (int i = 1; i <= n; i++)
    {
        int st = pos[i].second;
        if (st == 0) continue;
        for (int j = st; j <= n; j++)
        {
            if (ans[j] != -1) break;
            ans[j] = i;
        }
    }

    for (int i = 1; i <= n; i++) cout << ans[i] << " "; cout << endl;
}


int32_t main()
{
    fastio();
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //#endif
    // srand(time(NULL));

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve ();
    }

    return 0;
}