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
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    int need = 0, extra = 0, kom = 0, ind = n;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > b[i]) extra += (a[i] - b[i]);
        else if (a[i] < b[i]){need += (b[i] - a[i]); kom++; ind = i;}
    }

    if (ind == n) 
    {
        cout << "YES" << endl;
        return;
    }
    else 
    {
        for (int i = 0; i < n; i++)
        {
            if (i == ind) continue;
            if ((a[i] - b[i]) < (b[ind] - a[ind]))
            {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
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