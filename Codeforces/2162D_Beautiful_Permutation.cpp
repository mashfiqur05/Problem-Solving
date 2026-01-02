///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///

#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::flowatfield); cout.precision(10); cout.setf(ios::fixed,ios::flowatfield);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

// #define endl '\n'
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

int query_p (int l, int r)
{
    cout << "1 " << l << " " << r << endl;
    int x; cin >> x;
    return x;
}

int query_a (int l, int r)
{
    cout << "2 " << l << " " << r << endl;
    int x; cin >> x;
    return x;
}

void solve (int CaseNo)
{
    int n; cin >> n;
    int total = query_a (1, n) - query_p (1, n);

    int low = 1, high = n, l = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int diff = query_a(1, mid) - query_p(1, mid);
        if (diff > 0)
        {
            l = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    // low = l, high = n;
    // int r = -1;
    // while (low <= high)
    // {
    //     int mid = (low + high) / 2;
    //     int diff = query_a(1, mid) - query_p(1, mid);
    //     if (diff == total)
    //     {
    //         r = mid;
    //         low = mid + 1;
    //     }
    //     else
    //     {
    //         high = mid - 1;
    //     }
    // }
    int r = l + total - 1;

    cout << "! " << l << " " << r << endl;
}


int32_t main()
{
    fastio();
    // srand(time(NULL));

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve (tt);
    }

    return 0;
}