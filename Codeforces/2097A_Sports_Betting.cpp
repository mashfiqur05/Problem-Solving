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
    map<int, int> cnt;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        cnt[v[i]]++;
    }

    for (auto u : cnt)
    {
        if (u.second >= 4)
        {
            cout << "Yes" << endl;
            return;
        }
    }

    int cur = -1;
    for (auto u : cnt)
    {
        if (cur != -1)
        {
            if (cur+1 != u.first) cur = -1;
            else if (u.second >= 2)
            {
                cout << "Yes" << endl;
                return;
            }
            else cur++;
        }
        if (cur == -1)
        {
            if (u.second >= 2) cur = u.first;
        }
        // cout << cur << " " << u.first << " " << u.second << endl;
    }

    cout << "No" << endl;
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