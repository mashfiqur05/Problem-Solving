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

const int mx = 1e5+123;
int arr[mx];


int main()
{
    Bismillah();

    int testcases = 1;
    //cin >> testcases;
    while (testcases--) 
    {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) cin >> arr[i];

        for (int i = 1; i <= n; i++)
        {
            arr[i] += arr[i-1];
        }

        int query;
        cin >> query;
        ll sum = 0;

        while (query--)
        {
            int i, j;
            cin >> i >> j;

            if (i > j) swap (i, j);

            if (i == 0) sum = arr[j];
            else sum = arr[j] - arr[i-1];
            
            cout << sum << endl;
        }
    }
    
    return 0;
}