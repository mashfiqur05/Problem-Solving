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

string decToBinary(int n)
{
    // Size of an integer is assumed to be 32 bits
    string res = "";
    for (int i = 31; i >= 0; i--) {
        int k = n >> i;
        if (k & 1) res += '1';
        else res += '0';
    }

    return res;
}



void solve (int testCase)
{
    int l, r;
    cin >> l >> r;

    string x = decToBinary (l), y = decToBinary (r);

    string p = "", q = "";
    bool f = 0;

    for (int i = 0; i < x.size(); i++)
    {
        if (x[i] == y[i] && !f) 
        {
            p += x[i];
            q += x[i];
        }
        else if (f)
        {
            p += '0';
            q += '1';
        }
        else 
        {
            f = 1;
            p += '1';
            q += '0';
        }
    }

    int a = stoi (p, 0, 2);
    int b = stoi (q, 0, 2), c;

    for (int i = l; i <= r; i++)
    {
        if (i != a && i != b)
        {
            c = i;
            break;
        }
    }

    cout << a << ' ' << b << " " << c << endl;
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