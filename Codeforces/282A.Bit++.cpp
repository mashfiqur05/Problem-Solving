/// implementation /// 800

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

    int t, cnt = 0;
    cin >> t;

    while (t--)
    {
        char a, b, c;
        cin >> a >> b >> c;

        if (a == '+' || c == '+') cnt++;
        else cnt--;
    }   

    cout << cnt << endl;

    return 0;
}