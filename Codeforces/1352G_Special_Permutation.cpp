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
    int n; 
    cin >> n;
    if (n >= 1 && n <= 3) {cout << -1 << endl; return;}
    else if (n == 4)
    {
        cout << "3 1 4 2" << endl;
        return;
    }
    else if (n == 5)
    {
        cout << "3 1 4 2 5" << endl;
        return;
    }

    int i = 0, val = n;
    for (i = 0; i < n && val > 0; i++)
    {
        cout << val << " ";
        val -= 2;
    }

    if (n % 2 == 0)
    {
        if (n < 7)
        {
            cout << "5 1 3 ";
        }
        else
            cout << "5 1 3 7 ";

        val = 9;
        while (val <= n)
        {
            cout << val << " ";
            val += 2;
        }
    }
    else 
    {
        if (n < 8)
        {
            cout << "4 2 6 ";
        }
        else
            cout << "4 2 6 8 ";

        val = 10;
        while (val <= n)
        {
            cout << val << " ";
            val += 2;
        }
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