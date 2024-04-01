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

const ll MX = 123;
int arr[MX];

int main()
{
    Bismillah();

    int testcases = 1;
    //cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        ll n, a;
        cin >> n >> a;

        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }

        int ans = 0;

        if (n == 1) 
        {
            if (arr[1] == 1) ans = 1;
            else ans = 0;
        }
        else if (a <= n/2)
        {
            int tmp = 2 * a;
            for (int i = tmp; i <= n; i++)
            {
                if(arr[i] == 1) ans++;
            }

            for (int i = a-1, j = a+1; i >= 1, j <= tmp; i--, j++)
            {
                if (arr[i] == 1 && arr[j] == 1) ans += 2;
            }

            if (arr[a] == 1) ans++;
        }
        else
        {
            int tmp = a - (n - a);

            for (int i = 1; i < tmp; i++)
            {
                if (arr[i] == 1) ans++;
            }

            for (int i = a-1, j = a+1; i >= tmp, j <= n; i--, j++)
            {
                if (arr[i] == 1 && arr[j] == 1) ans += 2;
            }

            if (arr[a] == 1) ans++;
        }


        cout << ans;
    }
    
    return 0;
}