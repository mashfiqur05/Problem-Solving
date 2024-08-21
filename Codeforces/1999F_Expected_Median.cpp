//In the name of ALLAH

#include<bits/stdc++.h>
using namespace std;


#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define M 1000000007
#define MOD1 998244353
#define INF 1e18
#define endl "\n"
#define int long long
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define mem(a,b) memset(a, b, sizeof(a) )
#define sq(a) ((a) * (a))
#define all(v) (v).begin(),(v).end()     /// ascending
#define rall(v) (v).rbegin(),(v).rend()  /// descending


typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

/*
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
*/
// ll lcm ( ll a, ll b ) { return a * ( b / __gcd ( a, b ) ); }

const int N = 2e5 + 1;
vector<int> fact(N + 1, 1);

int binaryexponential(int no, int power)
{
    int ans = 1;
    while (power)
    {
        if (power & 1)
        {
            ans = (ans * no) % M;
        }
        no = (no * no) % M;
        power >>= 1;
    }
    return ans;
}

int ncr(int n, int r)
{
    if (r < 0 || n < 0 || n < r)
        return 0;
    int value = (fact[r] * fact[n - r]) % M;
    int ans = (fact[n] * binaryexponential(value, M - 2)) % M;
    return ans;
}

int32_t main()
{
    fastio();
    int t;
    cin >> t;
    for (int i = 1; i <= N; ++i)
    {
        fact[i] = (fact[i - 1] * i) % M;
    }
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n];
        vector<int> pre(n + 1, 0);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            pre[i + 1] = pre[i] + a[i];
        }
        int half_length = (k / 2);
        int ans = 0;
        int count_zeros = n - pre[n];
        int count_ones = pre[n];

        for (int i = 0; i < n; ++i)
        {
            if (a[i] == 0)
            {
                continue;
            }
            else
            {
                int pre_no = count_zeros + pre[i];
                int post_ones = pre[n] - pre[i + 1];
                // cout << (i + 1) << " " << pre_no << " " << post_ones << endl;
                int value = (ncr(pre_no, half_length) * ncr(post_ones, half_length)) % M;
                ans = (ans + value) % M;
            }
            // cout << ans << endl; 
        }
        cout << (ans) << endl; 
    }

    return 0;
}
