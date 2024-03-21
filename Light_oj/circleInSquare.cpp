#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

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
double PI =  2 * acos (0.0);

int main()
{
    Bismillah();

    int testcases = 1;
    cin >> testcases;
    for (int i = 1; i <= testcases; i++) 
    {
        double radius;
        cin >> radius;

        fraction();
        double ans = (2 * radius) * (2 * radius) - (PI * radius * radius);

        cout << "Case " << i << ": " << ans << endl;

    }
    
    return 0;
}