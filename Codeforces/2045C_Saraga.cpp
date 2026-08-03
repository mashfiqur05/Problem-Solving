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
    string s, t; cin >> s >> t;
    vector<int> fs(26, inf), ft(26, inf);
    for (int i = 1; i < s.size(); i++)
    {
        int c = s[i] - 'a';
        if (fs[c] == inf) fs[c] = i+1;
        // cout << c << " " << fs[c] << endl;
    }

    for (int i = t.size()-2; i >= 0; i--)
    {
        int c = t[i] - 'a';
        if (ft[c] == inf) ft[c] = t.size() - i;
    }

    int len = inf, ind = -1;
    for (int i = 0; i < 26; i++)
    {
        // cout << i << " " << fs[i] << " " << ft[i] << endl;
        if (fs[i]+ft[i] < len && fs[i] != inf && ft[i] != inf)
        {
            len = fs[i] + ft[i];
            ind = i;
        }
    }

    if (ind == -1) 
    {
        cout << ind << endl;
        return;
    }
    string ans = "";
    // cout << ind << " " << fs[ind] << " " << ft[ind] << endl;
    for (int i = 0; i < fs[ind]; i++) 
    {
        ans += s[i];
    }
    ans.pop_back();
    for (int i = t.size()-ft[ind]; i < t.size(); i++) ans += t[i];

    cout << ans << endl;

}


int32_t main()
{
    fastio();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    // srand(time(NULL));

    int testcases = 1;
    // cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve ();
    }

    return 0;
}