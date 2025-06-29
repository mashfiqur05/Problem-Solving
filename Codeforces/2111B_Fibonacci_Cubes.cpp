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


void testCases (int tt)
{
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> v(m);
    for (int i = 0; i < m; i++)
    {
        vector<int> cube(3);
        cin >> cube[0] >> cube[1] >> cube[2];
        sort (all (cube));
        v[i] = {cube[0], cube[1], cube[2]};
    }

    vector<int> f(n);
    f[0] = 1, f[1] = 2;
    for (int i = 2; i < n; i++) f[i] = f[i-1] + f[i-2];
    vector<int> need(3);
    need[0] = need[1] = f[n-1], need[2] = f[n-1] + f[n-2];
    sort (all (need));

    for (auto u : v)
    {
        int a = get<0>(u), b = get<1>(u), c = get<2>(u);

        if (a >= need[0] && b >= need[1] && c >= need[2]) cout << 1;
        else cout << 0;
    }
    cout << endl;
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