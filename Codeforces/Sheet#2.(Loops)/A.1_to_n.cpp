/// Given a number N. Print numbers from 1 to N in separate lines.

#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

int main()
{
    optimize();

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cout << i << endl;
    }
    
    return 0;
}