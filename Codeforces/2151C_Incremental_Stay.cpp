///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///

#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

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

/*
4 5 6 9 12 15 16 18 19 23
 1 2 3 4 5 6 7  8  9 10
 1 1 3 3  3  1  2  1  4 
 1 2 5 8  11 12 14 15 19
19 14 12 7 3
19 33 45 52 55

k = 1 => 19
k = 2 => 14 + (23 - 4) = 33
k = 3 => 12 + (33) = 

k = 3
enter- 4  5  6 12...
exit - 23 19 9 15...
*/
void solve()
{
    int n;
    cin >> n;

    vector<int> a(2 * n);

    for (int i = 0; i < 2 * n; i++)
    {
        cin >> a[i];
    }

    vector<int> gap(2 * n - 1);
    for (int i = 0; i < 2 * n - 1; i++)
    {
        gap[i] = a[i + 1] - a[i];
    }


    vector<int> evenPrefix(2 * n, 0);
    vector<int> oddPrefix(2 * n, 0);

    for (int i = 1; i < 2 * n; i++)
    {
        evenPrefix[i] = evenPrefix[i - 1];
        oddPrefix[i] = oddPrefix[i - 1];

        if (i % 2 == 0)
        {
            evenPrefix[i] += gap[i - 1];
        }
        else
        {
            oddPrefix[i] += gap[i - 1];
        }
    }

    dbg (oddPrefix, evenPrefix);
    vector<int> ans(n + 1, 0);
    ans[1] = oddPrefix[2 * n - 1];

    for (int k = 2; k <= n; k++)
    {
        int left = k, right = 2 * n - k;

        int sum;

        if (k % 2 == 0)
        {
            sum = evenPrefix[right] - evenPrefix[left - 1];
        }
        else
        {
            sum = oddPrefix[right] - oddPrefix[left - 1];
        }

        ans[k] = ans[k - 1] + 2LL * sum;
    }

    for (int k = 1; k <= n; k++)
    {
        cout << ans[k] << " ";
    }

    cout << '\n';
}

int32_t main()
{
    fastio();
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    // srand(time(NULL));

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve ();
    }

    return 0;
}