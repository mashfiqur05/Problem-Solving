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

const int mx = 2e5+123;
int arr[mx];

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);

    for (int i = 0; i < n; i++)  cin >> v[i];

    sort (all(v));
    int cnt = 1, ans = 1;

    for (int i = 1; i < n; i++)
    {
        if (v[i] - v[i - 1] > k) cnt = 1;
        else cnt++;

        ans = max (ans, cnt);
    }

    cout << n - ans << endl;
}

int main()
{
    optimize();

    int t = 1;
    
    cin >> t;
    while (t--) 
    {
        solve();
    }
    
    return 0;
}