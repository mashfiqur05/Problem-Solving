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
const int N = 1e6+123;
const ll infLL = 9000000000000000000;
const int MOD = 1e9+7;

long long fact[N], invfact[N];

long long power(long long a,long long b){
    long long res=1;
    while(b){
        if(b&1) res=res*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return res;
}

void precompute(){
    fact[0]=1;
    for(int i=1;i<N;i++)
        fact[i]=fact[i-1]*i%MOD;

    invfact[N-1]=power(fact[N-1],MOD-2);

    for(int i=N-2;i>=0;i--)
        invfact[i]=invfact[i+1]*(i+1)%MOD;
}

long long nCr(int n,int r){
    if(r>n) return 0;
    return fact[n]*invfact[r]%MOD*invfact[n-r]%MOD;
}


void solve (int CaseNo)
{
    int n, a, b, d; 
    while (cin >> n >> a >> b >> d)
    {
        int ans =  power(nCr(b,d), a);
        ans %= MOD;
        ans *= nCr(n, a);
        ans %= MOD;

        cout << ans << endl;
    }
}


int32_t main()
{
    fastio();
    // srand(time(NULL));

    precompute();
    int testcases = 1;
    // cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        solve (tt);
    }

    return 0;
}