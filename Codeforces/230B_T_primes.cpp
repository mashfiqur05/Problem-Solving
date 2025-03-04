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
const int MX = 1e6+12;
const ll infLL = 9000000000000000000;
const int MOD = 1e9+7;

set<long long> tprimes;

bool isPrime(int n)
{
    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

void testCases(int tt)
{
    ll n;
    cin >> n;

    if (tprimes.find (n) == tprimes.end()) cout << "NO" << endl;
    else cout << "YES" << endl;
}

int32_t main()
{
    fastio();
    // srand(time(NULL));
    tprimes.insert(4);
    for (int i = 3; i <= 1000000; i += 2)
    {
        if (isPrime(i))
        {
            tprimes.insert((ll)i * i);
        }
    }
    
    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        testCases (tt);
    }

    return 0;
}