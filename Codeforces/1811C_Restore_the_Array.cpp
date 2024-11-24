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
#define MOD 1000000007

ll lcm ( ll a, ll b ) { return a * ( b / __gcd ( a, b ) ); }


int32_t main()
{
    fastio();

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        int n;
        cin >> n;
        vector<int> a(n), b(n-1);
        for (int i = 0; i < n-1; i++) cin >> b[i];
        bool f = 0;
        int id = 0;
        for (int i = 0; i < n-1; i++)
        {
            if (b[i] < b[i+1] && !f)
            {
                a[id++] = b[i];
                a[id++] = 0;
                f = 1;
            }
            else if (f && b[i] > b[i+1] && (i+1) != n-1)
            {   
                a[id++] = b[i+1];
            }
            else 
            {
                a[id++] = b[i];
            }
        }

        if (!f) a[n-1] = 0;
        for (auto u : a) cout << u << " ";
        cout << endl;
    }

    return 0;
}