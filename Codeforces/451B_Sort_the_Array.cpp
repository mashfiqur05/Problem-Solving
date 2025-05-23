///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///

#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define endl '\n'
#define ll long long
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a) )
#define sq(a) ((a) * (a))

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const int MX = 2e5+123;
const ll infLL = 9000000000000000000;
const int MOD = 1e9+7;


void testCases (int tt)
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    vector<int> a = v;
    sort (all (a));

    int l = 0, r = 0, f= -1;

    for (int i = 0; i < n; i++)
    {
        if (v[i] != a[i] && f == -1)
        {
            f = 1;
            l = i;
        }
        else if (f == 1 && v[i] != a[i])
        {
            r = i;
        }
    }

    if (l > r)
    {
        cout << "no" << endl;
        return;
    }

    // cout << l << " " << r << endl;
    for (int i = l, j = r; i <= r; i++, j--)
    {
        if (v[i] != a[j]) 
        {
            f = 0;
            break;
        }
    }

    if (f == 0)
    {
        cout << "no" << endl;
    }
    else 
    {
        cout << "yes" << endl;
        cout << l + 1 << " " << r + 1 << endl;
    }
}


int32_t main()
{
    fastio();
    // srand(time(NULL));

    int testcases = 1;
    // cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        testCases (tt);
    }

    return 0;
}