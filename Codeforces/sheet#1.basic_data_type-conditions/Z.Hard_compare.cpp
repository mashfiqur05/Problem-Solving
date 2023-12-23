/// Given 4 numbers A,B,Cand D. If A^B> C^Dprint "YES" otherwise, print "NO".

#include<bits/stdc++.h>
#include<cmath>
using namespace std;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

int main()
{
    optimize();

    long long a, b, c, d;
    cin >> a >> b >> c >> d;

    if(b * log(a) > d * log(c)) cout << "YES";      /// log(a^b) = b*log(a); 
    else cout << "NO";

    return 0;
}