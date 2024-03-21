#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl "\n"
#define Bismillah() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);    ///  Fast IO.
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define pb push_back
#define mem(a,b) memset(a, b, sizeof(a) )
#define sq(a) ((a) * (a))
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

const int mx = 123;
int l[mx], r[mx];

int main()
{
    Bismillah();

    int testcases = 1;
    cin >> testcases;
    while (testcases--) 
    {
        int n, k;
        cin >> n >> k;
    
        int mx = 0, mn = 55;

        while (n--)
        {
            int l, r;
            cin >> l >> r;

            if (l <= k and k <= r)
            {
                mx = max (mx, l);
                mn = min (mn, r);
            }
        }

        if (mx == mn) cout << "YES" << endl;
        else cout << "NO" << endl;

    }
    
    return 0;
}