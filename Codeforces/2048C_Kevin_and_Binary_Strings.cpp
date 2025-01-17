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


void solve (int testCase)
{
    string s;
    cin >> s;
    int l1 = 1, l2 = 1, r1 = s.size(), r2 = 1;
    int ind = 0, cnt1 = 0, cnt0 = 0;

    while (s[ind] == '1') 
    {
        cnt1++;
        ind++;
    }

    while (s[ind] == '0')
    {
        cnt0++;
        ind++;
    }

    int mn = min (cnt0, cnt1);
    l2 = (cnt1 - mn) + 1;
    r2 = r1 - mn;

    if (cnt0 == 0)
    {
        l2 = 1;
        r2 = 1;
    }

    cout << l1 << " " << r1 << " " << l2 << " " << r2 << endl;
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