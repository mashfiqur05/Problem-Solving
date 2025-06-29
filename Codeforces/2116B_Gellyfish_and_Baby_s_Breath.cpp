///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///

#include <bits/stdc++.h>
using namespace std;

#define fastio()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define fraction()                \
    cout.unsetf(ios::floatfield); \
    cout.precision(10);           \
    cout.setf(ios::fixed, ios::floatfield);
#define file()                        \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

#define endl '\n'
#define ll long long
#define int long long
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(x) (int)x.size()
#define mem(a, b) memset(a, b, sizeof(a))
#define sq(a) ((a) * (a))
#define unq(x)                                        \
    {                                                 \
        x.erase(unique(x.begin(), x.end()), x.end()); \
    }

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const int MX = 2e5 + 123;
const ll infLL = 9000000000000000000;
const int MOD = 998244353;

//
//debug
template<typename F,typename S>ostream&operator<<(ostream&os,const pair<F,S>&p){return os<<"("<<p.first<<", "<<p.second<<")";}
template<typename T>ostream&operator<<(ostream&os,const vector<T>&v){os<<"{";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<*it;}return os<<"}";}
template<typename T>ostream&operator<<(ostream&os,const set<T>&v){os<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<",";os<<*it;}return os<<"]";}
template<typename T>ostream&operator<<(ostream&os,const multiset<T>&v) {os<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<*it;}return os<<"]";}
template<typename F,typename S>ostream&operator<<(ostream&os,const map<F,S>&v){os<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<it->first<<" = "<<it->second;}return os<<"]";}
#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)
void faltu(){cerr << endl;}
template<typename T>void faltu(T a[],int n){for(int i=0;i<n;++i)cerr<<a[i]<<' ';cerr<<endl;}
template<typename T,typename...hello>void faltu(T arg,const hello&...rest){cerr<<arg<<' ';faltu(rest...);}
//#else
//#define dbg(args...)


void testCases(int tt)
{
    int n;
    cin >> n;

    vector<int> p(n), q(n), indP(n), indQ(n);

    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        indP[p[i]] = i;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> q[i];
        indQ[q[i]] = i;
    }

    vector<int> pow2(n);
    pow2[0] = 1;
    for (int i = 1; i < n; i++)
    {
        pow2[i] = pow2[i - 1] * 2;
        pow2[i] %= MOD;
    }
    // dbg (pow2);

    vector<int> mxOfP(n), mxOfQ(n);
    mxOfP[0] = p[0];
    mxOfQ[0] = q[0];
    for (int i = 1; i < n; i++)
    {
        mxOfP[i] = max(mxOfP[i - 1], p[i]);
        mxOfQ[i] = max(mxOfQ[i - 1], q[i]);
    }

    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        int mx = max(mxOfP[i], mxOfQ[i]);
        int cur = 0;

        if (mxOfP[i] > mxOfQ[i])
        {
            int j = indP[mx];
            int k = i - j;
            if (k >= 0 && k < n) cur = q[k];
        }
        else if (mxOfQ[i] > mxOfP[i])
        {
            int k = indQ[mx];
            int j = i - k;
            if (j >= 0 && j < n) cur = p[j];
        }
        else
        {
            int j1 = indP[mx], k1 = i - j1;
            int val1, val2;
            if (k1 >= 0 && k1 < n) val1 = q[k1];
            else val1 = -1;

            int k2 = indQ[mx], j2 = i - k2;
            if (j2 >= 0 && j2 < n) val2 = p[j2];
            else val2 = -1;

            cur = max (val1, val2);
        }

        // cout << i << " " << mx << " " << cur << endl;

        ans[i] = (pow2[mx] + pow2[cur]) % MOD;
    }

    for (auto u : ans) cout << u << " "; cout << endl;
}

int32_t main()
{
    fastio();
    // srand(time(NULL));

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        testCases(tt);
    }

    return 0;
}