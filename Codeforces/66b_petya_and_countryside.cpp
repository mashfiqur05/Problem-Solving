#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define Bismillah() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);    ///  Fast IO.
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define mem(a,b) memset(a, b, sizeof(a) )
#define sq(a) ((a) * (a))
#define all(v) (v).begin(),(v).end()     /// ascending
#define rall(v) (v).rbegin(),(v).rend()  /// descending

//ll gcd ( ll a, ll b ) { return __gcd ( a, b ); }
//ll lcm ( ll a, ll b ) { return a * ( b / gcd ( a, b ) ); }

const ll MX = 1123;
int arr[MX];

int main()
{
    Bismillah();

    int testcases = 1;
    //cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        ll n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            
            int tmp = i;
            while (arr[tmp] >= arr[tmp+1] && tmp+1 <= n-1)
            {
                cnt++;
                tmp++;
                //cout << tmp << ' ' << tmp+1 << endl;
            }

            tmp = i;
            while (arr[tmp] >= arr[tmp-1] && tmp-1 >= 0)
            {
                cnt++;
                tmp--;
            }
            
            cnt++;
            ans = max (ans, cnt);
            //cout << mx << endl;
        }

        cout << ans;
    }
    
    return 0;
}
