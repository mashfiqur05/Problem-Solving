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
const int MX = 1500;
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
int n, k;
int dp[250][20][MX];


bool sieve[MX];
vector<int> primes;

void primeGenerator (int limit)
{
    mem (sieve, true);
    
    for (int i = 2; i * i <= limit; i++)
    {
        if (sieve[i] == true)
        {
            for (int j = i * i; j <= limit; j += i) sieve[j] = false;
        }
    }

    primes.push_back (2);
    for (int i = 3; i <= limit; i+=2)
    {
        if (sieve[i]) primes.push_back (i);
    }
}


int fun (int pos, int cnt, int sum)
{
    if (pos == primes.size() || sum >= n || cnt == k)
    {
        if (sum == n && cnt == k) return 1;
        else return 0;
    }

    if (dp[pos][cnt][sum] != -1) return dp[pos][cnt][sum];

    int val1 = fun (pos+1, cnt, sum);
    int val2 = fun (pos+1, cnt+1, sum+primes[pos]);

    return dp[pos][cnt][sum] = val1 + val2;
}


int32_t main()
{
    fastio();

    primeGenerator (1500);
    
    int testcases = 1;
    // cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        while (1)
        {
            mem (dp, -1);
            cin >> n >> k;
            if (n == 0 && k == 0) break;

            cout << fun (0, 0, 0) << endl;
        }
    }

    return 0;
}