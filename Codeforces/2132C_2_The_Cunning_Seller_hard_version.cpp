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

vector<int> cost, watermelon;

void solve (int CaseNo)
{
    int n, k; cin >> n >> k;
    int ans = 0, deal = 0;
    vector<int> track(watermelon.size());

    for (int i = watermelon.size() - 1; i >= 0; i--)
    {
        if (watermelon[i] <= n)
        {
            int cnt = n / watermelon[i];
            ans += cost[i] * cnt;
            track[i] = cnt;
            deal += cnt;
            n %= watermelon[i];
        }
    }

    if (deal > k) 
    {
        cout << -1 << endl;
        return;
    }

    for (int i = track.size()-1; i > 0; i--)
    {
        int val = watermelon[i], cnt = track[i];
        int need_deal = cnt * 2;
        if (deal + need_deal <= k)
        {
            deal += need_deal;
            ans -= cost[i] * cnt;
            ans += cost[i-1] * cnt * 3;
            track[i-1] += cnt * 3;
        }
        else 
        {
            int remaining = k - deal;
            remaining /= 2;
            ans -= cost[i] * remaining;
            ans += cost[i-1] * remaining * 3;
            break;
        }
    }

    cout << ans << endl;
}


int32_t main()
{
    fastio();
    // srand(time(NULL));


    for (int i = 0;; i++)
    {
        int number = pow (3, i);
        int coin = pow (3, i+1) + i * pow (3, i-1);
        if (coin > 1e18) break;
        watermelon.push_back(number);
        cost.push_back(coin);
    }

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve (tt);
    }

    return 0;
}