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


bool isPossible(int mid, const vector<pair<int,int>>& v)
{
    int total_width = 0;

    for (auto p : v)
    {
        int a = p.first;
        int b = p.second;

        int mx = max(a, b), mn = min(a, b);

        if (mx >= mid)
        {
            total_width += min(mn, (long long)mid);
        }
    }

    return total_width >= mid;
}

void solve (int CaseNo)
{
    int n; 
    cin >> n;

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second;

    int l = 0, r = 1e9, ans = 0;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (isPossible(mid, v))
        {
            ans = mid;   
            l = mid + 1;
        }
        else
        {
            r = mid - 1;  
        }
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