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
int arr[mx];

int main()
{
    optimize();

    int t = 1;
    //cin >> t;
    while (t--) 
    {
        string s1, s2;
        cin >> s1 >> s2;

        for (int i = 0; i < s1.length(); i++)
        {
            if ((s1[i] == '1' && s2[i] == '0') || (s1[i] == '0' && s2[i] == '1')) cout << '1';
            else cout << '0';
        }

        cout << endl;
    }
    
    return 0;
}