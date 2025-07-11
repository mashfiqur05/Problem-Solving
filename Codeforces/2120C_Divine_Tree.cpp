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


void solve (int CaseNo)
{
    int n, m;
    cin >> n >> m;
    int mx = (n * (n + 1)) / 2;
    if (m < n || m > mx)
    {
        cout << -1 << endl;
        return;
    }

    vector<int> val (n, 0);
    for (int i = 0; i < n; i++) val[i] = i + 1;
    int rmv = (n*(n+1)/2 - m);

    for (int i = n-1; i >= 0; i--)
    {
        if (rmv <= val[i]-1)
        {
            val[i] -= rmv;
            rmv = 0;
        }
        else 
        {
            rmv -= (val[i] - 1);
            val[i] = 1;
        }

        if (rmv == 0) break;
    }

    int root = *max_element (all (val));

    cout << root << endl;
    for (int i = 0; i < n; i++)
    {
        if (i+1 == root) continue;
        if (val[i] == i + 1)
        {
            cout << val[i] << " " << root << endl;
        }
        else cout << i+1 << " " << val[i] << endl;
    }
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