#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

const int mx = 100123;
int a[mx];

int main()
{
    optimize();

    int n;
    long long sum = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {   
        cin >> a[i];
        sum += a[i];
    }
    cout << abs(sum) << endl;

    return 0;
}