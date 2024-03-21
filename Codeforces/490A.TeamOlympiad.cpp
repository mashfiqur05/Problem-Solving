#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define Bismillah() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);    ///  Fast IO.
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define pb push_back
#define mem(a,b) memset(a, b, sizeof(a) )
#define sq(a) ((a) * (a))
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

//ll gcd ( ll a, ll b ) { return __gcd ( a, b ); }
//ll lcm ( ll a, ll b ) { return a * ( b / gcd ( a, b ) ); }

//const int mx = 123;
//int arr[mx];

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

        for (int i = 0; i < n; i++) cin >> v[i];

        vector<int> cnt1;
        vector<int> cnt2;
        vector<int> cnt3;

        for (int i = 0; i < n; i++)
        {
            if (v[i] == 1) cnt1.pb (i+1);
            else if (v[i] == 2) cnt2.pb (i+1);
            else cnt3.pb (i+1);
        }

        int sz1 = cnt1.size();
        int sz2 = cnt2.size();
        int sz3 = cnt3.size();

        int mn = sz1;
        mn = min (mn, sz2);
        mn = min (mn, sz3);


        if ((cnt1.size() == 0) || (cnt2.size() == 0) || (cnt3.size() == 0)) cout << 0;
        else 
        {
            cout << mn << endl;
            for (int i = 0; i < mn; i++) cout << cnt1[i] << ' ' << cnt2[i] << ' ' << cnt3[i] << endl;
        }
    }
    
    return 0;
}