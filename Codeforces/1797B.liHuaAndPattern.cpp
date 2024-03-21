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

const int mx = 1e3+123;
int arr[mx][mx];

int main()
{
    Bismillah();

    int testcases = 1;
    cin >> testcases;
    for (int i =1; i<= testcases; i++)
    {
        int n, k;
        cin >> n >> k;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++) cin >> arr[i][j];
        }

        int cnt = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j<=n; j++)
            {
                if (arr[i][j] != arr[n+1-i][n+1-j]) cnt++;
            }
        }

        cnt /= 2;
        
        if (cnt > k) cout << "NO" << endl;
        else 
        {
            k -= cnt;
            if (n & 1) cout << "YES" << endl;
            else if (k & 1) cout << "NO" <<  endl;
            else cout << "YES" << endl;
        }
    }
    
    return 0;
}