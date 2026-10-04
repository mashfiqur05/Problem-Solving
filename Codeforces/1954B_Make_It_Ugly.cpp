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
const int N = 2e5+123;
const ll infLL = 9000000000000000000;
const int MOD = 1e9+7;


void solve ()
{
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    if (count (all (v), v[0]) == n) 
    {
        cout << -1 << endl;
        return;
    } 
    vector<int> same, notSame;
    int c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == v[0])
        {
            c1++;
            if (c2)
            {
                notSame.push_back (c2);
                c2 = 0;
            }
        }
        else
        {
            if (c1)
            {
                same.push_back (c1);
                c1 = 0;
            }
            c2++;
        }
    }
    if (c1) same.push_back(c1);
    if (c2) notSame.push_back (c2);
    
    int ans = *min_element(all (same));
    if (*max_element(all (notSame)) >= 2) ans = 0;
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
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve ();
    }

    return 0;
}