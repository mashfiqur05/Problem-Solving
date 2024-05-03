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
    //cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        int n;
        cin >> n;

        vector<int> v(n);
        stack<int> pos, neg, zero;

        for (int i = 0; i < n; i++) 
        {
            cin >> v[i];

            if (v[i] < 0) neg.push (v[i]);
            else if (v[i] > 0) pos.push (v[i]);
            else zero.push (v[i]);
        }


        cout << 1 << ' ' << neg.top() << endl;
        neg.pop();

        if (neg.size() % 2 == 1)
        {
            int x = neg.top();
            neg.pop();
            zero.push (x);
        }


        cout << pos.size() + neg.size() << ' ';
        while (!neg.empty())
        {
            cout << neg.top() << ' ';
            neg.pop();
        }
        while (!pos.empty())
        {
            cout << pos.top() << ' ';
            pos.pop();
        }
        cout << endl;


        cout << zero.size() << ' ';
        while (!zero.empty())
        {
            cout << zero.top() << ' ';
            zero.pop();
        }
        cout << endl;

    }
    
    return 0;
}