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


int32_t main()
{
    fastio();

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        ll sum = 0;
        for (int i = 0; i < n; i++) {cin >> v[i]; sum += v[i];}
        sort (all (v));

        int mid = n / 2;

        int lagbe = (2 * v[mid]);
        lagbe = lagbe * n;
        int ans = -1;

        if (n > 2) ans = lagbe - sum + 1;
        if (n > 2) 
        {
            if (ans > 0) cout << ans << endl;
            else cout << 0 << endl;
        }  
        else cout << -1 << endl;
    }

    return 0;
}