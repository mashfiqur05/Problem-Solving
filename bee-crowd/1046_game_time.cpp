#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

int main()
{
    optimize();

    int a, b;
    cin >> a >> b;
    
    int gamehour = 24 - a + b;

    if (gamehour <= 24) cout << "O JOGO DUROU " << gamehour << " HORA(S)" << endl;
    else  cout << "O JOGO DUROU " << (gamehour - 24) << " HORA(S)" << endl;

    return 0;
}