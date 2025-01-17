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
// Lower bound: Min index where I can insert x still v is sorted.
int lb(const vector<int> &arr, int x)
{
    int low = 0, high = arr.size();
    while (low < high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] < x) low = mid + 1;
        else high = mid;
    }

    return low;
}

// Upper bound: Max index where I can insert x still v is sorted.
int ub(const vector<int> &arr, int x)
{
    int low = 0, high = arr.size();
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= x) low = mid + 1;
        else high = mid;    
    }

    return low;
}
void solve (int testCase)
{
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    ll sum = accumulate (all(a), 0LL);

    vector<int> b = a;
    sort (all (b));
    // dbg (sum, b);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int after_minus = sum - a[i];
        int st, end;
        if (after_minus < y) st = 0;
        else st = after_minus - y;

        if (after_minus < x) end = 0;
        else end = after_minus - x;

        int idst = lb(b, st);
        int idend = ub(b, end);

        // dbg (st, end, idst, idend);
        ans += idend - idst;
        if (a[i] >= st && a[i] <= end) ans--;
        // dbg (ans);
    }

    cout << ans/2 << endl;
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