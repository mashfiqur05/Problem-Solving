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


void testCases (int tt)
{
    int n;
    cin >> n;
 
    int x[n+2];
 
    for(int i = 1; i <= n; i++){
        cin >> x[i];
    }
 
    int prefix_gcd[n+2];
    prefix_gcd[0] = 0;
 
    for(int i = 1; i <= n; i++){
        prefix_gcd[i] = __gcd(prefix_gcd[i-1], x[i]);
    }
 
    int suffix_gcd[n+2];
    suffix_gcd[n+1] = 0;
 
    for(int i = n; i >= 1; i--){
        suffix_gcd[i] = __gcd(suffix_gcd[i+1], x[i]);
    }
 
    int mx = 0;
 
    for(int i = 1; i <= n; i++){
        mx = max(mx, __gcd(prefix_gcd[i-1], suffix_gcd[i+1]));
    }
 
    cout << mx << endl;
}


int32_t main()
{
    fastio();
    // srand(time(NULL));

    int testcases = 1;
    // cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        testCases (tt);
    }

    return 0;
}