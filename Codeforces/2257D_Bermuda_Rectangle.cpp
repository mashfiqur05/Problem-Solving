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

/*
s = 8
5 6

1 -> 8 
2 -> 4 
3 -> 2 
4 -> 2 
5 to 8 is 1

5+4+2+2+1+1 = 15

problem is x, y < s

1 2 4 8
8 4 2 1

6*1+4*1+2*2+1*1 = 15 

*/

void solve ()
{
    int s, q; cin >> s >> q;

    vector<int> div;
    for (int i = 1; i * i <= s; i++)
    {
        if (s % i == 0)
        {
            div.push_back(i);
            if (i != s/i) div.push_back (s/i);
        }
    }

    sort (all (div));

    // for (auto u : div) cout << u << " "; cout << endl;
    vector<int> prefix(div.size(), 0), contribution (div.size(), 0);
    for (int i = 0; i < div.size(); i++)
    {
        if (i == 0) prefix[i] = s/div[i];
        else prefix[i] = prefix[i-1] + ((s/div[i]) * (div[i]-div[i-1]));
        contribution[i] = s/div[i];
        // cout << prefix[i] << " ";
    }

    auto getPrefix = [&](int x)
    {
        if (x == 0)
            return 0LL;

        int id = lower_bound(all(div), x) - div.begin();

        if (id == 0)
            return x * (s / div[id]);

        return prefix[id - 1] + (x - div[id - 1]) * (s / div[id]);
    };

    while (q--)
    {
        int x, y;
        cin >> x >> y;
        // cout << getPrefix(5) << endl;

        // have to do in log(s)
        int limit = s / y;

        int id = upper_bound(all(div), limit) - div.begin() - 1;

        int k = min(x, div[id]);

        int ans = k * y + getPrefix(x) - getPrefix(k);

        cout << ans << endl;
    }
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