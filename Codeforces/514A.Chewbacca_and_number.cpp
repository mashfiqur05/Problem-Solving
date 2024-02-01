/// greedy  /// implementation // *1200

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

    string n;
    cin >> n;

    char tmp = n[0];

    for (int i = 0; i < n.length(); i++)
    {
        int t = n[i] - '0';
        int rev = 9 - t;
        
        rev = min (rev, t);

        n[i] = rev + '0';
    }

    if (n[0] == '0') n[0] = tmp;

    for (int i = 0; i < n.length(); i++)
    {
        cout << n[i];
    }
    cout << endl;

    return 0;
}