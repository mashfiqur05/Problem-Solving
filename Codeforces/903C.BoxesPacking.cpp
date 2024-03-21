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

const int mx = 5e3+123;
int arr[mx];


void solve()
{
    int n;
    cin >> n;

    map<int, int> cnt;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        cnt[arr[i]]++;
    }

    int ans = 0;
    
    for (int i = 0; i < n; i++)
    {
        ans = max (ans, cnt[arr[i]]);
    }
    cout << ans << endl;
}

int main()
{
    optimize();

    int t = 1;
    //cin >> t;
    while (t--) 
    {
        solve();
    }
    
    return 0;
}
