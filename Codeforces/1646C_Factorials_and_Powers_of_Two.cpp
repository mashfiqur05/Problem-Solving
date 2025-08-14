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
const int MX = 1e12;
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


vector<int> factorial;
set<pair<int, int>> sums;

void generateSums(int idx, ll currentSum, int element) 
{
    if (currentSum > 0 && currentSum <= MX) {
        if (__builtin_popcountll(currentSum) != 1) sums.insert({currentSum, element}); 
        else sums.insert ({currentSum, 1});
    }
    if (idx == factorial.size() || currentSum > MX) return;

    generateSums(idx + 1, currentSum + factorial[idx], element + 1);

    generateSums(idx + 1, currentSum, element);
}

void solve (int CaseNo)
{
    int n; cin >> n;

    int ans = infLL, res = infLL;
    if (__builtin_popcountll(n) == 1)
    {   
        cout << 1 << endl;
        return;
    }

    // dbg (sums);
    for (auto u : sums)
    {
        if (n < u.first) break;
        int bit = __builtin_popcountll(n - u.first);
        
        // cout << "bit > " << bit << "--> " << u.first << " " << u.second << " = " << n-u.first << endl;

        ans = min (ans, bit + u.second);
    }

    cout << ans << endl;
}


int32_t main()
{
    fastio();
    // srand(time(NULL));
    
    int fact = 1, ind = 2;
    factorial.push_back (1);
    while (fact <= MX)
    {
        fact *= ind;
        ind++;
        factorial.push_back (fact);
    }

    generateSums(0, 0, 0);

    for (auto u : factorial) sums.insert ({u, 1});
    for (int i = 0; i <= 40; i++)
    {
        sums.insert ({pow (2, i), 1});
    }

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve (tt);
    }

    return 0;
}