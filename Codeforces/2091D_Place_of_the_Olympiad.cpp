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

bool isOk (int mid, int k, int n, int m)
{
    int row = (mid * (m / (mid+1))) + m % (mid + 1);
    int can_seat = row * n;

    // cout << "mid " << mid << " row " << row << " can seat " << can_seat << endl;
    if (can_seat >= k) return true;
    else return false;
}

void testCases (int tt)
{
    int n, m, k;
    cin >> n >> m >> k;

    int l = 0, r = m, ans;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        // cout << l << " " << r << " " << mid << " ";
        if (isOk(mid, k, n, m)) 
        {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
        // cout << ans << " " << isOk (mid, k, n, m) << endl;
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