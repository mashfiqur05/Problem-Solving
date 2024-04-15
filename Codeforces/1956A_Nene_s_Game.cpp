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

int main()
{
    Bismillah();

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        int k, q;
        cin >> k >> q;

        vector<int> vk(k, 0);
        vector<int> vq(q, 0);

        for (int i = 0; i < k; i++) cin >> vk[i];
        for (int i = 0; i < q; i++) cin >> vq[i];

        for (int i = 0; i < q; i++)
        {
            if (vk[0] <= vq[i]) 
            {
                cout << vk[0] - 1 << ' ';
            }
            else cout << vq[i] << ' ';
        }

        cout << endl;
    }
    
    return 0;
}