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
    int n, k, q; cin >> n >> k >> q;
    vector<pair<int, pair<int, int>>> v(q);
    for (int i = 0; i < q; i++) cin >> v[i].first >> v[i].second.first >> v[i].second.second;

    vector<int> ans(n+1, -1), track (n+1, 0);

    for (int i = 0; i < q; i++)
    {
        int c = v[i].first, l = v[i].second.first, r = v[i].second.second;
        if (c == 1)
        {
            for (int j = l; j <= r; j++)
            {
                if (track[j] == 2 || track[j] == 3) track[j] = 3;
                else track[j] = 1;
            }
        }
        else 
        {
            for (int j = l; j <= r; j++)
            {
                if (track[j] == 1 || track[j] == 3) track[j] = 3;
                else track[j] = 2;
            }
        }
        // for (int i = 1; i <= n; i++) cout << track[i] <<" "; cout << endl;
    }
    // for (int i = 1; i <= n; i++) cout << track[i] <<" "; cout << endl;

    int val = 0;
    for (int i = 1; i <= n; i++) 
    {
        if (track[i] == 1)
        {
            ans[i] = k;
        }
        else if (track[i] == 2)
        {
            ans[i] = val++;
            if (val == k) val = 0;
        }
        else if (track[i] == 3)
        {
            ans[i] = k+1;
        }
        else ans[i] = k;
    }
    for (int i = 1; i <= n; i++) cout << ans[i] <<" "; cout << endl;
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