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
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int div = (k+1)/2;
    multiset<int> small, large, init;
    for (int i = 0; i < k; i++) init.insert(a[i]);
    for (int i = 0; i < div; i++)
    {
        small.insert(*init.begin());
        init.erase(init.begin());
    }
    for (int i = 0; i < k-div; i++)
    {
        large.insert(*init.begin());
        init.erase(init.begin());
    }

    // for (auto u : small) cout << u << " "; cout << endl;
    // for (auto u : large) cout << u << " "; cout << endl;
    
    vector<int> ans;
    ans.push_back(*small.rbegin());
    // cout << *small.rbegin() << " ";

    // cout << small.size() << " " << large.size() << endl;
    for (int i = 1; i <= n - k; i++)
    {
        int rmv = a[i-1], add = a[i+k-1];
        if (small.find(rmv) != small.end())
        {
            small.erase (small.find(rmv));
        }
        else
        {
            large.erase (large.find(rmv));
        }

        if (small.empty() || add <= *small.rbegin())
        {
            small.insert(add);
        }
        else
        {
            large.insert(add);
        }

        if (small.size() < div)
        {
            small.insert(*large.begin());
            large.erase(large.begin());
        }
        else if (small.size() > div)
        {
            large.insert(*small.rbegin());
            small.erase(prev(small.end()));
        }

        ans.push_back(*small.rbegin());
    }

    for (auto u : ans) cout << u << " "; cout << endl;
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