#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl "\n"
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

const int mx = 123;
int arr[mx];

int main()
{
    optimize();

    string s;
    cin >> s;
    int ans = 0;

    if (isupper(s[0])) ans = 1;
    else 
    {
        cout << "No" << endl;
        return 0;
    }
    
    for (int i = 1; i < s.length(); i++)
    {
        if (islower(s[i])) ans = 1;
        else 
        {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    return 0;
}