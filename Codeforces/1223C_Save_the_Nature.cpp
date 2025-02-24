///   ***   ---   |||     In the name of ALLAH    |||   ---   ***   ///

#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()

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


ll lcm(ll a, ll b) { return a * (b / __gcd(a, b)); }
ll n;
vector<ll>v;
ll x, y, a, b, k;
bool check(ll mid) {
    vector<ll>contri(mid, 0);
    for(ll i = 1; i <= mid; i++) {
        if(i % a == 0 and i % b == 0) {
            contri[i - 1] = (x + y);
        } else if(i % a == 0) {
            contri[i - 1] = x;
        } else if(i % b == 0) {
            contri[i - 1] = y;
        }
    }
    sort(rall(contri));
    sort(rall(v));
 
    ll sum = 0;
    for(int i = 0; i < mid; i++) {
        sum += (v[i] * 1ll * contri[i]) / 100;
        if(sum >= k) return true;
    }
    return false;
}
void solve() {
    cin >> n;
    v.resize(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    cin >> x >> a >> y >> b;
    cin >> k;
    ll low = 1, high = n, ans = -1;
    while(low <= high) {
        ll mid = (low + high) / 2;
        if(check(mid)) {
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
     }
 
     cout << ans << endl;
}

int32_t main() {
    fastio();
    int testcases;
    cin >> testcases;
    while (testcases--) {
        solve();
    }
    return 0;
}
