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

ll check[10];

int main()
{
    Bismillah();

    int testcases = 1;
    //cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        int n, k;
        cin >> n >> k;

        int cnt = n;

        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;

            mem (check, 0);

            for (int j = 0; j < s.size(); j++)
            {
                check[s[j] - '0'] = 1;
            }

            for (int z = 0; z <= k; z++)
            {
                if (check[z] == 0)
                {
                    cnt--;
                    break;
                }
            }

        }
    
        cout << cnt << endl;       
    }
    
    return 0;
}
