#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define Bismillah() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);    ///  Fast IO.
#define fraction() cout.unsetf(ios::floatfield); cout.precision(2); cout.setf(ios::fixed,ios::floatfield);
#define pb push_back
#define mem(a,b) memset(a, b, sizeof(a) )
#define sq(a) ((a) * (a))
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

const int mx = 123;
int arr[mx];

int main()
{
    Bismillah();

    int testcases = 1;
    cin >> testcases;
    for (int tt = 1; tt <= testcases; tt++)
    {
        double r1, r2, b, requiredRunRate;
        cin >> r1 >> r2 >> b;

        fraction();
        double currentRunRate = (r2 / ((300 - b) / 6));
        
        if (r1 < r2) requiredRunRate = 0.00;
        else requiredRunRate = ((r1 - r2 + 1) / b) * 6;

        cout << currentRunRate << ' ' << requiredRunRate << endl;
    }
    
    return 0;
}