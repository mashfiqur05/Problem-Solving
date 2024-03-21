#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define Bismillah() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);    ///  Fast IO.
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define pb push_back
#define mem(a,b) memset(a, b, sizeof(a) )
#define sq(a) ((a) * (a))
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

const int mx = 2e5+123;
ll arr[mx];
ll sum[mx];

int main()
{
    Bismillah();

    int testcases = 1;
    //cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        int n, x;

        cin >> n >> x;
        
        for (int i = 1; i <= n; i++) cin >> arr[i];
        
        for (int i = 1; i <= n; i++)
        {
            sum[i] = sum[i-1] + arr[i];
        }

        map<ll, int> cnt;
        ll ans = 0;
        
        cnt[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            ll needSum = sum[i] - x;
            ans += cnt[needSum];
            cnt[sum[i]]++;
        }
        
        cout << ans << endl;
    }
    
    return 0;
}