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

bool isPossible (vector<int> &v, int canPartition)
{
    vector<bool> f(MX, false);
    f[v[0]] = 1;
    int remainingElement = 1, ans = 1;
    set<int> futureElements;
    for (int i = 1; i < v.size(); i++)
    {
        futureElements.insert (v[i]);
        if (f[v[i]])
        {
            f[v[i]] = 0;
            remainingElement--;
        }

        if (remainingElement == 0)
        {
            ans++;
            for (auto u : futureElements) f[u] = true;
            remainingElement = futureElements.size();
        }
    }

    if (ans >= canPartition) return true;
    else return false;
}

void testCases (int tt)
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    map<int, int> frq;
    for (int i = 0; i < n; i++) frq[v[i]]++;
    int mx = 0;
    for (auto u : frq) mx = max (mx, u.second);

    int l = 1, r = mx, ans = 1; 
    while (l <= r)
    {
        int mid = (l + r) / 2;

        // cout << l << " " << r << " " << mid << " " << ans << endl;
        if (isPossible (v, mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }

    cout << ans << endl;
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