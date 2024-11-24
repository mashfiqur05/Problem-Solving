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

string decToBinary(ll n)
{

    string ret = "";
    for (int i = 61; i >= 0; i--) 
    {
        int k = n >> i;
        if (k & 1) ret += "1";
        else ret += "0";
    }

    return ret;
}

long long binaryToDecimal(const string& binaryStr) {
    long long decimalValue = 0;
    int length = binaryStr.length();

    for (int i = 0; i < length; i++) {
        if (binaryStr[i] == '1') {
            decimalValue += 1LL << (length - 1 - i); // 1 shifted by (position from the right)
        }
    }
    return decimalValue;
}

int32_t main()
{
    fastio();

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        ll x, y, z;
        cin >> x >> y >> z;

        string b = decToBinary (x), c = decToBinary (y), d = decToBinary (z);

        // dbg (b, c, d);        

        string ans = "";
        bool ok = 0;
        for (int i = 0; i < d.size(); i++)
        {
            ll bit_b = b[i] - '0';
            ll bit_c = c[i] - '0';
            ll bit_d = d[i] - '0';

            if ((bit_b && (!bit_c) && (!bit_d)) || ((!bit_b) && bit_c && bit_d))
            {
                ok = 1;
                break;
            }
            if (bit_b && bit_c)
            {
                if (bit_d) ans += "0";
                else ans += "1";
            }
            else
            {
                if (!bit_d) ans += "0";
                else ans += "1";
            }
            // dbg(ans);
        }

        if (ok)
        {
            cout << -1 << endl;
            continue;
        }
        // dbg(b, c, d, ans);

        cout << binaryToDecimal(ans) << endl;
    }

    return 0;
}