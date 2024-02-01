#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

const int mx = 123;
int arr[mx];

int main()
{
    optimize();

    int n;
    cin >> n;

    if (n == 1) cout << n << endl;

    else if ( n == 2 || n == 3) cout << "NO SOLUTION" << endl;

    else 
    {
        for (int i = 2; i <= n; i+=2) cout << i << ' ';
        for (int i = 1; i <= n; i+=2) cout << i << ' ';
    }

    return 0;
}