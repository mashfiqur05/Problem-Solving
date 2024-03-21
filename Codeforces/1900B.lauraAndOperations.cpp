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

const int mx = 123;
int arr[mx];

int main()
{
    Bismillah();

    int testcases = 1;
    cin >> testcases;
    while (testcases--) 
    {
        int a, b, c;
        cin >> a >> b >> c;

        cout << (b + c + 1) % 2 << ' ' << (a + c + 1) % 2 << ' ' << (a + b + 1) % 2 << endl;
    }
    
    return 0;
}