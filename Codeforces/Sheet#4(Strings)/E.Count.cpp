#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

int main()
{
    optimize();

    string s;
    cin >> s;

    long long sum = 0;
    int i = 0;

    while (s[i] != 0)
    {
        sum += (s[i] - '0');
        i++;
    }

    cout << sum << endl;
   
    return 0;
}