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

vector<int> findDiv (int n)
{
    vector<int> div;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0) 
        {
            div.push_back (i);
            if (i != n/i) div.push_back (n/i);
        }
    }

    return div;
}

void solve (int CaseNo)
{
    int n; cin >> n;

    vector<int> divN = findDiv (n);
    sort (rall (divN));

    for (int i = 0; i < divN.size(); i++)
    {
        // cout << divN[i] << " ";
        vector<int> div = findDiv(divN[i]);
        bool f = 1;
        for (auto u : div)
        {
            if (sq ((int)sqrt (u)) == u && u != 1)
            {   
                // cout << sqrt(u) << endl;
                f = 0;
                break;
            }
        }

        if (f)
        {
            cout << divN[i] << endl;
            return;
        }
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
        solve (tt);
    }

    return 0;
}