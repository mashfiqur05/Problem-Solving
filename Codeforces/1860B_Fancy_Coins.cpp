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
    int m, k, a1, ak;
    cin >> m >> k >> a1 >> ak;
    
    int burrleWithAk = m / k;
    if (burrleWithAk <= ak)
    {
        ak -= burrleWithAk;
        m -= (burrleWithAk * k);
    }
    else
    {
        m -= (ak * k);
        ak = 0;
    }

    // cout << m << " ";
    if (m <= a1) 
    {
        cout << 0 << endl;
    }
    else 
    {
        int needMore = m - a1;
        int canDoWithAk = (needMore + k - 1) / k;
        // int extra = m - a1 - canDoWithAk * k;?
        if (canDoWithAk * k <= m && m - canDoWithAk * k <= a1) cout << canDoWithAk << endl;
        else 
        {
            canDoWithAk--;
            cout << canDoWithAk + (m - canDoWithAk * k - a1) << endl;
        }

        // cout << needMore << " " << canDoWithAk << " " << extra << endl;
        // cout << canDoWithAk + extra << endl;
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
        testCases (tt);
    }

    return 0;
}