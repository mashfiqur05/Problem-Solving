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
#define MOD 10000007

ll lcm ( ll a, ll b ) { return a * ( b / __gcd ( a, b ) ); }
int n;

// bool isDivisibleBy11 (string s)
// {
//     ll sum_odd = 0, sum_even = 0;
//     for (int i = 0; i < s.size(); i++)
//     {
//         if (i & 1) sum_odd += (s[i] - '0');
//         else sum_even += (s[i] - '0');
//     }

//     if (abs (sum_even - sum_odd) % 11 == 0) return true;
//     else return false;
// }


int32_t main()
{
    fastio();
    // srand(time(NULL));

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        cin >> n;
        string s;
        
        if (n == 1 || n == 3) 
        {
            cout << -1 << endl;
            continue;
        }
        // for (int i = 0; i < n-1; i++) s += '3';
        
        if (n & 1)
        {
            for (int i = 0; i < n-5; i++)
            {
                s += '3';
            }
            s += "36366";
        }
        else
        {
            for (int i = 0; i < n-2; i++)
            {
                s += '3';
            }
            s += "66";
        }

        cout << s << endl;
    }

    return 0;
}