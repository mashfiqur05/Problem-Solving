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
const int MX = 1e6+123;
const ll infLL = 9000000000000000000;
const int MOD = 1e9+7;

// proper divisor 
int divSum[MX];

void precompute()
{
    for (int i = 1; i < MX; i++)
    {
        for (int j = 2*i; j < MX; j+=i)
        {
            divSum[j] += i;
        }
    }
}

void solve ()
{
    int n; cin >> n;
    int sn = divSum[n];

    // cout << sn << endl;
    if (sn > n) cout << "abundant" << endl;
    else if (sn < n) cout << "deficient" << endl;
    else cout << "perfect" << endl;
}



int32_t main()
{
    fastio();
    precompute();
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