#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define pb push_back
#define mem(a,b) memset(a, b, sizeof(a) )
#define sq(a) ((a) * (a))
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

const int mx = 123;
string name[mx], ip[mx];


void solve()
{
    int n, m;
    cin >> n >> m;

    map<string, string> ipName;

    while (n--)
    {
        string name, ip;
        cin >> name >> ip;

        ipName[ip] = name;
    }

    while (m--)
    {
        string ip, comand;
        cin >> comand >> ip;

        ip.pop_back();

        cout << comand << ' ' << ip << "; #" << ipName[ip] << endl;
    }
}

int main()
{
    optimize();

    int t = 1;
    //cin >> t;
    while (t--) 
    {
        solve();
    }
    
    return 0;
}