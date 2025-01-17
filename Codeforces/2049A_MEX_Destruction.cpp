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

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const int MX = 2e5+123;
const ll infLL = 9000000000000000000;
const int MOD = 1e9+7;


void solve (int testCase)
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    bool isZeroInMiddle = 0, isZero = 0;
    int cnt = 0, other = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] != 0 && isZeroInMiddle == 1) other = 2;
        else if (v[i] != 0) other = 1;
        else if (i != 0 && i != n-1 && v[i] == 0 && other == 1) 
        {
            isZeroInMiddle = 1;
            isZero = 1;
        } 
        else if (v[i] == 0) isZero = 1;

        if (v[i] == 0) cnt++;
    }
    // cout << isZero  << " " << cnt << " " << isZeroInMiddle << " " << other << endl;

    if (isZero == 0) cout << 1 << endl;
    else if (cnt == n) cout << 0 << endl;
    else if (other != 2 && (v[0] == 0 || v[n-1] == 0)) cout << 1 << endl;
    else cout << 2 << endl;
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