///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///

#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

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

/*
101110
red - 1, 1, 1 
blue- 0, 1, 0 
0, 1, 0
1, 1, 1

10011110101011
r - 1011111
b - 0110001
0010001
1111111
*/

void solve ()
{
    int n, k; cin >> n >> k;
    string s; cin >> s;
    string r ="", b ="";
    for (int i = 0; i < 2*n; i++)
    {
        if (i%2 == 0) r+= s[i];
        else b += s[i];
    }

    // cout << r << endl << b << endl;
    int rp = 0, bp = 0;
    for (int i = 0; i < n; i++)
    {
        if (r[i] == '1')
        {
            if (b[i] == '0') rp++;
            else bp++;
        }
        if (b[i] == '1')
        {
            if (i+1 < n && r[i+1] == '0') bp++;
            else if (i+1 == n && r[0] == '0') bp++;
            else rp++;
        }
    }

    cout << rp << " " << bp << endl;
}


int32_t main()
{
    fastio();
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //#endif
    // srand(time(NULL));

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve ();
    }

    return 0;
}