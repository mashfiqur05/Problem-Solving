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
    int n, k1, k2; cin >> n >> k1 >> k2;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    priority_queue<int> pq;
    for (int i = 0; i < n; i++) 
    {
        int val = abs (a[i]-b[i]);
        if (val != 0) pq.push(val);
    }

    int move = k1+k2;
    while (move--)
    {
        if (pq.empty())
        {
            // cout << "move " << move << endl;
            if (move % 2 == 0) pq.push(1);
            else pq.push(0);
            break;
        }
        int val = pq.top();
        pq.pop();
        val = max (0LL, val-1);
        if (val == 0) continue;
        // cout << move << " " << val << endl;
        pq.push(val);
    }

    int ans = 0;
    while (!pq.empty())
    {
        int val = pq.top();
        // cout << val << endl;
        ans += sq(val);
        pq.pop();
    }

    cout << ans << endl;
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