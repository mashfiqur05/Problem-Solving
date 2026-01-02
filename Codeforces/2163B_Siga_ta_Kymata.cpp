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
    for (int i = 0; i < n; i++) cin >> v[i];
    string s; cin >> s;
    
    int mn = min_element (all (v)) - v.begin();
    int mx = max_element (all (v)) - v.begin();
    //cout << mn << " " << mx << endl;

    if (s[0] == '1' || s[n-1] == '1' || s[mn] == '1' || s[mx] == '1')
    {
        cout << -1 << endl;
        return;
    }

    vector<pair<int, int>> ans;
    if (mn != 0) ans.push_back ({1, mn+1});
    if (mn != n-1) ans.push_back ({mn+1, n});
    if (mx != 0) ans.push_back ({1, mx+1});
    if (mx != n-1) ans.push_back ({mx+1, n});
    ans.push_back ({min (mn+1, mx+1), max (mn+1, mx+1)});

    cout << ans.size() << endl;
    for (auto u : ans) cout << u.first << " " << u.second << endl;
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