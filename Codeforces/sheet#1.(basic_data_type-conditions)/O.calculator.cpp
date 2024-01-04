/// Given a mathematical expression. The expression will be one of the following expressions: A+B, A−B, A∗B and A/B. print the ans.

#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

int main()
{
    optimize();

    int a, b;
    char s;
    cin >> a >> s >> b;
    
    if (s == '+') cout << a + b << endl;
    else if (s == '-') cout << a - b << endl;
    else if (s == '*') cout << a * b << endl;
    else cout << a / b << endl;

    return 0;
}