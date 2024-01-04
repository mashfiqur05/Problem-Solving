/// Given a number N. Print all even numbers between 1 and N inclusive in separate lines.
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
    
    if (n == 1) cout << "-1";
    for (int i = 2; i <= n; i+=2)
    {
        cout << i << endl;
    }
    

    return 0;
}