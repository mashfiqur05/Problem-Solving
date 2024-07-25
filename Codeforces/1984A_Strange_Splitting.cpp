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
        vector<int> v (n);
        for (int i = 0; i < n; i++) cin >> v[i];

        bool f = 0;
        int mn = INT_MAX;
        int mx = INT_MIN;
        int id1, id2, id3;
        for (int i = 0; i < n-1; i++)
        {
            if (v[i] != v[i+1] && !f) 
            {
                f = 1;
            }
            if (v[i] < mn)
            {
                mn = v[i];
                id1 = i;
            }
            if (v[i] > mx)
            {
                mx = v[i];
                id2 = i;
            }
        }
        bool f1 = 1;

        if (f == 0) cout << "NO" << endl;
        else 
        {
            cout << "YES" << endl;
            for (int i = 0; i < n; i++)
            {
                if (i != id1 && i != id2 && f1 == 1) {cout << 'R';f1 = 0;}
                else cout << 'B';
            }
            cout << endl;
        }
    }
    
    return 0;
}