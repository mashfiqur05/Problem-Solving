#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
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
    optimize();

    int t = 1;
    //cin >> t;
    while (t--) 
    {
        int l1, l2, l3;
        cin >> l1 >> l2 >> l3;

        int a = sqrt (l1 * l2 / l3);
        int b = sqrt (l3 * l1 / l2);
        int c = sqrt (l2 * l3 / l1 );

        int ans = 4 * (a + b + c);

        cout << ans << endl;
    }
    
    return 0;
}