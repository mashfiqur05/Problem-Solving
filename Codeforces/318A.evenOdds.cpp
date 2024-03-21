#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define pb push_back
#define mem(a,b) memset(a, b, sizeof(a) )
#define sq(a) ((a) * (a))
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

const int mx = 123;
int arr[mx];

int main()
{
    optimize();

    ll t = 1;
    //cin >> t;
    while (t--) 
    {
        ll n, k;
        cin >> n >> k;

        ll oddRange, ans;
        if (n % 2 == 0) oddRange = n / 2;
        else oddRange = n / 2 + 1;

        if (k <= oddRange) ans = 2 * k - 1;
        else ans = (k - oddRange) * 2;

        cout << ans << endl;
    }
    
    return 0;
}