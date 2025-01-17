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
#define MOD 1000000007

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

ll lcm ( ll a, ll b ) { return a * ( b / __gcd ( a, b ) ); }
int budget, n;
int cost[105], funs[105];
pair<int, int> dp[105][505];


pair<int, int> solve (int pos, int cur_cost)
{
    if (pos == n) return {0, 0};

    if (dp[pos][cur_cost].first != -1) return dp[pos][cur_cost];

    pair<int, int> val2 = {0, 0};
    pair<int, int> val1 = solve (pos + 1, cur_cost);

    if (cur_cost + cost[pos] <= budget)
    {
        val2 = solve (pos + 1, cur_cost + cost[pos]);
        val2.first += funs[pos];
        val2.second += cost[pos];
    }

    auto val = max (val1, val2);
    if (val1.first == val2.first)
    {
        if (val1.second < val2.second) val = val1;
        else val = val2;
    }

    // dbg (pos, cur_cost, val);
    return dp[pos][cur_cost] = val;
} 



int32_t main()
{
    fastio();

    int testcases = 1;
    // cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        while (1)
        {
            for (int i = 0; i < 105; i++)
            {
                for (int j = 0; j < 505; j++)
                {
                    dp[i][j].first = -1;
                }
            }
            mem (cost, 0);
            mem (funs, 0);
            cin >> budget >> n;
            if (budget == 0 && n == 0) break;

            for (int i = 0; i < n; i++) cin >> cost[i] >> funs[i];

            auto ans = solve (0, 0);

            cout << ans.second << " " << ans.first << endl;

        }
    }

    return 0;
}