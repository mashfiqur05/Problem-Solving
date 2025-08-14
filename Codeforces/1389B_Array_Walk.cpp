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


void solve (int CaseNo)
{
    int n, k, z;
    cin >> n >> k >> z;
    vector<int> v(n), prefix_sum(n+1, 0), prefix_max(n+1, 0);
    for (int i = 0; i < n; i++) cin >> v[i];

    for (int i = 1; i <= n; i++)
    {
        prefix_sum[i] = prefix_sum[i - 1] + v[i - 1];
    }
    prefix_max[1] = v[0];
    for (int i = 2; i < n; i++)
    {
        prefix_max[i] = max (prefix_max[i-1], max (v[i-1] + v[i-2], v[i-1] + v[i]));
    }
    if (n >= 2) prefix_max[n] = max (prefix_max[n-1], v[n-1] + v[n-2]);

    // dbg (prefix_sum);
    int ans = 0;
    for (int i = 0; i <= z; i++)
    {
        for (int j = 1; j <= k - 2*i +1; j++)
        {
            if (j == k - 2*i + 1 && i == 0) continue;
            // case 1 -> 4 6 8 2 8 2 8 2
            int sum1 = prefix_sum[j+1];
            int repeat1 = prefix_max[j+1];
            repeat1 *= i;
            int total = sum1 + repeat1;
            //case 2 -> 4 6 8 2 8 2 8
            if (j == k - 2*i + 1)
            {
                total -= v[j];
            }

            ans = max (ans, total);
        }
        // cout << i << "-> " <<  ans << endl;
    }
    
    cout << ans << endl;
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