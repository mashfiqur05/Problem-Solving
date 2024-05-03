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

//const ll MX = 123;
//int arr[MX];
bool mark[11111];
int c[55], d[55];

int main()
{
    Bismillah();

    int testcases = 1;
    //cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        int p, q, l, r;
        cin >> p >> q >> l >> r;

        for (int i = 1; i <= p; i++)
        {
            int a, b; 
            cin >> a >> b;
            for (int j = a; j <= b; j++) mark[j] = 1;
        }
        for (int i = 0; i < q; i++)
        {
            cin >> c[i] >> d[i];
        }

        int ans = 0;

        for (int i = l; i <= r; i++)
        {
            for (int j = 0; j < q; j++)
            {
                for (int k = c[j]; k <= d[j]; k++)
                {
                    if (mark[k+i])
                    {
                        ans++;
                        j = q;
                        k = d[j]+1;
                    }
                }
            }
        }

        cout << ans << endl;
    }   
    
    return 0;
}