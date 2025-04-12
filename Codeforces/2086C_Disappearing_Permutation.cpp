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


void testCases (int tt)
{
    int n;
    cin >> n;
    vector<int> p(n+1), d(n+1);
    // map<int, int> ind;
    for (int i = 1; i <= n; i++) {cin >> p[i];}
    for (int i = 1; i <= n; i++) cin >> d[i];

    // for (auto u : ind) cout << u.first << ' ' << u.second << endl;
    vector<bool> f(n+1, false);
    int cnt = 0;
    vector<int> ans(n+1);
    for (int i = 1; i <= n; i++)
    {
        // cout << "i " << i << endl;
        int khujbo = d[i], child = p[d[i]];
        if (f[khujbo])
        {
            ans[i] = cnt;
            continue;
        }
        while (khujbo != child)
        {
            // cout << "khujbo " << khujbo << " chi " << child << " ";
            f[child] = true;
            child = p[child];
            cnt++;
            // cout << "khujbo " << khujbo << " chi " << child << endl;
        }
        f[child] = true;
        cnt++;
        ans[i] = cnt;
    }

    for (int i = 1; i <= n; i++) cout << ans[i] << ' '; cout << endl;
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