#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

int main()
{
    optimize();

    char a, b, c, d;
    cin >> a >> b >> c >> d;

    int s1, s2, t1, t2;

    if(int(a) > int(b))
    {
        s1 = int(a);
        s2 = int(b);
    }
    else
    {
        s1 = int(b);
        s2 = int(a);
    }
    if(int(c) > int(d))
    {
        t1 = int(c);
        t2 = int(d);
    }
    else
    {
        t1 = int(d);
        t2 = int(c);
    }

    if((s1 - s2) == (t1 - t2)) cout << "Yes";
    else cout << "No";

    return 0;
}