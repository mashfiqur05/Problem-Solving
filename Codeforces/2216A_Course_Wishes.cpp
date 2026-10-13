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
    int n, k; cin >> n >> k;
    vector<int> a(k), b(n);
    for (int i = 0; i < k; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    map<int, int> cnt;
    for (auto u : b) cnt[u]++;

    vector<int> ans;
    for (int i = 1; i <= 1000; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (b[j] < k && cnt[b[j]+1] < a[b[j]])
            {
                cnt[b[j]]--;
                cnt[b[j]+1]++;
                b[j]++;
                ans.push_back(j);
            }
            else if (b[j] == k) 
            {
                cnt[b[j]]--;
                cnt[b[j]+1]++;
                b[j]++;
                ans.push_back (j);
            }
        }
    }

    // for (auto u : b) cout << u << " "; cout << endl;
    if (count(all (b), k+1) != n) cout << -1 << endl;
    else 
    {
        cout << ans.size() << endl;
        for (auto u : ans) cout << u+1 << " "; cout << endl;
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