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
    int n, q;
    cin >> n >> q;
    vector<int> p_id(n+1), nest(n+1, 1);
    for (int i = 1; i <= n; i++) p_id[i] = i;

    int ans = 0;
    for (int i = 0; i < q; i++)
    {
        int op; cin >> op;
        if (op == 1)
        {
            int p, h; cin >> p >> h;
            int prev_nest = p_id[p];
            p_id[p] = h;
            nest[prev_nest]--; nest[h]++;
            if (nest[prev_nest] == 1) ans--;
            if (nest[h] == 2) ans++;
        }
        else cout << ans << endl;
    }
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