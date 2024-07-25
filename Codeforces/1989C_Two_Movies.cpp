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

int dx[] = {0, 0, +1, -1, +1, +1, -1, -1};
int dy[] = {+1, -1, 0, 0, +1, -1, +1, -1};

//int gcd ( int a, int b ) { return __gcd ( a, b ); }
//int lcm ( int a, int b ) { return a * ( b / gcd ( a, b ) ); }

//const int N = 1e5+123;
//int arr[N];

int32_t main()
{
    Bismillah();

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        int n;
        cin >> n;
        vector<int> a(n), b (n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        

        int rat1 = 0, rat2 = 0, pos = 0, neg = 0;

        for (int i = 0; i < n; i++)
        {
            if (a[i] > b[i]) rat1 += a[i];
            else if (a[i] < b[i]) rat2 += b[i];
            else if (a[i] == 1 && b[i] == 1) pos++;
            else if (a[i] == -1 && b[i] == -1) neg++;
        }

        // cout << pos << " " <<neg << " " << rat1 << " " << rat2 << endl;
        while (pos--)
        {
            if (rat1 > rat2) rat2++;
            else rat1++;
        }

        while (neg--)
        {
            if (rat1 > rat2) rat1--;
            else rat2--;
        }

        cout << min (rat1, rat2) << endl;
    }
    
    return 0;
}