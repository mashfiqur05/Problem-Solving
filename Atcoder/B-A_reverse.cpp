/// ABC 233

#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

const int mx = 123;
int arr[mx];

int main()
{
    optimize();

    string s;
    int l, r;

    cin >> l >> r >> s;

    for (int i = l-1, j = r-1; i < j; i++, j--)
    {
        int temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }

    cout << s << endl;

    return 0;
}