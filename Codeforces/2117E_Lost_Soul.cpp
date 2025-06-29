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

void testCases (int tt)
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    int ans = -1;
    for (int i = n-1; i >= 0; i--)
    {
        if (a[i] == b[i]) 
        {
            ans = i;
            break; 
        }
    }

    // cout << ans << endl;

    set<int> zigzag, zig1, zig2;
    int prev1 = a[n-1], prev2 = b[n-1];

    for (int i = n-1; i >=0; i--)
    {
        if (i % 2 == 0)
        {
            if (zig1.find(a[i]) != zig1.end())
            {
                ans = max (ans, i);
                break;
            }
            if (zig2.find(b[i]) != zig2.end())
            {
                ans = max (ans, i);
                break;
            }
            zig2.insert (a[i]);
            zig1.insert (b[i]);
        }
        else 
        {
            if (zig1.find(b[i]) != zig1.end())
            {
                ans = max (ans, i);
                break;
            }
            if (zig2.find(a[i]) != zig2.end())
            {
                ans = max (ans, i);
                break;
            }
            zig2.insert (b[i]);
            zig1.insert (a[i]);
        }
        // dbg (a[i], b[i]);
        // dbg (zig1, zig2);

    }

    // cout << ans << endl;

    for (int i = n-2; i >= 0; i--)
    {
        int val1 = a[i], val2 = b[i];
        auto it1 = zigzag.find (val1);
        auto it2 = zigzag.find (val2);

        if (it1 != zigzag.end() || it2 != zigzag.end())
        {
            ans = max (ans, i);
            break;
        }
        zigzag.insert (prev1);
        zigzag.insert (prev2);

        prev1 = a[i], prev2 = b[i];
    }

    cout << ans + 1 << endl;
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