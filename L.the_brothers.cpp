#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

int main()
{
    optimize();

    string f1, f2, s1, s2;
    cin >> f1 >> s1 >> f2 >> s2;

    if(s1 == s2) cout << "ARE Brothers" << endl;
    else cout << "NOT" << endl;

    return 0;
}