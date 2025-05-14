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

bool isOk (int pre[][32], int mid, int l, int k)
{   
    int val = 0;
    for (int i = 0; i < 32; i++)
    {
        if (pre[mid][i] - pre[l-1][i] >= mid - l + 1) 
        {
            val += (pow (2, i));
        }
    }

    if (val >= k) return true;
    return false;
}

void testCases (int tt)
{
    int n;
    cin >> n;
    vector<int> v(n+1);
    for (int i = 1; i <= n; i++) cin >> v[i];

    int pre[n+1][32] = {0};
    for (int i = 1; i <= n; i++)
    {
        // cout << endl << v[i] << " ";
        for (int j = 0; j < 32; j++)
        {
            int bit = v[i] & (1 << j);  /// Kth bit on or not
            if (bit) pre[i][j] = pre[i-1][j] + 1;
            else pre[i][j] = pre[i-1][j]; 
            // cout << pre[i][j] << " "; 
        }
    }

    int q;
    cin >> q;
    vector<int> ans(q);
    for (int i = 0; i < q; i++)
    {
        // cout << "Q " << i+1 << endl;
        int l, k;
        cin >> l >> k;

        if (v[l] < k)
        {
            ans[i] = -1;
            continue;
        }

        // vector<int> need;
        // for (int i = 0; i < 32; i++)
        // {
        //     int bit = k & (1 << i);
        //     if (bit) need.push_back (i);
        // }

        // dbg (need);
        int low = l, high = n, res = l;
        while (low <= high)
        {
            int mid = (low + high) / 2;

            // cout << low << " " << high << " " << mid << endl;
            if (isOk (pre, mid, l, k)) 
            {
                res = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }

        ans[i] = res;
    }

    for (int i = 0; i < q; i++) cout << ans[i] << " "; 
    cout << endl;
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